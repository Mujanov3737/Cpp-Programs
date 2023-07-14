#ifndef _TIME_H_
#define _TIME_H_

// Declaring Accessors and Mutators for hours, minutes, and seconds
static int hours;
static int minutes;
static int seconds;

// Declaring variables to use for the clock digits
int getHours();
void setHours(int h);

int getMinutes();
void setMinutes(int m);

int getSeconds();
void setSeconds(int s);

#endif