# C++ Programs
This repository contains 3 different console C++ programs that were written early on as an exploration of the language's capabilities. Note, these projects generally do not leverage much of Modern C++, like smart pointers.
## C++_1 Clock Application
This application presents a 12 and 24 hour clock and refreshes every second. The user has the option to press the selected key and add a second, minute, or hour to the time to update it. The clocks will roll over properly. Note, this application does not use multiple threads to both refresh the clock and handle user input, but a sleep() system call to wait 1000ms before updating. This causes a few problems, one being it is dependant on the operating system being windows and another that it may feel delayed or sluggish if the user selects an option at certain times.

![cpp1](https://github.com/Mujanov3737/Cpp-Programs/assets/75598761/8f6abc41-ca1c-4393-afa6-284772a79d87)
## C++_2 Banking Interest Calculator
The second application take user inputs for investment amount, monthly deposit, annual interest, and years in order to calculate balance and interest. These interest values are then nicely formatted within the console and displayed for each year the user entered
![cpp2](https://github.com/Mujanov3737/Cpp-Programs/assets/75598761/c7d9712e-00b4-4d2a-9ab3-bd2b7e7c30f8)
![cpp2_2](https://github.com/Mujanov3737/Cpp-Programs/assets/75598761/d70b0eba-2c9d-45be-a275-5406e66dec93)

##
