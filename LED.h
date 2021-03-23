#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define LED_GREEN "/sys/class/leds/upboard:green:/brightness"
#define LED_RED "/sys/class/leds/upboard:red:/brightness"
#define LED_YELLOW "/sys/class/leds/upboard:yellow:/brightness"

int LED_Change();
int BrightAll();
int DarkAll();
#To DO: the head file should be replaced
