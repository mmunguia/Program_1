// Author: Marcos Munguia


#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include "LINKEDLIST_FINAL.h"
using namespace std;

myList::myList()
{
    head = new node;
    head = NULL;
};

myList::~myList(void)
{
    node *next;
    while(head != NULL)
    {
        next = head->next;
        delete head;
        head = next;
    }
};

void myList::PutItem(int x)
{
    node *n = new node;
    n->next = NULL;
    n->data = x;
    if(head != NULL)
    {
        curr = head;
        while(curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = n;
    }
    else
    {
        head = n;
    }
};

void myList::PrintList(string outputFileName)
{
    ofstream outputFile(outputFileName, ios::app);


    if(head == NULL)
    {
        return;
    }

    if(head != NULL)
    {
        curr = head;
    }

    while(curr->next != NULL)
    {
        outputFile << curr->data;
        curr = curr->next;
    }
    outputFile << curr->data << endl;
    outputFile.close();
};

int myList::GetLength()
{
    sizeCount = 0;
    if(head == NULL)
    {
        sizeCount = 0;
    }


    if(head != NULL)
    {
        curr = head;
        while(curr->next != NULL)
        {
            sizeCount = sizeCount + 1;
            curr = curr->next;
        }
        sizeCount = sizeCount + 1;
        return sizeCount;
    }
};



void myList::DeleteItem(int deleteThisItem)
{
    node *temp = head;
    node *prev = new node;

    if(temp != NULL && temp->data == deleteThisItem)
    {
        head = temp->next;
        delete temp;
        return;
    }

    while(temp != NULL && temp->data != deleteThisItem)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        return;
    }

    prev->next = temp->next;
    delete temp;
};


int myList::GetItem(int getThisItem,string outputFileName)
{
    ofstream outputFile(outputFileName, ios::app);

    if(head == NULL)
    {
        return 0;
    }

    if(head != NULL)
    {
        curr = head;
    }

    while(curr->next != NULL)
    {
        if(curr->data == getThisItem)
        {
            outputFile << getThisItem << " found in list." << endl;
            return getThisItem;
        }
        curr = curr->next;
    }
    if(curr->data == getThisItem)
        {
            outputFile << getThisItem << " found in list." << endl;
            return getThisItem;
        }
        else
            outputFile << getThisItem << " not in list." << endl;
            outputFile.close();
};


void myList::Quit()
{
    cout << "Testing completed." << endl;
    exit(0);
};

bool myList::IsFull()
{
    bool outOfMemory = false;
    return outOfMemory;

};

void myList::MakeEmpty()
{
    this->~myList();
};

