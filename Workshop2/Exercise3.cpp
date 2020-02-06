//// Workshop2.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
//#include <iostream>
//using namespace std;
//
//string SquareWord(string word) {
//	string substring = "";
//
//	for (int l = 0; l < word.length(); l++)
//	{
//		int length = l + 1;
//		for (int i = 0; i < word.length(); i++)
//		{
//			int nextIndex = i + length;
//			substring = word.substr(i, length);
//			int findIndex = word.find(substring, nextIndex);
//			if (nextIndex == findIndex) {
//				return substring;
//			}
//		}
//	}
//
//	return "No square";
//}
//
//int main()
//{
//	cout << "EXERCISE 3!\n";
//	string word = "banana";
//	cout << "Result: " << SquareWord(word) << endl;
//}
