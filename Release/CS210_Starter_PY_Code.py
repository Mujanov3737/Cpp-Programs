import re
import string

def printsomething():
    print("Hello from python!")

def PrintMe(v):
    print("You sent me: " + v)
    return 100;

def SquareValue(v):
    return v * v

# Reads the file and stores names and quantities into a dictionary. Returns the dictionary created.
def buildDict():
    itemsDict = {}
    itemsFile = open("CS210_Project_Three_Input_File.txt", "r")
    for item in itemsFile:
        item = item.strip()
        if (item not in itemsDict.keys()):
            itemsDict[item] = 1
        elif (item in itemsDict.keys()):
            itemsDict[item] = itemsDict[item] + 1
    itemsFile.close()

    return itemsDict

#Calls function to build dictionary from original file, iterates over the dict, and displays items & quantity.
def displayItems():
    itemsDict = buildDict()
    print('')
    for item, quantity in itemsDict.items():
        print(f'{item}: {quantity}')
    print('')

#Displays quantity of item chosen by user. If item doesn't exist, returns a 0 which causes C++ to ask for input again.
def displayChoice(userChoice):
    itemsDict = buildDict()
    userChoice = userChoice.strip()
    userChoice = userChoice.lower()

    for item, quantity in itemsDict.items():
        if (item.lower() == userChoice):
            print('')
            print(f'For the item [{item}], there were [{quantity}] purchased.')
            print('')
            return 1

    print('')
    print('Sorry, that item was not found in inventory')
    print('')
    return 0;

#Calls function to build dictionary from original file. Writes that dictionary to new "frequency.dat" file.
def createFile():
    itemsDict = buildDict()
    dictFile = open("frequency.dat", "x")
    for item, quantity in itemsDict.items():
        dictFile.write(f'{item}-{quantity}\n')
    dictFile.close()