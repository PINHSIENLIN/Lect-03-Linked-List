// Integrate linked list functionality into one program
// Function
// Enter 'i', then enter a number to insert the data in the node as value at the end of the string
// Enter 'd' and then enter a number to delete the data in the node with the same value 
// (assuming that the entered value will not be repeated). After successful deletion, Delete ok will be printed. 
// If there is no data with the same value, Can will be printed. not delete
// Enter 'f' followed by a number to print found xx for data nodes with the same number. 
// If not found, Not found will be printed.
// Enter ‘g’ to display the current number of records
// Enter ‘l’ to print out the contents of all nodes in the series into one column. 
// There is a blank after each output, and a new line is required at the end.
// Type 'q' to exit the program

#include <iostream>
using namespace std;
#define N 1000

struct Node {
  int data;
  Node* next;
};

// Set Head Node* as Null to create an empty linked list
Node* head = NULL;

// Function to add data to the linked list
void insertAtEnd(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL){
        head = newNode;
    } 
    else {
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to find the number
bool findNumber(Node* head, int target){
     Node* current = head;
     while (current->next != NULL){
        if(current->data == target){
            return true;
        }
        current = current->next;
     }
     return false;
}

// Deleting a node from a linked list involves three steps:

// 1.Locating the node to be deleted: Traverse the linked list until you find the node with the value you want to delete.

// 2.Updating the links: Once you have found the node to be deleted, you need to update the links of the surrounding nodes. 
// This involves setting the next pointer of the previous node to point to the next node of the node to be deleted.

// 3.Deallocating the memory: Finally, you need to free the memory that was allocated for the node to be deleted. 
// This is typically done using the delete operator in C++.

bool deleteNode(Node* head, int target){
    //  The prev pointer keeps track of the previous node
     Node* prev = NULL;
    //  The curr pointer keeps track of the current node
     Node* curr = head;
     // curr != NULL to check if the linked list is empty
     while (curr != NULL){
         if (curr->data == target){
            // Case 1: Delete the head node
            if (prev == NULL){
            //  the head pointer is updated to point to the next node  
                head = curr->next;
            } else {
            // Case 2: traverses the linked list until it finds the node with the target value. 
            // It keeps track of the previous node so that it can update the links after deleting the target node
                prev->next = curr->next;
            }
        // deallocates the memory for the target node
        delete curr;
        return true;
        }
       prev = curr;
       curr = curr->next;
     }
     return false;
}

int LengthofLinkedList(Node* head){
      int count = 0;
      Node* temp = head;
      while(temp != NULL){
        temp = temp->next;
        count++;
      }
      return count;
}

int main(){
    
    // Choice
    char choice;
    
    while (true)
    {
        cin >> choice;

        // if Choice = i, insert a data
        if (choice == 'i') {
            int data;
            cin >> data;
            insertAtEnd(data);
        }
        else if (choice == 'd'){
            int data;
            cin >> data;
            if (deleteNode(head,data)){
                cout << "Delete ok" << endl;
            } else {
                cout << "Can not delete" << endl;
            }
        }
        else if (choice == 'f'){
            int data;
            cin >> data;
            if (findNumber(head,data)){
               cout << "found " << data << endl;
            } else {
               cout << "Not found" << endl;
            }
        }
        else if (choice == 'g'){
              
              cout << LengthofLinkedList(head) << endl;
        }
        else if (choice == 'l'){
             Node* temp = head;
            while (temp != NULL) {
                   cout << temp->data << " ";
                   temp = temp->next;
            };
            cout << endl;
        } 
        else if (choice == 'q')
           return 0;
    
    }

    return 0;
}