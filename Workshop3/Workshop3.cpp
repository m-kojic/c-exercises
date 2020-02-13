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
	Recipe* recipes;
	int totalRecipes;
};

struct Recipe {
	string name;
	Ingredient* ingredients[2];
};

unsigned int totalRecipes = 0;
unsigned int totalItems = 0;
unsigned int totalIngredients = 0;

Item* items;
Ingredient* ingredients;
Recipe* recipes;

Item* getItem(string input) {
	for (int i = 0; i < totalItems; i++)
	{
		if (items[i].name == input) {
			return &items[i];
		}
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

void makeItem(string name, Recipe* recipe) {
	if (recipe->ingredients[0]->amount > 0 && recipe->ingredients[1]->amount > 0) {
		recipe->ingredients[0]->amount -= 1;
		recipe->ingredients[1]->amount -= 1;
		cout << "Item \"" << name << "\" created!" << endl;
	}
	else {
		cout << "No enough ingredients to make this item!" << endl;
	}
}

void checkForMultipleRecipes(Item* item) {
	if (item->totalRecipes > 1) {
		cout << "What recipe do you want to create?" << endl;
		for (int i = 0; i < item->totalRecipes; i++)
		{
			cout << "Option " << i << ": " << item->recipes[i].name << " = "
				<< item->recipes[i].ingredients[0]->name << " + " << item->recipes[i].ingredients[1]->name << endl;
		}

		int option;
		cin >> option;
		if (option < item->totalRecipes) {
			Recipe* recipe = &(item->recipes[option]);
			makeItem(item->name, recipe);
		}
		else {
			cout << "Invalid value!" << endl;
		}
	}
	else {
		makeItem(item->name, &(item->recipes[0]));
	}
}

void processInput(string input) {
	Item* inputItem = getItem(input);
	if (inputItem != nullptr) {
		checkForMultipleRecipes(inputItem);
	}
	else if (input == "items") {
		cout << endl << "ITEMS" << endl;
		cout << "****************" << endl;
		for (int i = 0; i < totalItems; i++)
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
			cout << endl << recipes[i].name << endl << endl;
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

int countItems(string* recipes, unsigned int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		string name = recipes[i];
		int j;
		for ( j = 0; j < i; j++) {
			string comparedName = recipes[j];
			if (name == comparedName) {
				break;
			}
		}

		if(i == j)
			count++;
	}
	return count;
}

void countIngredientsAndRecipes(ifstream& inputFile) {
	string line;
	stringstream stringStream;
	string itemNames[100];
	while (getline(inputFile, line))
	{
		if (line.find("=") != string::npos) {
			stringStream.str(line);
			string name;
			stringStream >> name;
			itemNames[totalRecipes] = name;
			totalRecipes++;
		}
		else {
			totalIngredients++;
		}
	}
	totalItems = countItems(itemNames, totalRecipes);
	cout << "totalItems: " << totalItems << endl;
	cout << "totalRecipes: " << totalRecipes << endl;
	cout << "totalIngredients: " << totalIngredients << endl;
}

void populateIngredientsAndRecipes(ifstream& inputFile) {
	recipes = new Recipe[totalRecipes];
	ingredients = new Ingredient[totalIngredients];
	items = new Item[totalItems];

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
			item->recipes = new Recipe[totalRecipes];
			Recipe* recipe = new Recipe;
			item->amount = 0;
			item->totalRecipes = 0;

			string recipeName;
			lineStream >> recipeName;
			item->name = recipeName;
			recipe->name = recipeName;
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

			Item* existingItem = getItem(recipeName);
			if (existingItem == nullptr) {
				item->recipes[item->totalRecipes] = *recipe;
				item->totalRecipes += 1;
				items[currentRecipes] = *item;
			}
			else {
				existingItem->recipes[existingItem->totalRecipes] = *recipe;
				existingItem->totalRecipes += 1;
			}

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