//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//
//int main() {
//    //Write to a file
//    ofstream outputFile;
//    outputFile.open("exampleFile.txt");
//    if (outputFile.is_open()) {
//        outputFile << "Writing this to a file.\n";
//        outputFile << "Writing this to a file line 2.\n";
//        outputFile.close();
//    }
//    else {
//        cout << "Unable to open file";
//    }
//    
//
//	  //************************************************
//    //*** Read from a file - ONLY THE FIRST STRING ***
//    //************************************************
//
//    //string content;
//    //ifstream inputFile;
//    //inputFile.open("exampleFile.txt");
//    //inputFile >> content;
//    //cout << content;
//    
//	  //***************************************
//    //*** Read from a file - LINE BY LINE ***
//    //***************************************
//
//    /*string line = "";
//    ifstream inputFile;
//    inputFile.open("exampleFile.txt");
//    if (inputFile.is_open())
//    {
//        while (getline(inputFile, line))
//        {
//            cout << line << '\n';
//        }
//        inputFile.close();
//    }
//    else {
//        cout << "Unable to open file";
//    }*/
//
//    //***************************************
//    //*** Read from a file - CHAR BY CHAR ***
//    //***************************************
//    string line = "";
//    ifstream inputFile;
//    inputFile.open("exampleFile.txt");
//    if (inputFile.is_open())
//    {
//        while (!inputFile.eof())
//        {
//            char c = inputFile.get();
//            cout << c << '\n';
//        }
//        inputFile.close();
//    }
//    else {
//        cout << "Unable to open file";
//    }
//}