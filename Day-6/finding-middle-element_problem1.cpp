#include <iostream>
using namespace std;
struct node;				//globally declaring the node
node* head_node = NULL;		//globally declaring the head_node as NULL as it is empty now
node* pointer1 = NULL;		//pointer1 is NULL 
node* pointer2 = NULL;		//pointer2 is NULL
struct node {				
							//creating a node with data node and address of the next node
    int data_node;
    node* next_node;
	node(int value);		//the node takes in the input values 
};


node::node(int value) {  	//creating a constructor outside the node
    data_node = value;		// the data node now stores the value
    next_node = nullptr;	//the next node points to NULL

    if (head_node == NULL) { // if the head node is empty, the head node stores the current node
        head_node = this;
    } else {				
        node* temp = head_node;	//else it stores the head_node's address within the temporary node
        while (temp->next_node != NULL) { 
            temp = temp->next_node;
        }
        temp->next_node = this;  //if the temporary node has an address then it stores the current node
    }
}


int find_middle_element() { //finding the middle element in the linked list 
    pointer1 = head_node; //pointing both the pointer nodes to the head node 
    pointer2 = head_node;

    while (pointer2 != NULL && pointer2->next_node != NULL) { 
        pointer1 = pointer1->next_node; //first pointer traverses from the first element
        pointer2 = pointer2->next_node->next_node; //the second pointer traverses after two elements 
    }
	if (pointer1 != NULL){ 							// if the pointer1 is empty then return it's value
    return  pointer1->data_node;
}

}

int main() {
    int data; //variable to store the elements 
    cout << "Enter elements:" << endl;

    while (cin >> data) {
        new node(data);
    }

    int middle = find_middle_element(); //calling the function to find the middle element 
    cout << "Middle element is: " << middle << endl;

    return 0;
}
