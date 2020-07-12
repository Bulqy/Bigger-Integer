//Noah Shaffer
//Section 2
//cop 3330
//7/10/2020

#include <cstring>
#include "myint.h"


   char* str;		// pointer to a dynamically managed array of chars
   int size;		// this will store the size of the string
			//  allocation will be size+1 at all times
			//  and we will store internally as a c-string


//*********************************************************************************************CONVERSION FUNCTIONS WE WERE GIVEN FROM CHAR TO INTS AND VICE VERSA****************************************************************************
int C2I(char c)
// converts character into integer (returns -1 for error)
{
	if (c < '0' || c > '9')	return -1;	// error
	return (c - '0');				// success
}

char I2C(int x)
// converts single digit integer into character (returns '\0' for error)
{
	if (x < 0 || x > 9)		return '\0';	// error
	return (static_cast<char>(x) + '0'); 	// success
}
//**********************************************************************************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************************************************************************GETSUMSIZE
int MyInt::sumSize(const MyInt & x, const MyInt & y){
int bigger;
	if(x.size >= y.size)
		bigger = x.size;

	if(x.size <= y.size)		
		bigger = y.size;


	
	if((x.size==y.size && C2I(x.str[x.size-1])+C2I(y.str[y.size-1])>=10)){
		bigger = bigger+1;
			
	}

	return bigger;

}
//**********************************************************************************************************************************************************************************************************************************************
//***************************************************************************************************************************************************************************************************************************************GETbIGGER
MyInt GetBigger(const MyInt & x, const MyInt & y){
	MyInt Temp;
	//we use the overloads 
	if(x > y)
		Temp = x;

	//	Temp = y;
	return Temp;
	
}
//***************************************************************************************************************************************************************************************************************************************
//****************************************************************************************************************************************************************************************************************************************GETSMALLER
MyInt GetSmaller(const MyInt & x, const MyInt & y){
	//we use the overloads
	MyInt Temp;
	if(x < y)
		Temp =  x;

	Temp = y;
	return Temp;
}
//***************************************************************************************************************************************************************************************************************************************
//****************************************************************************************************************************************************************************************************************************************
// friend function definitions
// ***************************************************************CONCATINATION OF TWO CSTRINGS OF INTEGERS******************************************************************************************************************************

MyInt operator+ (const MyInt& x, const MyInt& y) {
MyInt sum;

	MyInt A =GetBigger(x,y);
	//Get the smaller int object for the inside loop
	MyInt B = GetSmaller(x,y);

//our strings are read in reverese

	//Get the appropriate size for sum
	sum.size  = sum.sumSize(x,y);
	//Initilize the sum array with new size
	sum.resize(sum, sum.size);
	//assign bigger int to A

	sum = sum.Add(sum,A,B);
	
	return sum;
}

//***********************************************************************************************************************************************************************************************************************MULTIPLICATION OF TWO MyInts

MyInt operator* (const MyInt& x, const MyInt& y) {	
MyInt mult;
	MyInt A = GetBigger(x,y);
	
	//Get the smaller int object for the inside loop
	MyInt B = GetSmaller(x,y);
	mult.size = mult.multSize(x,y);
	mult.resize(mult, mult.size);

	mult = mult.Multiply(mult,A,B);

	
	
	return mult;
}
//******************************************************************************************************************************************************************************************************************************************
//************************************************************************************************************************************************************************************************************************************RETURNS THE APPROPRIATE SIZE FOR THE PRODUCT

int MyInt::multSize(const MyInt & x, const MyInt & y){
//Initilize with larger size first
MyInt mult;
mult.size = x.size + y.size;
mult.resize(mult,mult.size);
//Call multiply function and if size-1 is not initilized then we know that we can subtract 1 from the size
//mult = mult.Multiply(mult,x,y);
	//M+N-1 or an M+N depending on the digits
//mult = mult.Multiply(x,y);
	return mult.size;

}

//******************************************************************************************************************************************************************************************************************************************
//*******************************************************************************************************************************************************************************************************************************************

MyInt& MyInt::Multiply(MyInt & mult, MyInt & Bigger, MyInt & Smaller){

	int c = 0;
	int R;
	int B = 1;
	int j;
	int Sum = 0;
	int  BigSum = 0;
	int S = 1;
	/*
	for(int i = 0; i <= Smaller.size-1; i++)
	S=S*10;
	
	for(int i = 0; i <= Bigger.size-1; i++)
	B=B*10;
	*/
	//we are going to add the multiplication of each loop through the array to sum, and then when we move to the next outside array we add sum to the product and rest sum to zero	
	
			
			//loop through both arrays
			for(int i= 0; i <= Smaller.size-1; i++){
				//S = S*10;	
				for(int j =0; j <= Bigger.size-1; j++){
				//	B = B*10;
					int c = (S * (C2I(Smaller.str[i]))) * (((C2I(Bigger.str[j]))) * B);
					Sum = Sum + c;
					B=B*10;
				}
				B =1;
				S=S*10;
				BigSum = BigSum + Sum;
				Sum = 0;
				
			//we are moving a tens place
			
			}
	
	mult = BigSum; 



	return mult;


}
//**************************************************************************************************************************************************************************************************************************************FIND THE BIGGER SIZE
MyInt& MyInt::Add(MyInt & sum, MyInt & Bigger, MyInt & Smaller){
	int c;
	int R;
	int k = 0;
	int j;
			for(int i =0; i <= Bigger.size-1; i++){
			int flag = false;

				//smaller array
				if(i -  Smaller.size+1> 0){	
					sum.str[k] = Bigger.str[i];
				}	
				else{	

					
				 	R =  C2I(Bigger.str[i]) + C2I(Smaller.str[k])+ c;
					sum.str[i] = I2C(R%10);
					c = R/10;
					j++;
				}
				
			k++;				
				
			}
	return sum;
}

