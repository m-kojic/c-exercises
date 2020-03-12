#include <iostream>
#include <set>
using namespace std;

struct TreeNode {
	int data;
	TreeNode *leftChild, *rightChild;
};

struct MalformedTree {};

// Check weather all values in the subtree below n are less than the pivot
bool allLess(TreeNode *n, int pivot) {
	if (n != nullptr) {
		return ((n->data < pivot) &&
				allLess(n->leftChild, pivot) && 
				allLess(n->rightChild, pivot));
	}
	// otherwise nothing to check (no children)
	return true;
}

bool allGreater(TreeNode *n, int pivot) {
	if (n != nullptr) {
		return ((n->data > pivot) &&
				allGreater(n->leftChild, pivot) &&
				allGreater(n->rightChild, pivot));
	}
	// otherwise nothing to check (no children)
	return true;
}

bool isSorted(TreeNode *root) {
	if (root != nullptr) {
		return (isSorted(root->leftChild) && 
				isSorted(root->rightChild) &&
				allLess(root->leftChild, root->data) &&
				allGreater(root->rightChild, root->data));
	}
	// otherwise : nothing to check
	return true;
}

void constructTree() {
	// Left
	TreeNode n2;
	n2.data = 3;
	n2.leftChild = nullptr;
	n2.rightChild = nullptr;

	// Right
	TreeNode n3;
	n3.data = 9;
	n3.leftChild = nullptr;
	n3.rightChild = nullptr;

	// Root
	TreeNode n1;
	n1.data = 8;
	n1.leftChild = &n2;
	n1.rightChild = &n3;

	cout << "Is sorted: " << isSorted(&n1) << endl;
}

// A set of node pointers that keep track of which nodes have already been seen
//#include<set>
bool isSortedRec(TreeNode* root, std::set<TreeNode*>& seen) {
	if (root != nullptr) {
		if (seen.find(root) != seen.end()) {
			throw MalformedTree{};
		}
		else {
			seen.insert(root);
			return (isSortedRec(root->leftChild, seen) &&
					isSortedRec(root->rightChild, seen) &&
					allLess(root->leftChild, root->data) &&
					allGreater(root->rightChild, root->data));
		}
	}
	return true;
}

bool isSortedFixed(TreeNode* root) {
	std::set<TreeNode*> seen;
	try
	{
		return isSortedRec(root, seen);
	}
	catch (MalformedTree &e)
	{
		cout << "Nice try" << endl;
	}
}

// This will cause StackOverflow exception
void faultyTree() {
	TreeNode n1 = { 1, nullptr , nullptr };
	TreeNode n0 = { 0, nullptr , &n1 };
	n1.leftChild = &n0;
	//isSorted(&n0);
	isSortedFixed(&n0);
}

int main() {
	constructTree();
	faultyTree();
}