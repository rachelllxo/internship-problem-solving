#include <iostream>
using namespace std;

struct node {								//creating a node - that has a value stored and link node that points to next node
    int data;
    struct node* link;
};

struct node* head = NULL;					//declaring head as a global variable 

int insert(int data, int count) {				//inserting the values in a linked list 
    node* temp1 = new node();				//creating a new node called temp1
    temp1->data = data;						//setting temp's data to store the value
    temp1->link = NULL;						// setting temp's link to NULL so it doesn't move to the next

    if (count == 1) {						//checking if we are inserting at the beginning of the list							
        temp1->link = head;					//if inserted we Make the new node point to the current head of the list.
        head = temp1;						//updating the head pointer to the current node 
        return 0;
    }

    node* temp2 = head;						//we are creating another temp that points to the current head node
    for (int count1 = 0; count1 < count - 2; count1++) { //inserting from left to right 
        if (temp2 == NULL) {
            cout << "Position out of bounds!" << endl;
            return 0;
        }
        temp2 = temp2->link;
    }

    temp1->link = temp2->link;		//setting the temp1 link to temp2 link 
    temp2->link = temp1;
	return 0;			
}

int print() {						//printing the linked list
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << endl;
    return 0;
}

int reverse() {					//to reverse a linked list 
    node* prev = NULL;			//initializing all the nodes 
    node* current = head;
    node* next = NULL;

    while (current != NULL) {	//next is used to temporarily hold the next node during traversal
        next = current->link;	//flipping the link to the previous node 
        current->link = prev;
        prev = current;
        current = next;
    }

    head = prev;
	return 0;				//head is linked to the previous node which is NULL and the list is stopped 
} 

int main() {
    int counter;	//declaring a variable to get the elements until the size of the list
    int size;		//declaring a variable size to store the size 
    int elements;	//declaring a variable to store the elements 
    cout << "Enter no. of elements: ";
    cin >> size;
    cout << "Enter the elements: ";
    for (counter = 0; counter < size; counter++) {
        cin >> elements;
        insert(elements, counter + 1); 
    }
    reverse();
    cout << "Reversed List: ";
    print();

    return 0;
}
