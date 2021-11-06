#include "Driver.h"
#include <iostream>

using namespace std;


// swap two variables without using a temporary variable
void Swap(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

// checks a variable using bitwise operator
void CheckIfOddOrEven(int a)
{
	if (!(a&1))
	{
		cout << " is even." << endl;
	}
	else
	{
		cout << " is odd." << endl;
	}
}

void SwapWithBitwise(int &a, int &b)
{
	a ^= b;
	b ^= a;
	a ^= b;
	
}

void ConvertCaseBitwise()
{
	
	char word[8] = "sREedEv";
	char* wordptr = &word[0];

	cout << "Word: " << word << endl;
	
	while (wordptr < &word[7])
	{
		cout << "UPPERCASE: " << (*wordptr & '_') << endl;
		cout << "lowercase: " << (*wordptr | ' ') << endl;
		wordptr++;
	}

	cout << "Word: " << word << endl;
	
}


void main()
{
	int x = 5, y = 6;

	cout << "x & y: " << (x & y) << endl;	// prints '4'

	/*cout << "Before swap: x = " << x << " and y = " << y << endl;
	Swap(x, y);
	cout << "After swap:  x = " << x << " and y = " << y << endl;*/

	cout << "x | y: " << (x | y) << endl;	// prints '7'
	cout << "x ^ y: " << (x ^ y) << endl;	// prints '3'
	cout << "~x: " << (~x) << endl;

	y = 2;
	cout << "x << y: " << (x << y) << endl;	// prints '20'
	cout << "x >> y: " << (x >> y) << endl;	// prints '1'
	
	cout << "x";
	CheckIfOddOrEven(x);
	cout << "y";
	CheckIfOddOrEven(y);

	cout << "Before swap: x = " << x << " and y = " << y << endl;
	SwapWithBitwise(x, y);
	cout << "After swap:  x = " << x << " and y = " << y << endl;

	ConvertCaseBitwise();
	
}
