#include <iostream>
#include <fstream>
#include <string>
#include <map >
#include <vector >

using namespace std;

struct State {
	string prefix;
	map <char, State*> transitions;
};

struct Automaton {
	vector < State*> states;
	State* currentState;
};

void buildStates(Automaton* a, string& s) {
	for (int i = 0; i <= s.length(); i++) {
		// Push a state for the substring s[0] ,... ,s[i -1]
		a->states.push_back(new State());
		a->states.back()->prefix = s.substr(0, i);
		// a-> states . back ()-> transitions = map <char , State * >{};
	}
	a->currentState = a->states[0];
}

void addTransition(Automaton* a, int fromIndex, int toIndex, char c) {
	cout << " Adding transition on character " << c << " from state " << fromIndex
		<< "( prefix " << a->states[fromIndex]->prefix << ") to state " << toIndex
		<< "( prefix " << a->states[toIndex]->prefix << ")" << endl;
	a->states[fromIndex]->transitions[c] = a->states[toIndex];
}

void buildTransitions(Automaton* a, string& s) {
	// Add " backwards " transitions first ( can you see why ?)
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < i; j++) {
			State* si = a->states[i], * sj = a->states[j];
			string iPrefix = si->prefix.substr(i - j);
			if (iPrefix == sj->prefix)
				addTransition(a, i, j + 1, s[j]);
		}
	}
	// Now add the " forwards " transitions
	for (int i = 0; i < s.length(); i++) {
		addTransition(a, i, i + 1, s[i]);
	}
}

Automaton* buildAutomaton(string& s) {
	Automaton* a = new Automaton();
	buildStates(a, s);
	buildTransitions(a, s);
	return a;
}

void processChar(Automaton* a, char c) {
	State* s = a->currentState;
	map <char, State* >::iterator t = s->transitions.find(c);
	cout << " Parsing character " << c << " in state " << s->prefix;
	if (t == s->transitions.end())
		// No matching transition ; back to the initial state
		a->currentState = a->states[0];
	else
		// Iterators in a map point to a <key , value > pair ; second gets us the value
		a->currentState = t->second;
	cout << " --> state now: " << a->currentState->prefix << endl;
}

bool isFinal(Automaton* a) {
	return (a->currentState == a->states.back());
}

bool processText(Automaton* a, string& text) {
	// Should only happen if the search string is empty
	if (isFinal(a)) {
		cout << " Search string is empty!" << endl;
		return true;
	}
	for (int i = 0; i < text.length(); i++) {
		processChar(a, text[i]);
		if (isFinal(a)) {
			// Note that this outputs the position of the last character .
			// Can you see how to output the first position instead ?
			cout << " Search string found at position " << i << endl;
			return true;
		}
	}
	cout << " Search string not found " << endl;
	return false;
}

string GetFileContent() {
	string line = "";
	string text = "";
    ifstream inputFile;
    inputFile.open("text.txt");
    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
			text += line;
        }
        inputFile.close();
    }
    else {
        cout << "Unable to open file";
    }

	return text;
}

int main()
{
	std::cout << "WEBINAR 6!\n";
	//string text = "fnordcococoafnord";
	string text = GetFileContent();
	string findMe = "corona";
	Automaton* a = buildAutomaton(findMe);
	processText(a, text);
}
