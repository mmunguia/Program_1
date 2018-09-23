// *********************************************************************************************************************
// Author: Marcos Munguia, Omar Trueba, ChiaSiang Chng
//
// Assignment: Lab 3
//
// *********************************************************************************************************************
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <fstream>
#include "LINKEDLIST_FINAL.h"
using namespace std;

int main()
{

    int commandCounter = 0;                                                 // Counts the the commands
    string fileName;
    string textFileExtension = ".txt";                                      // Used to append file names
    string outputFileName;
    string testRunName;

    cout << "Enter The Input File Name: ";                                  // Command text file prompt
    cin >> fileName;
    fileName = fileName+textFileExtension;


    cout << "\nEnter The Output File Name: ";                               // Output file prompt
    cin >> outputFileName;
    outputFileName = outputFileName + textFileExtension;


    cin.ignore();                                                           // Clearing the buffer in cin for getline()

    cout << "\nEnter The Test Run Name: ";                                  // Asking for name of current test run
    getline(cin, testRunName);
    cout << testRunName << endl;


    ofstream outputFile(outputFileName);                                    // Writting test run name into output file
    outputFile << testRunName << endl;
    outputFile.close();



    ifstream file(fileName);
    myList thisList;                                                        // New linked list object 'thisList'

    bool toPush, push = false;                                              // These bools are used as flags, when the
    bool toGet, get = false;                                                // program runs and see the commands PutItem(),
    bool toDelete, del = false;                                             // DeleteItem(), or GetItem() it will set it to true
                                                                            // which will then wait for the next item to be read which is the value
    string instructions;                                                    // for one of the functions.
    int x = -250;

    while(file >> instructions)
    {
        char *cstr = new char[instructions.length()+1];                    // Read in the instruction and convert to c str to use
        strcpy (cstr,instructions.c_str());                                // isDigit to find the values for functions.


        if(push == true && x > -250)
        {
            commandCounter += 1;
            cout << " Command number " << commandCounter << " completed." << endl;
            thisList.PutItem(x);
            outputFile.open(outputFileName, ios::app);
            outputFile << x  << " is in list." << endl;
            outputFile.close();
            x =  -250;
            toPush = false;
            push = false;
        }

        if(get == true && x > -250)
        {
            commandCounter += 1;
            cout << " Command number " << commandCounter << " completed." << endl;
            thisList.GetItem(x, outputFileName);
            x = -250;
            toGet = false;
            get = false;
        }

        if(del == true && x > -250)
        {
            commandCounter += 1;
            cout << " Command number " << commandCounter << " completed." << endl;
            thisList.DeleteItem(x);
            outputFile.open(outputFileName, ios::app);
            outputFile << x << " is deleted." << endl;
            outputFile.close();
            x = -250;
            toDelete = false;
            del = false;
        }


        if(instructions == "PutItem")
        {
            toPush = true;
        }
        else if(instructions == "GetItem")
        {
            toGet = true;
        }
        else if(instructions == "DeleteItem")
        {
            toDelete = true;
        }
        else if(instructions == "PrintList")
        {
            commandCounter += 1;
            cout << " Command number " << commandCounter << " completed." << endl;
            thisList.PrintList(outputFileName);
        }
        else if(instructions == "GetLength")
        {
            commandCounter += 1;
            cout << " Command number " << commandCounter << " completed." << endl;
            outputFile.open(outputFileName, ios::app);
            outputFile << "Length is " << thisList.GetLength() << endl;
            outputFile.close();

        }
        else if(instructions == "IsFull")
        {
            commandCounter += 1;
            cout << " Command number " << commandCounter << " completed." << endl;
            if(thisList.IsFull() == false)
            {
                outputFile.open(outputFileName, ios::app);
                outputFile << "List is not full." << endl;
            }
            else
                outputFile << "List is full." << endl;
                outputFile.close();
        }
        else if(instructions == "MakeEmpty")
        {
            commandCounter += 1;
            cout << " Command number " << commandCounter << " completed." << endl;
            thisList.MakeEmpty();
        }
        else if(instructions == "Quit")
        {
            commandCounter += 1;
            cout << " Command number " << commandCounter << " completed." << endl;
            thisList.Quit();
        }
        else if(instructions == "Error")
        {
            cout << "Error is not A valid command." << endl;
        }


        if(isdigit(cstr[0]))        // Check if the first character in the c str is a digit.
        {
            x = atoi(cstr);
        }

        get = toGet;                // Reset my 'flags' for the functions.
        push = toPush;
        del = toDelete;
    }
}
