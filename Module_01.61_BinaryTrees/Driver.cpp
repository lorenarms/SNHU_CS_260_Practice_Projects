#include <iostream>

using namespace std;

class BinaryTree {
	class Node {
	public:
		int key;
		Node* left;
		Node* right;
	};
	Node* root;

public:
	BinaryTree();
	//virtual ~BinaryTree();
	void Append(int key);
	void Add(int key);
	void Remove(int key);
	int Search(int key);
	void PrintTree(Node* curr);
	int Size();
	Node* GetRoot() {
		return this->root;
	}


};

BinaryTree::BinaryTree() {
	root = NULL;

}



void BinaryTree::Add(int key) {
	Node* curr = new Node();
	Node* toAdd = new Node();

	toAdd->key = key;
	toAdd->left = NULL;
	toAdd->right = NULL;

	if (this->root == NULL) {
		this->root = toAdd;
		return;
	}
	else {
		curr = this->root;
		while (curr != NULL) {
			if (toAdd->key < curr->key) {
				if (curr->left == NULL) {
					curr->left = toAdd;
					return;
				}
				else {
					curr = curr->left;
				}
			}
			else {
				if (curr->right == NULL) {
					curr->right = toAdd;
					return;
				}
				else {
					curr = curr->right;
				}

			}
		}

		
	}

}

void BinaryTree::PrintTree(Node* curr) {
	if (curr == NULL) {
		return;
	}

	PrintTree(curr->left);
	cout << curr->key << endl;
	PrintTree(curr->right);

}





int main() {
	BinaryTree tree;

	tree.Add(12);
	tree.Add(11);
	tree.Add(13);
	tree.Add(5);
	tree.Add(56);
	tree.Add(3);

	tree.PrintTree(tree.GetRoot());


	cin.get();
	return 0;
}