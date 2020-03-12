//Q9 (16.22%)

//#include <iostream>
//using namespace std;
//
//// x and y are references to what ever is passed to the function
//// since the same variable is passed for both x and y that means by changing x that changes y too
//void f(int& x, int& y) {
//    if (x <= y)
//        x = x + y;
//    if (y <= x)
//        y = x + y;
//}
//
//int main() {
//	cout << "Q9" << endl;
//    
//    int k = 2;
//    // the same variable k is passed two times
//    f(k, k);
//    cout << "k: " << k << endl;
//}