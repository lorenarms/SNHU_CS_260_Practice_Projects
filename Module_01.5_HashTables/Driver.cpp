// CPP program to implement hashing with chaining
//#include<bits/stdc++.h>
#include<list>
#include<iterator>
#include<iostream>

using namespace std;

struct Bid {
	int data;
	int moreData;
	string name;
	Bid() {
		data = -1;
		moreData = -999;
		name = "noName";
	}
};

class Hash
{
	int BUCKET; // No. of buckets

	// Pointer to an array containing buckets
	list<int>* table;
	//list<Bid>* bidTable;

public:
	Hash(int V); // Constructor

	// inserts a key into hash table
	void insertItem(int x);

	// deletes a key from hash table
	void deleteItem(int key);

	// hash function to map values to key
	int hashFunction(int x) {
		return (x % BUCKET);
	}

	void displayHash();
};

Hash::Hash(int b)
{
	this->BUCKET = b;
	table = new list<int>[BUCKET];
	//bidTable = new list<Bid>[BUCKET];
}

void Hash::insertItem(int key)
{
	Bid bid;
	int index = hashFunction(key);
	table[index].push_back(key);
	//bidTable[index].push_back(bid);
}

void Hash::deleteItem(int key)
{
	// get the hash index of key
	int index = hashFunction(key);

	// find the key in (index)th list
	list <int> ::iterator i;
	for (i = table[index].begin(); i != table[index].end(); i++) {
		if (*i == key)
			break;
	}

	// if key is found in hash table, remove it
	if (i != table[index].end())
		table[index].erase(i);
}

// function to display hash table
void Hash::displayHash() {
	for (int i = 0; i < BUCKET; i++) {
		cout << i;
		for (auto x : table[i])
			cout << " --> " << x;
		cout << endl;
	}
}

// Driver program
int main()
{
	// array that contains keys to be mapped
	int a[] = { 15, 15, 8, 8, 11, 27, 8, 12 ,15};


	/*for (int i = 0; i < sizeof(a); i++) {
		cout << "size of (a[" << i << "]): " << sizeof(a[i]) << endl;
	}*/
	
	/*int n = sizeof(a[0]);
	cout << "sizeof(a[1]): " << n << endl;
	n = sizeof(a);
	cout << "sizeof(a): " << n << endl;
	
	cout << "sizeof(a) / sizeof(a[0]): " << n << endl;*/
	
	int l = sizeof(a);
	int m = sizeof(a[0]);
	cout << "sizeof(a): " << l << endl;
	cout << "sizeof(a[0]): " << m << endl;

	int n = sizeof(a) / sizeof(a[0]);
	cout << "sizeof(a) / sizeof(a[0]): " << n << endl;

	// insert the keys into the hash table
	Hash h(7); // count of buckets in hash table
	
	for (int i = 0; i < n; i++)
		h.insertItem(a[i]);

	h.displayHash();
	cout << endl;

	// delete 12 from hash table
	h.deleteItem(15);
	h.deleteItem(15);
	h.deleteItem(15);
	h.deleteItem(15);

	// display the Hash table
	h.displayHash();

	cin.get();

	return 0;


}
