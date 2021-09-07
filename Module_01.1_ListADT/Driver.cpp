#include <iostream>
#include <string>
#include <vector>

using namespace std;

class List {
	
	vector<int> newList;
	
	List(int size) {
		newList.resize(size);

	}
};

int main() {

	int myVar = 555;
	int* myPtr = &myVar;			// '*' after var type defines a pointer

	cout << "Var: " << myVar << " Pointer: " << myPtr << endl;
	cout << "Var: " << myVar << " Pointer: " << &myVar << endl;		// '&' at beginning of var accesses pointer of that var (even if one isn't defined explicitly)
	cout << "Var: " << *myPtr << endl;			// '*' at beginning of pointer var acceses content of pointer

	int* newPtr = 0;
	cout << "newPtr: " << newPtr << endl;

	// Next line would cause error because myPtr is null
	//cout << "*myPtr: " << *myPtr << endl; // ERROR


	// new allocates int, returns pointer
	newPtr = new int;
	cout << "newPtr: " << newPtr << endl;
	cout << "*newPtr: " << *newPtr << endl;

	*newPtr = 555;
	cout << "*newPtr: " << *newPtr << endl;



	cin.get();
	return 0;
}