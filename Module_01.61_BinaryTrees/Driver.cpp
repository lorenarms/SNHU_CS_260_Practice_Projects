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
	virtual ~BinaryTree();
	void Add(int key);
	void Remove(Node* curr, int key);
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

BinaryTree::~BinaryTree() {
	delete root;
}

void BinaryTree::Add(int key) {
	Node* curr = new Node();
	Node* toAdd = new Node();

	toAdd->key = key;
	toAdd->left = toAdd->right = NULL;

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

void BinaryTree::Remove(Node* curr, int key) {
	Node* parent = NULL;
	
	while (curr != NULL) {
		if (curr->key == key) {
			if (!curr->left && !curr->right) {
				if (!parent) {
					this->root = NULL;
				}
				else if (parent->left == curr) {
					parent->left = NULL;
				}
				else
					parent->right = NULL;
			}
			else if (curr->left && !curr->right) {
				if (!parent) {
					this->root = curr->left;
				}
				else if (parent->left == curr) {
					parent->left = curr->left;
				}
				else
					parent->right = curr->left;
			}
			else if (!curr->left && curr->right) {
				if (!parent) {
					this->root = curr->right;
				}
				else if (parent->left == curr) {
					parent->left = curr->right;
				}
				else
					parent->right = curr->right;
			}
			else {
				Node* succ = NULL;
				succ = curr->right;
				while (succ->left != NULL) {

					succ = succ->left;
				}
				curr->key = succ->key;
				Remove(curr->right, succ->key);
			}
			return;
		}
		else if (curr->key < key) {
			parent = curr;
			curr = curr->right;
		}
		else {
			parent = curr;
			curr = curr->left;
		}
	}
	return;
	
}

void BinaryTree::PrintTree(Node* curr) {
	if (curr == NULL) {
		return;
	}

	PrintTree(curr->left);
	if (!curr->left && !curr->right) {
		cout << "00" << " <-L- " << curr->key << " -R-> " << "00" << endl;
	}
	else if (!curr->left && curr->right) {
		cout << "00" << " <-L- " << curr->key << " -R-> " << curr->right->key << endl;
	}
	else if (curr->left && !curr->right) {
		cout << curr->left->key << " <-L- " << curr->key << " -R-> " << "00" << endl;
	}
	else {
		cout << curr->left->key << " <-L- " << curr->key << " -R-> " << curr->right->key << endl;
	}
	
	PrintTree(curr->right);

}





int main() {
	BinaryTree tree;

	tree.Add(12);
	tree.Add(11);
	tree.Add(15);
	tree.Add(5);
	tree.Add(56);
	tree.Add(3);
	tree.Add(7);
	tree.Add(13);
	tree.Add(14);

	tree.PrintTree(tree.GetRoot());
	int rt = tree.GetRoot()->key;
	cout << endl << "Root: " << rt << endl;

	tree.Remove(tree.GetRoot(), 12);
	tree.PrintTree(tree.GetRoot());
	rt = tree.GetRoot()->key;
	cout << endl << "Root: " << rt << endl;

	/*tree.Remove(tree.GetRoot(), 13);
	tree.PrintTree(tree.GetRoot());
	rt = tree.GetRoot()->key;
	cout << endl << "Root: " << rt << endl;*/

	cin.get();
	return 0;
}