//*****************************************************************************************OVERLOADED EXTRACTION OPERATOR***********************************************************************************************************************
ostream& operator<<(ostream& os, const MyInt& s)
{
	//os << s.str;		// print the c-string using operator<<
 
	for (int i = s.size-1 ; i >=0; i--)
		os << s.str[i];
 

	return os;
}

//***********************************************************************************************************************************************************************************************************************************************
// member function definitions


//******************************************************************************************DEFUALT CONSTRUCTOR ALSO INITILIZE WITH AND INTEGER**************************************************************************************************
MyInt::MyInt(int n)
// creates an empty string
{

	//This will store the integers in reverse order	
	int counter = 0; //This will descide how large of an array we should grow to 
	if (n <= 0) {
		size = 0;
		str = new char[1];
		str[0] = '\0';
		return;
	}

	int number = n;
	int tmp = 0;
	while (number > 0) {
		tmp = number % 10;
		counter++;
		number /= 10;
	}
	
	size = counter;
	str = new char[size + 1];

	tmp = 0;
	int i = 0;
	while (n > 0) {
		tmp = n % 10;
		str[i] = I2C(tmp);
		i++;
		n /= 10;
	}
	


}
//********************************************************************************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************************************************INTEGER TO CSTRING***(PRIVATE)
//*******************************************************************************************************************************************************************************************************************************************

//**********************************************************************************************************************************************************************************************************************CSTRING TO INTEGER(PRIVATE)
MyInt& MyInt::CstringToInteger(MyInt & x, const char * s){



return x;

}


//******************************************************************************************************************************************************************************************************************************************************

//**********************************************************************************************COPY CONSTRUCTOR******************************************************************************************************************************
MyInt::MyInt(const MyInt& D)
// copy constructor.  Initialize object as a copy of D
{
	size = D.size;
	size = D.size;

	// allocate new array of Entry objects
	str = new char[size+1];

	// copy the list over from D
	for (int i = 0; i < size; i++)
		str[i] = D.str[i];
}
//************************************************************************************************************************************************************************************************************************************************

//********************************************************************************************************************************************************************************************************************

//*******************************************************************************************ASSIGNMENT OPERATOR**********************************************************************************************************************************
MyInt& MyInt::operator= (const MyInt& D)
// assignment operator (a member function)
// does a similar task to that of the copy constructor
//  but is not a new object, so must delete any existing allocation
//  and must return the assigned value (i.e. this object, *this)
{

	if (this != &D)		// only make the copy if the original is
	{				//  not this same object

	   // first, delete the existing array
		delete[] str;

		// now do the copy.  Same way we did copy constructor
		size = D.size;
		str = new char[size+1];
		for (int i = 0; i < size; i++) {
			str[i] = D.str[i];
		}
	}

	return *this;		// return this object
}

//******************************************************************************************************************************************************************************************************************************************************


//*****************************************************************************************************CONSTRUCTOR USING CSTRING************************************************************************************************************************

MyInt::MyInt(const char* s)
// inits this string to have the data from the parameter c-string
{
	size = strlen(s);	// figure out the size of the incoming c-string
	str = new char[size + 1];
	//read them in reverse
	   for (int i = size-1, j = 0;  i >= 0 && j <= size -1; j++, i--){
		  str[i] = s[j];
		}
	

	//strcpy(str, s);
	
// this now works because we 
}
//*********************************************************************************************************************************************************************************************************************************************************

//******************************************************************************************************GETTER FUNCTION FOR SIZE***************************************************************************************************************************
int MyInt::GetSize() const
{
	return size;
}
//*********************************************************************************************************************************************************************************************************************************************************

//*****************************************************************************************************************************************************************************************************************************************DECONSTRUCTOR
MyInt::~MyInt()
// clean up
{
	delete[] str;
}
//******************************************************************************************************************************************************************************************************************************************


//***********************************************************************************************************************************************************************************************************************************COMPARISON OPERATORS
bool operator< (const MyInt& x, const MyInt& y) {

	//if the x size greater return false
	if (x.size > y.size)
		return false;

	//if x size less than return true
	if (x.size < y.size)
		return true;

	//then they are the same siize
	for (int i = 0; i < x.size; i++) {

		//the first digit where x is less than then retrun true
		if (C2I(x.str[i]) < C2I(y.str[i]))
			return true;

		//if they are equal check next number
		if (C2I(x.str[i]) == C2I(y.str[i]))
			continue;

		//return false otherwise
		return false;
	}

	return true;
}

bool operator<= (const MyInt& x, const MyInt& y) {
	if (x < y || x == y)
		return true;

	return false;
}

bool operator==(const MyInt& x, const MyInt& y) {
	//same size
	if (x.size == y.size) {

		//if a number is different then return false
		for (int i = 0; i < x.size; i++) {
			if (x.str != y.str)
				return false;
		}

		return true;
	}
	//different size they are not equal
	return false;
}

bool operator>= (const MyInt& x, const MyInt& y) {

	if (!(x < y) || x == y)
		return true;

	return false;
}

bool operator> (const MyInt& x, const MyInt& y) {
	if (!(x < y) && !(x == y))
		return true;

	return false;
}

void MyInt::resize(MyInt& x,int newSize) {
	 x.size = newSize;			// Determine a new size.
	char* newList = new char[size+1];		// Allocate a new array.

	for (int i = 0; i < size; i++)	// Copy each entry into
		newList[i] = '*';		// the new array.
	x.str[size] = '\0';
	
	delete[] str;			// Remove the old array
	str = newList;			// Point old name to new array.

}

//*****************************************************************************************************************************************************************************************************************************************************

istream& operator>>(istream& is, MyInt& s){

	return is;
}
