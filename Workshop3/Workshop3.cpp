// Workshop3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

unsigned int totalRecipes = 0;
unsigned int totalIngredients = 0;
unsigned int totalItems = 0;

string* recipes = new string[totalRecipes];
string* ingredients = new string[totalIngredients];

void processInput(string input) {
	if (input == "items") {
		cout << "Print items!" << endl;
	}
	else if (input == "recipes") {
		cout << endl << "RECIPES" << endl;
		cout << "****************" << endl;
		for (int i = 0; i < totalRecipes; i++)
		{
			cout << recipes[i] << endl;
		}
		cout << "****************" << endl;
	}
	else if (input == "ingredients") {
		cout << endl << "INGREDIENTS" << endl;
		cout << "****************" << endl;
		for (int i = 0; i < totalIngredients; i++)
		{
			cout << ingredients[i] << endl;
		}
		cout << "****************" << endl;
	}
	else if (input == "quit") {
		exit(1);
	}
	else {
		cout << "Invalid input. Please use \"items\", \"recipes\", \"ingredients\", \"{itemname}\" or \"quit\"" << endl;
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

void countIngredientsAndRecipes(ifstream& inputFile) {
	string line;
	while (getline(inputFile, line))
	{
		if (line.find("=") != std::string::npos) {
			totalRecipes++;
		}
		else {
			totalIngredients++;
		}
	}
	cout << "totalRecipes: " << totalRecipes << endl;
	cout << "totalIngredients: " << totalIngredients << endl;
}

void populateIngredientsAndRecipes(ifstream& inputFile) {
	recipes = new string[totalRecipes];
	ingredients = new string[totalIngredients];

	string line;
	unsigned int currentRecipes = 0;
	unsigned int currentIngredients = 0;

	while (getline(inputFile, line))
	{
		if (line.find("=") != string::npos) {
			recipes[currentRecipes] = line;
			currentRecipes++;
		}
		else {
			ingredients[currentIngredients] = line;
			currentIngredients++;
		}
	}

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
			countIngredientsAndRecipes(inputFile);
			inputFile.clear();
			inputFile.seekg(0, ios::beg);
			populateIngredientsAndRecipes(inputFile);
			inputFile.close();
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
