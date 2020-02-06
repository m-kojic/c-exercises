// Tutorial2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    cout << "EXERCISE 1\n";
    ifstream ifStreamFile;
    ifStreamFile.open("input.txt");
    ofstream ofStreamFile;
    ofStreamFile.open("output.txt");

    int result = 0;
    int currentNumber = 0;

    if (ifStreamFile.is_open() && ofStreamFile.is_open()) {
        while (ifStreamFile >> currentNumber) {
            result += currentNumber;
            ofStreamFile << result << endl;
        }
        ifStreamFile.close();
    }
    else {
        cout << "Unable to open file";
    }

    cout << endl << "Result: " << result << endl;
}
