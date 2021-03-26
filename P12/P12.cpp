#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
  
// A doubly linked list node
struct Node {
   string data;
   struct Node* next;
   struct Node* prev;
};

bool checkAppointment(struct Node** head, string d, int t){
    struct Node* temp = new Node;
    temp->next = (*head);

    string check = "Day: "; 
    check += d;
    check += ", time: " + t;
    if (temp->data == check) {
        return true;
    }
    else if(temp->next = NULL){
        return false;
    }
    else{
        temp = temp->next;
    }

}

void makeAppointment(struct Node* prev_node, string d, int t, string new_data)
{
   //check if prev node is null
   if (prev_node == NULL) {
   cout<<"Previous node is required , it cannot be NULL";
   return;
}
   //allocate memory for new node
   struct Node* newNode = new Node;

   string appoint = "Day: "; 
    appoint += d;
    appoint += ", time: " + t;

    new_data = appoint;
    stringstream maybe(new_data);
    string substr;

   //assign data to new node
   newNode->data = new_data;
  
  getline(maybe, substr, ',');
  if(substr.substr(5) == new_data.substr(5)){
      //set next of newnode to next of prev node
      newNode->next = prev_node->next;

      //set next of prev node to newnode
        prev_node->next = newNode;

     //now set prev of newnode to prev node
   newNode->prev = prev_node;
  }
  
   //set prev of new node's next to newnode
   if (newNode->next != NULL)
   newNode->next->prev = newNode;
}
  

//main program
int main() {
   // Start with the empty list
   struct Node* head = NULL;
   string day;
   int timeOfDay;
   cout << "Enter Day of Appointment: " << endl;
   cin >> day;
   cout << "Enter Time of Appointment: " << endl;
   cin >> timeOfDay;

    string appoint = "Day: "; 
    appoint += day;
    appoint += ", time: " + timeOfDay;

   if(checkAppointment(&head, day, timeOfDay)){
       cout << "Appointment already there. Next appointment is: " << endl;
   }
   else{
       makeAppointment(head->next, day, timeOfDay, appoint);
   }
   
   return 0;
}