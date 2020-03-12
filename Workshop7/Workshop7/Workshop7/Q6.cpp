////Q6(27.03 %)
//
//#include <iostream>
//using namespace std;
//
//// Contents and points to the next node
//struct Node {
//	int contents;
//	Node* next;
//};
//
//// The function makes a sum of contents
//int stats(Node* n) {
//	if (n == nullptr)
//		return 0;
//	return (n->contents + stats(n->next));
//}
//
//int main() {
//	cout << "Q6" << endl;
//
//	Node A = { 1, nullptr };
//	Node B = { 2, &A };
//	Node C = { 1, &B };
//
//	cout << "A:" << stats(&A) << endl;
//	cout << "B:" << stats(&B) << endl;
//	cout << "C:" << stats(&C) << endl;
//}