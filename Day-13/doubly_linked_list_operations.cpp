#include<iostream>
using namespace std;

struct node {			//a node structure that contains the data part, pointer that points to the previous node and the next node
	int data;
	node* prev;
	node* next;
};

node* head = NULL;

//inserts a node at the end of the linked list
int insert_atTheEnd(int value) {
	node* new_node = new node();		//new node is created 
	new_node->data = value; 			//value stores in the data part
	new_node->next = NULL;
	new_node->prev = NULL;

	if (head == NULL) {				//creates a node if the list is empty 
		head = new_node;
		return 0;
	}
	else {							//links the new node if the head is already pointing to a node 
		node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new_node;
		new_node->prev = temp;		//the previous pointer of the new node stores the memory address of the previous node  
		return 0;
	}
}

//inserts a node at the beginning of the linked list
int Insert_atBeginning(int value) {
	cout << "Enter a value to insert at the beginning: ";
	cin >> value;
	node* inserting_node = new node();
	inserting_node->data = value;
	inserting_node->next = NULL;
	inserting_node->prev = NULL;			//previous node's address is NULL as it is inserted at the beginning 

	if (head == NULL) {
		head = inserting_node;
		return 0;
	}
	else {
		inserting_node->next = head; // stores the address of the next node which is the first node that the head was pointing
		head->prev = inserting_node; // stores the new node's address to the previous part of the first node. 
		head = inserting_node;
		return 0;
	}
}

//inserts a node at a specific position
int Insert_atPosition(int value, int position) {
	cout << "Enter the position: ";
	cin >> position;
	cout << "Enter the value: ";
	cin >> value;

	node* inserting_node = new node();
	inserting_node->data = value;
	inserting_node->next = NULL;
	inserting_node->prev = NULL;

	if (position == 1) {					//if the position is 1, then we create a new node point the head to the new node. 
		if (head == NULL) {
			head = inserting_node;
		}
		else {
			inserting_node->next = head;
			head->prev = inserting_node;
			head = inserting_node;
		}
		return 0;
	}
	else {
		node* temp = head;
		int count;
		for (count = 1; count < position - 1 && temp != NULL; count++) {
			temp = temp->next;
		}
		if (temp == NULL) {
			cout << "The position is out of bounds.";
			delete inserting_node;
			return 0;
		}
		inserting_node->next = temp->next;
		inserting_node->prev = temp;
		if (temp->next != NULL) {
			temp->next->prev = inserting_node;
		}
		temp->next = inserting_node;
		return 0;
	}
}

//deletes a node from the given position
int delete_node(int deleteNode) {
	cout << "Enter the position of the node to delete: ";
	cin >> deleteNode;

	if (head == NULL) {
		return 0;
	}

	node* temp = head;
	int count;
	for (count = 1; count < deleteNode && temp != NULL; count++) {
		temp = temp->next;
	}

	//if the position is out of range
	if (temp == NULL) {
		cout << "Position out of range.\n";
		return 0;
	}

	// Update the previous node's next pointer
	if (temp->prev != NULL) {
		temp->prev->next = temp->next;
	}
	else {
		// If the node to be deleted is the head node
		head = temp->next;
	}

	// Update the next node's prev pointer
	if (temp->next != NULL) {
		temp->next->prev = temp->prev;
	}

	// Deallocate memory for the deleted node
	delete temp;
	return 0;
}

//reverses the doubly linked list
int reverse_Linkedlist(int value) {
	node* temp = head;
	node* prev_node = NULL;

	while (temp != NULL) {
		// Swap next and prev
		node* next_node = temp->next;
		temp->next = temp->prev;
		temp->prev = next_node;
		prev_node = temp;
		temp = next_node;
	}
	head = prev_node; // update head to the last node
	return 0;
}

//displays the entire linked list
int display_linkedList(int value) {
	if (head == NULL) {					//displays "the list is empty" if the head is NULL (does not point to the node)
		cout << "The list is empty\n";
	}
	else {
		node* temp = head;					//displays if the list is not empty
		cout << "Doubly Linked List: ";		//traverses from where the head is pointing (from the first node)
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	return 0;
}

int main() {
	int value;
	int choice;

	while (true) {
		cout << "\nChoose any one:\n";
		cout << "1. Insert node at the end\n";
		cout << "2. Insert node at the beginning\n";
		cout << "3. Insert node at a specific position\n";
		cout << "4. Delete a node\n";
		cout << "5. Display the linked list\n";
		cout << "6. Reverse the linked list\n";
		cout << "7. Exit\n";
		cin >> choice;

		if (choice == 1) {
			cout << "Enter value to insert at end: ";
			cin >> value;
			insert_atTheEnd(value);
		}
		else if (choice == 2) {
			Insert_atBeginning(value);
		}
		else if (choice == 3) {
			Insert_atPosition(value, 0);
		}
		else if (choice == 4) {
			delete_node(0);
		}
		else if (choice == 5) {
			display_linkedList(0);
		}
		else if (choice == 6) {
			reverse_Linkedlist(0);
		}
		else if (choice == 7) {
			cout << "Exiting...\n";
			return 0;
		}
		else {
			cout << "Invalid choice. Please try again.\n";
		}
	}
}
