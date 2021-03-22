#include "LED.h"

int LED_Change()
{
	int fd, fd1, fd2;
	int i = 0;
	int result;
	char Bright[1], Cright[1], Dright[1];
	fd = open(LED_NUM_OUT, O_RDWR);
	fd1 = open(LED_CAP_OUT, O_RDWR);
	fd2 = open(LED_INS_OUT, O_RDWR);
	if(fd < 0)
	{
		printf("Fail to open LED file in %s.\n", LED_NUM_OUT);
		return -1;
	}
	
	while(i < 1)
	{

		write(fd, "0", 1);
		write(fd1, "0", 1);
		write(fd2, "0", 1);
		sleep(1);
		
		write(fd, "1", 1);
		sleep(1);
		write(fd1,"1", 1);
		sleep(1);
		write(fd2,"1", 1);
		sleep(1);
		i++;
	}
		write(fd, "1", 1);
		write(fd1, "0", 1);
		write(fd2, "0", 1);
	return 0;
}

int BrightAll()
{
	int fd, fd1, fd2;
	int i = 0;
	int result;
	char Bright[1], Cright[1], Dright[1];
	fd = open(LED_NUM_OUT, O_RDWR);
	fd1 = open(LED_CAP_OUT, O_RDWR);
	fd2 = open(LED_INS_OUT, O_RDWR);

	if(fd < 0 || fd1 < 0 || fd2 < 0)
	{
		printf("Fail to open LED file in %s.\n", LED_NUM_OUT);
		return -1;
	}

	write(fd, "1", 1);
	write(fd1, "1", 1);
	write(fd2, "1", 1);
	
	return 0;
}

int DarkAll()
{
	int fd, fd1, fd2;
	int i = 0;
	int result;
	char Bright[1], Cright[1], Dright[1];
	fd = open(LED_NUM_OUT, O_RDWR);
	fd1 = open(LED_CAP_OUT, O_RDWR);
	fd2 = open(LED_INS_OUT, O_RDWR);

	if(fd < 0 || fd1 < 0 || fd2 < 0)
	{
		printf("Fail to open LED file in %s.\n", LED_NUM_OUT);
		return -1;
	}

	write(fd, "0", 1);
	write(fd1, "0", 1);
	write(fd2, "0", 1);
	
	return 0;
}
