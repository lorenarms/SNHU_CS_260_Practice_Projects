#include "Driver.h"
#include <iostream>

using namespace std;


// typedef means 'myStruct' is now a type like 'int'
typedef struct
{
	char a;
	int b;
} myStruct;




class A
{
public:
	virtual int value() { return 1; }
};

class B : public A
{
public:
	int value() { return 2; }

};




int a()
{
	cout << "a";
	return 0;
}
int b()
{
	cout << "b";
	return 0;
}




void main()
{
	A* obj = new B();
	int val = obj->value();

	// prints out '2' 
	cout << "Val: " << val << endl;


	myStruct s1;
	s1.a = 'a';
	s1.b = 3;

	myStruct s2;
	s2 = s1;

	// prints '3' because s2 = s1
	cout << "s2 = " << s2.b << endl;


	
	
	int e = 5;
	int* p = &e;

	// prints the address of 'e' (pointer value)
	cout << "p = " << p << endl;




	int c = 1;
	int d = 1;

	int* pc = &c;
	int* pd = &d;

	// prints '0' because the pointers are not equal
	cout << "pc = pd? " << (pc == pd) << endl;
	cout << "c = d? " << (c == d) << endl;



	// single pipe checks all parts of conditional
	// prints 'ab' because each method prints the respective letter
	// '|' is less efficient than '||'
	// '|' is the bitwise 'OR'
	if (a() ^ b())
	{
		cout << "main" << endl;
		
	}
	
	
}


