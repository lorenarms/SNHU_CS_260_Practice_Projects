#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
	int data;
	Node* next;
};

void printList(Node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


void main() {

    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // allocate 3 nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1; // assign data in first node
    head->next = second; // Link first node with the second node

    // assign data to second node
    second->data = 2;

    // Link second node with the third node
    second->next = third;

    third->data = 3; // assign data to third node
    third->next = NULL;

    Node* fourth = NULL;
    fourth = new Node();
    third->next = fourth;
    fourth->data = 45;
    fourth->next = NULL;

    printList(head);
    cin.get();


    Node* fifth = NULL;
    Node* tmp = NULL;
    fifth = new Node();
    fifth->data = 7;
    tmp = new Node();
    tmp = head;
    head = fifth;
    fifth = tmp;
    head->next = fifth;
    fifth->next = second;

    printList(head);

    

	
	cin.get();

}