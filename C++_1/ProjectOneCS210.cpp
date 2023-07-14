// Ahmet Mujanovic

#include <iostream>
#include <string>
#include <Windows.h>    // Including header to use sleep function in order to tick clock every second
#include <conio.h>      // Including header to use function to get user input without stopping program
#include "Time.h"       // Including header that contains declarations for accessors and mutators

using namespace std;    // Using this namespace for brevity but would generally not reccommend doing so

// Using these methods to validate if values are within acceptable
bool isValidHour(int n) {
    if (n >= 0 && n <= 23) {
        return true;
    }
    else {
        throw invalid_argument("Hours exceed 24 hr range");
        return false;
    }
}

bool isValidMinute(int n) {
    if (n >= 0 && n <= 59) {
        return true;
    }
    else {
        throw invalid_argument("Minutes exceed range");
        return false;
    }
}

bool isValidSecond(int n) {
    if (n >= 0 && n <= 59) {
        return true;
    }
    else {
        throw invalid_argument("Seconds exceed range");
        return false;
    }
}

// Establishing menu choices
const char* choices[] = { "Add One Hour", "Add One Minute", "Add One Second", "Exit Program" };

/**
 * Formats a number as 2 digits, with a leading 0 if needed
 *
 * @param n number to format, assumed between 0 and 59, inclusive
 * @return two digit string representation of number
 */
string twoDigitString(unsigned int n) {

    string formattedTwoDigit;

    if (n < 0 || n > 59) {
        throw invalid_argument("received value outside of range");
    }
    else {
        if (n >= 0 && n <= 9) {
            formattedTwoDigit = "0" + to_string(n);
            return formattedTwoDigit;
        }
        else {
            formattedTwoDigit = to_string(n);
            return formattedTwoDigit;
        }
    }
}

/**
 * Returns a string of length n, each character a c.
 * For example, nCharString(5, '*') should return "*****". 
 * Using overloaded constructor for string class to recieve parameters for size and char type.
 *
 * @param n string length, >=0
 * @return string of n c's
 */
string nCharString(size_t n, char c) {
    string formattedCharString(n, c);

    return formattedCharString;
}

/**
 * Formats the time in military format

 *
 * @param h, hours 0 to 23
 * @param m, minutes 0 to 59
 * @param s, seconds 0 to 59
 *
 * @return hh:mm:ss
 */
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    string time24Hour;
    if (isValidHour(h) && isValidMinute(m) && isValidSecond(s)) {
        time24Hour = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
        return time24Hour;
    }
    else {
        throw invalid_argument("received value outside of range");
    }
}

/**
 * Formats the time in am/pm format
 *
 * @param h, hours 0 to 23
 * @param m, minutes 0 to 59
 * @param s, seconds 0 to 59
 *
 * @return hh:mm:ss A M or hh:mm:ss P M where hh is between 01 and 12, inclusive
 */
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    string time12Hour;
    if (isValidHour(h) && isValidMinute(m) && isValidSecond(s)) {
        if (h >= 12 && h < 24) {        // Using 24 hours total but anything past 12 will be converted to the PM equivalent
            if (h == 12) {
                h = 24;
            }
            time12Hour = twoDigitString(h - 12) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " P M";
            return time12Hour;
        }
        else if (h >= 0 && h < 12) {
            if (h == 0) {
                h = 12;
            }
            time12Hour = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " A M";
            return time12Hour;
        }
    }
    else {
        throw invalid_argument("received value outside of range");
    }
}


/**
 * Prints menu and spaces evenly based on input parameters.
 *
 * @param *strings[], nonempty array of choices
 * @param width, width of each line, will be comfortably bigger than the longest string
 *
 */
void printMenu(const char* strings[], unsigned int numStrings, unsigned char width) {
    
    cout << nCharString(26, '*') << endl;

    for (int i = 0; i < numStrings; i++)
    {
        cout << "* " << i + 1 << " - " << strings[i] << nCharString((width - 7) - (strlen(strings[i])), ' ') << "*" << endl;
        //if (i == numStrings) {
            //cout << "*  " << i + 1 << " - " << strings[i] << nCharString((numStrings - 7) - strlen(strings[i]), ' ') << "*";
        //}
    }

    cout << nCharString(26, '*') << endl;
}


/**
 * Display the clocks
 *
 * @param h, hours 0 to 23
 * @param m, minutes 0 to 59
 * @param s, seconds 0 to 59
 */
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {

    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
    cout << nCharString(1, '*') << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << nCharString(3, ' ');
    cout << nCharString(1, '*') << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << endl;
    cout << endl;
    cout << nCharString(1, '*') << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << nCharString(1, '*') << nCharString(3, ' ');
    cout << nCharString(1, '*') << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << nCharString(1, '*') << endl;
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
}

/**
 * Adds one hour
 */
void addOneHour() {
     
    if (getHours() >= 0 && getHours() <= 22) {
        setHours(getHours() + 1);
    }
    else if (getHours() == 23) {
        setHours(0);
    }
}

/**
 * Adds one minute
 */
void addOneMinute() {

    if (getMinutes() >= 0 && getMinutes() <= 58) {
        setMinutes(getMinutes() + 1);
    }
    else if (getMinutes() == 59) {  // Rolls hour over if minutes exceed 59
        setMinutes(0);
        addOneHour();
    }
}

/**
 * Adds one second
 */
void addOneSecond() {

    if (getSeconds() >= 0 && getSeconds() <= 58) {
        setSeconds(getSeconds() + 1);
    }
    else if (getSeconds() == 59) { // Rolls minutes over if seconds exceed 59
        setSeconds(0);
        addOneMinute();
    }
}

/**
 * Gets menu choice 1 through maxChoice, inclusive
 *
 * @param maxChoice, maximum choice index, a number between 2 and 9, inclusive
 * @return the first legal choice input, could be 1 through maxChoice, inclusive
 */
unsigned int getMenuChoice(unsigned int maxChoice, char userKeyPress) {

    int userChoice = userKeyPress - '0';    // Converting character into integer. Ex: '1' into 1

    for (size_t i = 0; i <= maxChoice; i++)     // Looping through range of choices to see if input is one of them to return
    {
        if (userChoice == i) {
            return userChoice;
        }
    }
}

/**
 * Repeats getting the user's choice and taking the appropriate action until the user chooses 4 for exit
 */
void mainMenu() {

    bool exit = false;
    while (!exit) {
        printMenu(choices, 4, 26);
        displayClocks(getHours(), getMinutes(), getSeconds());
        addOneSecond();     // Pause execution for 1 second then add a second continously while waiting for input
        Sleep(1000);        
        if (_kbhit() != 0) {        // Enter this branch is user presses a key
            char keyPress = int(_getch());      // Catches key press and converts to integer to input as an argument for menu selection
            switch (getMenuChoice(4, keyPress)) {
                case 1:
                    addOneHour();
                    continue;
                case 2:
                    addOneMinute();
                    continue;
                case 3:
                    addOneSecond();
                    continue;
                case 4:
                    exit = true;
                    break;
            }
        }
    }
}

void main() {
    // Setting inital time with mutators from time.cpp
    setHours(13);
    setMinutes(55);
    setSeconds(55);

    // Displaying menu
    mainMenu();
}
