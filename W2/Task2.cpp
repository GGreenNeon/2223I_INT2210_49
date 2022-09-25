#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

Node* newNode (int data) {
	// allocating space
	Node* temp = new Node ();

	// inserting the required data
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void printList (Node* n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

int ListSize = 0;

void insertNodeAt (Node** n, int pos, int value) {
    do {
	    if (pos == 0) {
		    // adding Node at required position
		    Node* temp = newNode(value);

		    // Making the new Node to point to
		    // the old Node at the same position
		    temp->next = *n;

		    // Changing the pointer of the Node previous
		    // to the old Node to point to the new Node
		    *n = temp;
	    }
	    else {
            // Assign double pointer variable to point to the
	        // pointer pointing to the address of next Node
            n = & (*n)->next;
        }
	} while (pos--);
	ListSize++;
}

// Given a reference (pointer to pointer) to
// the head of a list and a position, deletes
// the node at the given position
void deleteNodeAt (Node** head_ref, int pos) {
  
    // If linked list is empty
    if (*head_ref == NULL)
        return;
  
    // Store head node
    Node* temp = *head_ref;
  
    // If head needs to be removed
    if (pos == 0) {
  
        // Change head
        *head_ref = temp->next;
  
        // Free old head
        free (temp);
        return;
    }
  
    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < pos - 2; i++)
        temp = temp->next;
  
    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;
  
    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    Node* next = temp->next->next;
  
    // Unlink the node from linked list
    free (temp->next); // Free memory
  
    // Unlink the deleted node from list
    temp->next = next;
}

int main () {
    Node* head = NULL;

    int n;
    cin >> n;
    string command;
    int posn, value;
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "insert") {
            cin >> posn >> value;
            insertNodeAt (&head, posn, value);
        }
        if (command == "delete") {
            cin >> posn;
            deleteNodeAt (&head, posn);
        }
    }
    
    printList (head);
    return 0;
}