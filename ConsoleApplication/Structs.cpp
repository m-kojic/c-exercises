#include <iostream>
using namespace std;

struct Pet;

struct Person {
	string name;
	int age;
	Pet* pet;
};


struct Pet {
	string name;
	int age;
	Person* owner;
};

void main() {
	cout << "STRUCTS" << endl;

	Person person;
	Pet pet;

	person.name = "John";
	person.age = 25;
	person.pet = &pet;

	pet.name = "Doggy";
	pet.age = 3;
	pet.owner = &person;

	cout << endl << "PERSON" << endl;
	cout << person.name << endl;
	cout << person.age << endl;
	cout << person.pet->name << endl;
	cout << person.pet->owner->name << endl;

	cout << endl << "PET" << endl;
	cout << pet.name << endl;
	cout << pet.age << endl;
	cout << pet.owner->name << endl;
}


//EXAMPLE 2

//struct Person;
//
//struct Building {
//	string location;
//	Person* owner;
//};
//
//struct Person {
//	string name;
//	Building* home;
//};
//
//void main() {
//	Building b;
//	Person p;
//
//	b.location = "Cool location!";
//	p.name = "Mike";
//	b.owner = &p;
//	cout << b.owner->name << endl;
//}