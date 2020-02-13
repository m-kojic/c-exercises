// Workshop3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Recipe;

struct Ingredient {
	string name;
	unsigned int amount;
};

struct Item {
	string name;
	unsigned int amount;
	Recipe* recipe;
};

struct Recipe {
	Item* item;
	Ingredient* ingredients[2];
};

unsigned int totalRecipes = 0;
unsigned int totalIngredients = 0;

Item* items;
Ingredient* ingredients;
Recipe* recipes;

Item* getItem(string input) {
	for (int i = 0; i < totalRecipes; i++)
	{

	}
	return nullptr;
}

Ingredient* getIngredient(string name) {
	for (int i = 0; i < totalIngredients; i++)
	{
		if (ingredients[i].name == name) {
			return &ingredients[i];
		}
	}
	return nullptr;
}

void MakeItem(Item* item) {
	//	Item newItem = new Item(item->name, item->amount++, item->ingredients);
}

void processInput(string input) {
	if (input == "items") {
		cout << endl << "ITEMS" << endl;
		cout << "****************" << endl;
		for (int i = 0; i < totalRecipes; i++)
		{
			cout << items[i].name << " " << items[i].amount << endl;
		}
		cout << endl << "****************" << endl;
	}
	else if (input == "recipes") {
		cout << endl << "RECIPES" << endl;
		cout << "****************" << endl;
		for (int i = 0; i < totalRecipes; i++)
		{
			cout << endl << recipes[i].item->name << endl << endl;
			cout << "Ingredients: " << endl;
			for (unsigned int j = 0; j < 2; j++)
			{
				cout << "\t" << recipes[i].ingredients[j]->name << " ";
			}
			cout << endl;
		}
		cout << endl << "****************" << endl;
	}
	else if (input == "ingredients") {
		cout << endl << "INGREDIENTS" << endl;
		cout << "****************" << endl;
		for (int i = 0; i < totalIngredients; i++)
		{
			cout << ingredients[i].name << " " << ingredients[i].amount << endl;
		}
		cout << "****************" << endl;
	}
	else if (Item* selectedItem = getItem(input)) {
		MakeItem(selectedItem);
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
		if (line.find("=") != string::npos) {
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
	items = new Item[totalRecipes];
	ingredients = new Ingredient[totalIngredients];
	recipes = new Recipe[totalRecipes];

	string line;
	unsigned int currentRecipes = 0;
	unsigned int currentIngredients = 0;

	istringstream lineStream;
	while (getline(inputFile, line))
	{
		lineStream.clear();
		lineStream.str(line);

		if (line.find("=") != string::npos) {
			char ignoreChars;
			Item* item = new Item;
			Recipe* recipe = new Recipe;
			item->amount = 0;

			lineStream >> item->name;
			lineStream >> ignoreChars;

			string ingredient1Name;
			lineStream >> ingredient1Name;
			Ingredient* ingredient1 = getIngredient(ingredient1Name);
			recipe->ingredients[0] = ingredient1;

			lineStream >> ignoreChars;
			
			string ingredient2Name;
			lineStream >> ingredient2Name;
			Ingredient* ingredient2 = getIngredient(ingredient2Name);
			recipe->ingredients[1] = ingredient2;

			item->recipe = recipe;
			recipe->item = item;
			items[currentRecipes] = *item;
			recipes[currentRecipes] = *recipe;
			currentRecipes++;
		}
		else {
			Ingredient ingredient;
			lineStream >> ingredient.name;
			lineStream >> ingredient.amount;
			ingredients[currentIngredients] = ingredient;
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
