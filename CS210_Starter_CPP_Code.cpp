#include <Python.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("CS210_Starter_PY_Code");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"CS210_Starter_PY_Code");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"CS210_Starter_PY_Code");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

/*
* Reads file created from Python and stores each line into a vector
* @param None
*
* @returns vector<string> of item name and quantity on each line
*/
vector<string> parseFile() {

	fstream file;
	string fileTempVar;
	vector<string> itemList;

	// Opening file with check for success, reading all lines, and storing into a vector.
	file.open("frequency.dat", ios::in);
	if (!file.is_open()) {
		cout << "Could not open file \"frequency.dat\"" << endl;
	}
	else if (file.is_open()) {
		while (getline(file, fileTempVar)) {
			itemList.push_back(fileTempVar);		// Using temporary variable to store input from file
		}
	}
	file.close();

	return itemList;
}

/*
* Prints a particular character a desired number of times
* @param int: Number of times to print a character
* @param char: The character desired to be printed
*
* @returns Formatted string
*/
string nCharString(size_t n, char c) {
	string formattedCharString(n, c);
	return formattedCharString;
}

/*
* Takes combined list of item names and their quantities, strips to only name, and stores name into vector.
* @param vector<string>: Combined name and quantity vector
*
* @returns vector<string> with just item names for each index
*/
vector<string> findNames(vector<string> itemList) {
	vector<string> itemNames;
	for (string line : itemList) {
		itemNames.push_back(line.substr(0, line.find("-")));
	}
	return itemNames;
}

/*
* Takes combined list of item names and their quantities, strips to only quantities, and stores quantities into vector.
* @param vector<string>: Combined name and quantity vector
*
* @returns vector<string> with just item quantities for each index
*/
vector<string> findQuantity(vector<string> itemList) {
	vector<string> itemQuantity;
	for (string line : itemList) {
		itemQuantity.push_back(line.substr(line.find("-") + 1));
	}
	return itemQuantity;
}

/*
Description:
	Displays menu for user selection. Validates user input for intergers and calls appropriate function.
*/
void displayMenu() {
	while (true) {
		cout << "1: Print all items bought in a day and their quantity" << endl;
		cout << "2: Print specific item and its quantity" << endl;
		cout << "3: Print a graph of all items bought in a day and their quantity" << endl;
		cout << "4: Exit" << endl;
		cout << "Enter your selection as a number 1, 2, 3, or 4: ";

		vector<string> itemList;
		string userItemChoice;
		int userCaseChoice;
		bool itemExists = false;

		cin >> userCaseChoice;
		switch (userCaseChoice)
		{
		//Calls function to display items and their quantities
		case 1:
			CallProcedure("displayItems");
			continue;
		//Calls function to display specific item. Cotinues to loop if an invalid selection is made
		case 2:
			int returnedValue;
			while (itemExists == false) {
				cout << "What item would you like to check? (Enter 'q' to exit): ";
				cin >> userItemChoice;
				if (userItemChoice == "q") {
					cout << endl;
					cout << "Returning to main menu..." << endl;
					cout << endl;
					break;
				}

				returnedValue = callIntFunc("displayChoice", userItemChoice);
				if (returnedValue == 1) {
					itemExists == true;
					break;
				}
				else if (returnedValue == 0) {
					cin.clear();
					cin.ignore(999, '\n');
					continue;
				}
			}
			continue;
		//Calls function create "frequency.dat" file. Parses that file and displays a histogram of items with a nested for loop.
		case 3:
			CallProcedure("createFile");
			itemList = parseFile();
			cout << endl;
			for (int i = 0; i < findNames(itemList).size(); i++) {
				for (int j = 0; j < findQuantity(itemList).size(); j++) {
					int tempVal = stoi(findQuantity(itemList).at(i));
					cout << setw(13) << left << findNames(itemList).at(i) << "| " << right << nCharString(tempVal, '=') << endl;
					break;
				}
			}
			cout << endl;
			continue;
		case 4:
			cin.clear();
			cin.ignore(999, '\n');
			cout << endl;
			cout << "Exiting Program.....";
			cout << endl;
			break;
		default:
			cin.clear();
			cin.ignore(999, '\n');
			cout << endl;
			cout << "Please enter a valid choice (1, 2, 3, or 4)" << endl;
			cout << endl;
			continue;
		}
		break;
	}
}

void main()
{
	displayMenu();
}