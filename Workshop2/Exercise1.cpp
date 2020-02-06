#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

stack<int> consts;
stack<char> operators;
stack<char> parenthesis;

int operand1 = 0;
int operand2 = 0;
int result = 0;

ifstream inputFile;

void Calculate() {
	operand1 = consts.top();
	consts.pop();

	operand2 = consts.top();
	consts.pop();

	char currentOperator = operators.top();
	operators.pop();

	if (currentOperator == '+') {
		result = operand1 + operand2;
	}
	else if (currentOperator == '-') {
		result = operand2 - operand1;
	}
	else if (currentOperator == '*') {
		result = operand1 * operand2;
	}
	else {
		result = operand2 / operand1;
	}
	consts.push(result);
}

void ProcessData(char c) {

	if (c == '(') {
		parenthesis.push(c);
	}
	else if (c == ')') {
		Calculate();
	}
	else if (isdigit(c)) {
		char peekValue = inputFile.peek();
		if (isdigit(peekValue)) {
			string merged = { c , peekValue };
			consts.push(stoi(merged));
			inputFile.get();
		}
		else {
			consts.push(c - '0');
		}
	}
	else {
		operators.push(c);
	}
}

int main() {
	cout << "EXERCISE 1" << endl;
	inputFile.open("exercise1.txt");
	if (inputFile.is_open())
	{
		while (!inputFile.eof())
		{
			char c = inputFile.get();
			ProcessData(c);
			cout << c << '\n';
		}
		inputFile.close();
	}
	else {
		cout << "Unable to open file";
	}

	cout << "Result: " << result << '\n';
}