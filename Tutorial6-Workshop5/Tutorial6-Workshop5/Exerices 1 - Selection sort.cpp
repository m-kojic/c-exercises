//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void selectionSort(vector<int>& v) {
//	for (int firstUnsorted = 0; firstUnsorted < v.size(); firstUnsorted++)
//	{
//		// Set initial min and minIndex
//		int min = v[firstUnsorted];
//		int minIndex = firstUnsorted;
//		// Find the smallest value in the unsorted region
//		// Start from the first unsorted element + 1 because we just stored min above the loop
//		for (int i = firstUnsorted + 1; i < v.size(); i++)
//		{
//			// If the current element is smaller than the min then store both the value and index
//			if (v[i] < min) {
//				min = v[i];
//				minIndex = i;
//			}
//		}
//		// Swap min with first unsorted element unless they are the same
//		if (minIndex != firstUnsorted) {
//			v[minIndex] = v[firstUnsorted];
//			v[firstUnsorted] = min;
//		}
//	}
//}
//
//void printVector(vector<int>& v) {
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	cout << "WEBINAR 4 - EXERCISE 1!" << endl;
//	vector<int> v;
//	v.push_back(4);
//	v.push_back(7);
//	v.push_back(1);
//	v.push_back(3);
//	v.push_back(2);
//	cout << "Starting vector:" << endl;
//	printVector(v);
//	cout << "***********************" << endl;
//	selectionSort(v);
//	cout << "Sorted vector:" << endl;
//	printVector(v);
//	cout << "***********************" << endl;
//}
