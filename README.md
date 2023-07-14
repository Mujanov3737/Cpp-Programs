# C++ Programs
This repository contains 3 different console C++ programs that were written early on as an exploration of the language's capabilities. Note, these projects generally do not leverage much of Modern C++, like smart pointers.
----------------------------------
## C++_1 Clock Application
This application presents a 12 and 24 hour clock and refreshes every second. The user has the option to press the selected key and add a second, minute, or hour to the time to update it. The clocks will roll over properly. Note, this application does not use multiple threads to both refresh the clock and handle user input, but a sleep() system call to wait 1000ms before updating. This causes a few problems, one being it is dependant on the operating system being windows and another that it may feel delayed or sluggish if the user selects an option at certain times.
----------------------------------
![cpp1](https://github.com/Mujanov3737/Cpp-Programs/assets/75598761/8f6abc41-ca1c-4393-afa6-284772a79d87)
----------------------------------
## C++_2 Banking Interest Calculator
The second application take user inputs for investment amount, monthly deposit, annual interest, and years in order to calculate balance and interest. These interest values are then nicely formatted within the console and displayed for each year the user entered
----------------------------------
![cpp2](https://github.com/Mujanov3737/Cpp-Programs/assets/75598761/c7d9712e-00b4-4d2a-9ab3-bd2b7e7c30f8)
----------------------------------
![cpp2_2](https://github.com/Mujanov3737/Cpp-Programs/assets/75598761/d70b0eba-2c9d-45be-a275-5406e66dec93)

## C++_3 Purchase History
The final application take in a text file of produce that was purchased, parses it to find the occurences of each product, then provides a menu of options for the user to view this information. These options include printing all the items and their quantity, printing a specific item, or generating a console based graph of this data. The interesting this about this application is that it makes calls to scripts created with the Python programming language in order to carry out some additional functions. While this increases the complexity and overhead of the program, the ultimate takeaway is that some languages have a large ecosystem of powerful tools or frameworks that can be leveraged to simplify the development process of other applications.
----------------------------------
![cpp3](https://github.com/Mujanov3737/Cpp-Programs/assets/75598761/4bda1f42-bf38-468d-adf5-762f93cdd175)
----------------------------------
![cpp3_1](https://github.com/Mujanov3737/Cpp-Programs/assets/75598761/dc1054d8-e1b8-4ac4-982a-da44260a0306)
----------------------------------
![cpp3_2](https://github.com/Mujanov3737/Cpp-Programs/assets/75598761/35b5b2ed-9120-47a5-aa92-9d7ccf022f95)
