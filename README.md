# C++ Programs
This repository contains 3 different console C++ programs that were written early on as an exploration of the language's capabilities. Note, these projects generally do not leverage much of Modern C++, like smart pointers.

## C++_1 Clock Application
This application presents a 12 and 24 hour clock and refreshes every second. The user has the option to press the selected key and add a second, minute, or hour to the time to update it. The clocks will roll over properly. Note, this application does not use multiple threads to both refresh the clock and handle user input, but a sleep() system call to wait 1000ms before updating. This causes a few problems, one being it is dependant on the operating system being windows and another that it may feel delayed or sluggish if the user selects an option at certain times.

![cpp1](https://github.com/Mujanov3737/Cpp-Programs/assets/75598761/2a27b81a-e93a-453a-b69a-81d6b8df4b93)

## C++_2 Banking Interest Calculator
The second application take user inputs for investment amount, monthly deposit, annual interest, and years in order to calculate balance and interest. These interest values are then nicely formatted within the console and displayed for each year the user entered

![cpp2](https://github.com/Mujanov3737/Cpp-Programs/assets/75598761/1f955aff-5ec7-4b08-b007-306f91a113b5)

![cpp2_2](https://github.com/Mujanov3737/Cpp-Programs/assets/75598761/648a3896-812a-49c0-b6d8-f9b07dcac460)

## C++_3 Purchase History
The final application take in a text file of produce that was purchased, parses it to find the occurences of each product, then provides a menu of options for the user to view this information. These options include printing all the items and their quantity, printing a specific item, or generating a console based graph of this data. The interesting this about this application is that it makes calls to scripts created with the Python programming language in order to carry out some additional functions. While this increases the complexity and overhead of the program, the ultimate takeaway is that some languages have a large ecosystem of powerful tools or frameworks that can be leveraged to simplify the development process of other applications.

![cpp3](https://github.com/Mujanov3737/Cpp-Programs/assets/75598761/36ba9be2-b3c4-4bdf-966a-dd061b583a18)

![cpp3_1](https://github.com/Mujanov3737/Cpp-Programs/assets/75598761/309669ba-03ea-4c5b-bb58-0040b2e7cf5c)

![cpp3_2](https://github.com/Mujanov3737/Cpp-Programs/assets/75598761/fc859a40-488e-4d3e-899e-bbe88fb46849)
