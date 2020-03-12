#include<iostream>
#include<vector>

using namespace std;

int mergeCounter = 0;

void printRange(vector<int>& v, int low, int high, string message) {
    string spacing = "";
    for (int i = low; i < high; i++) {
        spacing += " ";
    }
    if(message == "MERGE") {
        spacing = "";
    }
    cout << spacing << message << endl;
    string temp = "";
    for (int i = low; i < high; i++)
    {
        temp += to_string(v[i]) + " ";
    }
    cout << spacing << temp << endl;
    cout << endl;
}

// This function merges two ranges
// ***********************************
// [low is the starting position in the left side
// ]mid is the upper bound for the left side
// [mid is the starting position in the right side
// ]high is the upper bound for the right side
void mergeRanges(vector<int>& v, int low, int mid, int high) {
    mergeCounter++;
    // "temp" keeps track of sorted elements in the current merging
    vector<int> temp;
    // lowIndex will be initialized with starting position in the left side
    // it will be incremented every time we add an element to temp from the left side
    int lowIndex = low;
    // lowIndex will be initialized with starting position in the right side
    // it will be incremented every time we add an element to temp from the right side
    int midIndex = mid;

    // we need to go through all the elements in the both ranges and merge the values
    // so that the resulting range is sorted
    // "mid" and "high" determine the upper bounds for left and right side
    while (lowIndex < mid && midIndex < high) {
        // we need to compare valus in both ranges
        // if the value in the left range is lower that the value in the right
        // we add that value to the temp vector and increment the index to point to the next element
        if (v[lowIndex] < v[midIndex]) {
            temp.push_back(v[lowIndex++]);
        }
        // otherwise we take value from the right range
        // and increment the index in the right side
        else {
            temp.push_back(v[midIndex++]);
        }
    }
    // do to the while loop above only one region will have remaining elements
    // if something is left in the left range then we should copy that to temp
    while (lowIndex < mid) {
        temp.push_back(v[lowIndex++]);
    }
    // if something is left in the right range then we should copy that to temp
//    while (midIndex < high) {
//        temp.push_back(v[midIndex++]);
//    }
    printRange(temp, 0, temp.size(), "MERGE");
    // copy elements from the temp vector back to the original vector
    for (int i = 0; i < temp.size(); i++)
    {
        v[low + i] = temp[i];
    }
}

// this function is going to be called recursively to sort ranges
void sortRange(vector<int>& v, int low, int high)
{
    // if range is a single element then no need to sort
    if (low < high - 1) {
        int mid = (low + high) / 2;
        // sort left range from (low to mid - 1)
        printRange(v, low, mid, "LEFT");
        sortRange(v, low, mid);
        // sort left range from (mid to hight - 1)
        printRange(v, mid, high, "RIGHT");
        sortRange(v, mid, high);
        mergeRanges(v, low, mid, high);
    }
}

void mergeSort(vector<int>& v) {
    sortRange(v, 0, v.size());
}

void printVector(vector<int>& v) {
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "WEBINAR 4 - EXERCISE 2!" << endl;
    vector<int> v;

    v.push_back(14);
    v.push_back(7);
    v.push_back(3);
    v.push_back(12);
    v.push_back(9);
    v.push_back(11);
    v.push_back(6);
    v.push_back(2);

    cout << "Starting vector:" << endl;
    printVector(v);
    cout << "***********************" << endl;

    mergeSort(v);

    cout << "Sorted vector:" << endl;
    printVector(v);
    cout << "***********************" << endl;

    cout << "MERGE #: " << mergeCounter << endl;
}
#include<iostream>
#include<vector>

using namespace std;

int mergeCounter = 0;

void printRange(vector<int>& v, int low, int high, string message) {
	cout << message << endl;
	for (int i = low; i < high; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

// This function merges two ranges
// ***********************************
// [low is the starting position in the left side
// ]mid is the upper bound for the left side
// [mid is the starting position in the right side
// ]high is the upper bound for the right side
void mergeRanges(vector<int>& v, int low, int mid, int high) {
	mergeCounter++;
	// "temp" keeps track of sorted elements in the current merging
	vector<int> temp;
	// lowIndex will be initialized with starting position in the left side
	// it will be incremented every time we add an element to temp from the left side
	int lowIndex = low;
	// lowIndex will be initialized with starting position in the right side
	// it will be incremented every time we add an element to temp from the right side
	int midIndex = mid;

	// we need to go through all the elements in the both ranges and merge the values
	// so that the resulting range is sorted
	// "mid" and "high" determine the upper bounds for left and right side
	while (lowIndex < mid && midIndex < high) {
		// we need to compare valus in both ranges
		// if the value in the left range is lower that the value in the right
		// we add that value to the temp vector and increment the index to point to the next element
		if (v[lowIndex] < v[midIndex]) {
			temp.push_back(v[lowIndex++]);
		}
		// otherwise we take value from the right range
		// and increment the index in the right side
		else {
			temp.push_back(v[midIndex++]);
		}
	}
	// if something is left in the left range then we should copy that to temp
	while (lowIndex < mid) {
		temp.push_back(v[lowIndex++]);
	}
	// if something is left in the right range then we should copy that to temp
	while (midIndex < high) {
		temp.push_back(v[midIndex++]);
	}
	printRange(temp, 0, temp.size(), "MERGE");
	// copy elements from the temp vector back to the original vector
	for (int i = 0; i < temp.size(); i++)
	{
		v[low + i] = temp[i];
	}
}

// this function is going to be called recursively to sort ranges 
void sortRange(vector<int>& v, int low, int high) 
{
	// if range is a single element then no need to sort
	if (low < high - 1) {
		int mid = (low + high) / 2;
		// sort left range from (low to mid - 1)
		printRange(v, low, mid, "LEFT");
		sortRange(v, low, mid);
		// sort left range from (mid to hight - 1)
		printRange(v, mid, high, "RIGHT");
		sortRange(v, mid, high);
		mergeRanges(v, low, mid, high);
	}
}

void mergeSort(vector<int>& v) {
	sortRange(v, 0, v.size());
}

void printVector(vector<int>& v) {
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	cout << "WEBINAR 4 - EXERCISE 2!" << endl;
	vector<int> v;

	v.push_back(14);
	v.push_back(7);
	v.push_back(3);
	v.push_back(12);
	v.push_back(9);
	v.push_back(11);
	v.push_back(6);
	v.push_back(2);

	cout << "Starting vector:" << endl;
	printVector(v);
	cout << "***********************" << endl;

	mergeSort(v);

	cout << "Sorted vector:" << endl;
	printVector(v);
	cout << "***********************" << endl;

	cout << "MERGE #: " << mergeCounter << endl;
}
