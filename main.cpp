#include <iostream>
#include <cstring>
#include "myint.h"

using namespace std;

int main() {
	
	MyInt A;
	MyInt B("123456789");
	MyInt C(1234);	

	cout << "Deafualt constuctor  is " << A << endl; 
	cout << "cstring 55667788 is "<< B << endl; 
	cout <<"Integer 1234 is " << C << endl;

	MyInt D = C;

	cout <<"The coppy of " << C << " is " << D << endl; 
	cout <<"**************************************************************************************************************************************" << endl;
	MyInt F = B + C;
	//cout << B << " + " << C << " Is " << D << endl;
	
	cout <<"**************************************************************************************************************************************" << endl;
cout << C << " + " << B << " = " << F 	<< endl;
F = B + C;
cout << F << endl;

cout <<"**********************************************************************************************************************************************" << endl;
MyInt H("123");
MyInt I("12");
MyInt G = H * I;
cout << I << " * " << H << " = " <<  G << endl;
	return 0;


}
