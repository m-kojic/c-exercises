#include <iostream>
#include <stack>
using namespace std;

void ShowStack(stack<int> s) {
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	cout << "\n";
}
int main() {
	cout << "STACK" << endl;

	stack<int> intStack;
	intStack.push(10);
	intStack.push(20);
	intStack.push(30);
	intStack.push(40);

	cout << "Top: " << intStack.top() << endl;
	cout << "Size: " << intStack.size() << endl;
	ShowStack(intStack);
	intStack.pop();
	ShowStack(intStack);
}