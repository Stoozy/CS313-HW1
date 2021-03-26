#include<iostream>
#include<time.h>
using namespace std;

class Node {
public:
	Node* next;
	int data;
};


void swap(Node* x, Node* y) {
	int temp = x->data;  //Creates a temp to store the data of the list
	x->data = y->data;   //Swaps the data in the list
	y->data = temp;		 
}

void insertFirst(Node** head, int data) {
	Node* newNode;			//Creates a new node
	newNode = new Node();   
	newNode->data = data;	//Set the value of the new node to data
	newNode->next = *head;  //Connect new node to the head node
	*head = newNode;		//The new node now becomes the head
}

void LL_print(Node* current) {
	while (current != NULL) {         //Do the while loop until node is NULL
		cout << current->data << " "; //Print out the current value of the node
		current = current->next;	  //Set current to the next spot of the node
	}
}

void oddEven(Node** head) {
	Node* odd = NULL; //Making a new list for Odd numbers
	Node* even = NULL;//Making a new list for Even numbers
	Node* current = *head; //Node to travel through head list

	while (current != NULL) {
		int num = current->data;
		if ((current->data) % 2 != 0) {    //If num is odd, then push it in odd list
			insertFirst(&odd, num);
		}
		else {
			insertFirst(&even, num);              //If num is even, then push it in even list
		}
		current = current->next;           //Go to next node in current

	}
	//This part is where the two listed are combined
	*head = odd;	
	current = odd;  //Current now points to first entry of odd   
	while (current->next != NULL) {
		current = current->next;  //Go to next node in current
	}
	current->next = even;    //Current now points to start of even, combing the two linked list
}








int main() {
	srand(time(NULL));
	Node* start = NULL;
	int size = 10;
	for (int i = 0; i < size; i++)
	{
		insertFirst(&start, rand() % size + 1);
	}
	cout << "Unsorted Linked list:" << endl;
	LL_print(start);
	cout << endl;
	cout << "Odd then even sorted Linked list:";
	oddEven(&start);
	cout << endl;
	LL_print(start);
}