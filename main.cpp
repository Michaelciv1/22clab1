/*
  CIS 22C
    Lab1: This lab uses a linked list to create a phonebook
    where the user can insert, delete, and display contacts.

  Author: Michael Wallerius

  Date: 4/23/2020

*/

#include <iostream>
#include "contactlist.h"

using namespace std;

int main()
{
    char choice;
    string fname, lname, pnumber, name;
    contactlist phonebook;
    cout << "Welcome to the Phone Book" << endl;
    cout << "-------------------------" << endl;
    cout << "Options (type number to make selection)" << endl;
    cout << "1. Add to the phone book" << endl;
    cout << "2. Delete from the phone book" << endl;
    cout << "3. Display the phone book" << endl;
    cout << "4. Exit the program" << endl;
    cout << endl;

    while (choice != '4'){
    cout << "What do you want to do: ";
    cin >> choice;
    cout << endl;

    switch (choice){
        case '1':
            cout << "Enter his/her first name: ";
            cin >> fname;
            cout << "Enter his/her last name: ";
            cin >> lname;
            cout << "Enter their 10-digit phone number w/o spaces: ";
            cin >> pnumber;
            phonebook.insertNode(fname,lname,pnumber);
            cout << endl;
            cout << fname << " " << lname << " " << pnumber << " has been added to the phonebook." << endl;
            cout << endl;
            break;
        case '2':
            cout << "Enter his/her first name: ";
            cin >> fname;
            cout << "Enter his/her last name: ";
            cin >> lname;
            phonebook.deleteNode(fname, lname);
            cout << fname << " " << lname << " has been removed from the phonebook." << endl;
            break;
        case '3':
            cout << "Phonebook" << endl;
            cout << "---------" << endl;
            phonebook.displayList();
            cout << endl;
            break;
        }
    }
}
