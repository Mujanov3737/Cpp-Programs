#include <iostream>
#include "Time.h"   // Importing the header file that contains the declarations

// Defining Accessors and Mutators for hours, minutes, and seconds
int getHours() {
    return hours;
}
void setHours(int h) {
    hours = h;
}

int getMinutes() {
    return minutes;
}
void setMinutes(int m) {
    minutes = m;
}

int getSeconds() {
    return seconds;
}
void setSeconds(int s) {
    seconds = s;
}