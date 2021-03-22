#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <scsi/scsi.h>
#include <scsi/sg.h>
#include <sys/ioctl.h>
#include "LED.h"
#include "Copy.h"

#define msleep(n) usleep(n*1000)

int scsi_get_serial(int fd, void *buf, size_t buf_len) {
    // we shall retrieve page 0x80 as per http://en.wikipedia.org/wiki/SCSI_Inquiry_Command
    unsigned char inq_cmd[] = {INQUIRY, 1, 0x80, 0, buf_len, 0};
    unsigned char sense[32];
    struct sg_io_hdr io_hdr;
            int result;

    memset(&io_hdr, 0, sizeof (io_hdr));
    io_hdr.interface_id = 'S';
    io_hdr.cmdp = inq_cmd;
    io_hdr.cmd_len = sizeof (inq_cmd);
    io_hdr.dxferp = buf;
    io_hdr.dxfer_len = buf_len;
    io_hdr.dxfer_direction = SG_DXFER_FROM_DEV;
    io_hdr.sbp = sense;
    io_hdr.mx_sb_len = sizeof (sense);
    io_hdr.timeout = 5000;

    result = ioctl(fd, SG_IO, &io_hdr);
    if (result < 0)
        return result;

    if ((io_hdr.info & SG_INFO_OK_MASK) != SG_INFO_OK)
        return 1;

    return 0;
}

int main(int argc, char** argv) {
    char *dev = "/dev/sda";
    char scsi_serial[255];
    int led_status = 0;
    int rc;
    int fd = -1;

    DarkAll();
    while(fd < 0)
    {
        fd = open(dev, O_RDONLY | O_NONBLOCK);
        if(led_status == 0){
            BrightAll();
	    led_status = 1;
        }
	else{
            DarkAll();
	    led_status = 0;
        }
	msleep(500);
    }

    memset(scsi_serial, 0, sizeof (scsi_serial));
    rc = scsi_get_serial(fd, scsi_serial, 255);
    // scsi_serial[3] is the length of the serial number
    // scsi_serial[4] is serial number (raw, NOT null terminated)
    if (rc < 0) {
        printf("FAIL, rc=%d, errno=%d\n", rc, errno);
    } else
    if (rc == 1) {
        printf("FAIL, rc=%d, drive doesn't report serial number\n", rc);
    } else {
        if (!scsi_serial[3]) {
            printf("Failed to retrieve serial for %s\n", dev);
            return -1;
        }
        printf("Serial Number: %.*s\n", (size_t) scsi_serial[3], (char *) & scsi_serial[4]);
    }
    close(fd);
    Copy();
    LED_Change();

    return (EXIT_SUCCESS);
}
