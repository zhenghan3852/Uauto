#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define LED_NUM_OUT "/sys/class/leds/upboard:green:/brightness"
#define LED_CAP_OUT "/sys/class/leds/upboard:red:/brightness"
#define LED_INS_OUT "/sys/class/leds/upboard:yellow:/brightness"

int LED_Change();
int BrightAll();
int DarkAll();
