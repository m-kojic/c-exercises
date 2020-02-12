// Workshop3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void processInput(string input) {
	if (input == "items") {
		cout << "Print items!" << endl;
	}
	else if (input == "recipes") {
		cout << "Print recipes!" << endl;
	}
	else if (input == "quit") {
		exit(1);
	}
	else {
		cout << "Invalid input. Please use \"items\", \"recipes\", \"{itemname}\" or \"quit\"" << endl;
	}
}

void mainLoop() {
	while (true) {
		string currentInput;
		cout << "Your input: ";
		cin >> currentInput;
		processInput(currentInput);
	}
}

void readFromFile(ifstream &inputFile) {
	while (!inputFile.eof())
	{
		string current;
		inputFile >> current;
		cout << current << endl;
	}
	inputFile.close();
	mainLoop();
}

int main()
{
    ifstream inputFile;
	string fileName = "";
	cout << "EXERCISE 1" << endl;
	cout << "================" << endl;
	cout << "CRAFTING GAME" << endl;

	while (true) {
		cout << "Please enter the file name: ";
		cin >> fileName;
		inputFile.open(fileName);
		if (inputFile.is_open())
		{
			readFromFile(inputFile);
		}
		else {
			cout << "Unable to open file" << endl;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
