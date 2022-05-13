// Copyright (c) 2022 Nicolas Riscalas All rights reserved.
//
// Created by: Nicolas Riscalas
// Created on:April 25 2022
// This program figures out the mailing address

#include<iostream>
#include<cstring>
#include<algorithm>

using std::cin;
using std::cout;
using std::stof;
using std::stoi;
using std::string;

string GetAddress(string firstName, string lastName,
                       string streetAddress, string city,
                       string province, string firstPostalCode,
                       string lastPostalCode, string aptNumber = "") {
    // return the address in capital letters

    string address;

    address = firstName + " " + lastName + '\n';
    if (aptNumber.size() != 0) {
        address = address + aptNumber + "-";
    }
    address = address+streetAddress+'\n'+city+" "+province+"  "+
              firstPostalCode + " " + lastPostalCode;

    return address;
}


main() {
    // this function gets a users address and prints out their formal address

    string firstName, lastName, streetAddress, question;
    string aptNumber = "", city, province, address, postalCode;

    // input
    cout << "Enter your first name: ";
    getline(cin, firstName, '\n');
    cout << "Enter your last name: ";
    getline(cin, lastName, '\n');
    cout << "Enter your street address: ";
    getline(cin, streetAddress, '\n');
    cout << "Do you have the apartment number? (y/n): ";
    getline(cin, question, '\n');
    transform(question.begin(), question.end(), question.begin(), ::tolower);
    if (question == "y" || question == "yes") {
        cout << "Enter your apartment number: ";
        cin >> aptNumber;
    }
    cout << "Enter your city: ";
    cin >> city;
    cout << "Enter your province: ";
    cin >> province;
    cout << "Enter your postal code: ";
    cin >> postalCode;
    cout << "\n";

    if (aptNumber != "") {
        address = GetAddress(firstName, lastName, streetAddress, city,
                             province, firstPostalCode, lastPostalCode,
                             aptNumber);
    } else {
        address = GetAddress(firstName, lastName, streetAddress, city,
                             province, firstPostalCode, lastPostalCode);
    }
    transform(address.begin(), address.end(), address.begin(), ::toupper);
    cout << address;
}
