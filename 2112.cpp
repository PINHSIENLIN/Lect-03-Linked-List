// Integrate linked list functionality into one program
// Function
// Enter ‘i’ to add a new node at the end of the list. You can enter your name, email, and phone number.
// Enter 'd' followed by a name to delete those with the same name in the node 
// (assuming that the entered name will not be repeated). Delete ok will be printed after successful deletion. 
// If there is no data with the same name, Can not delete will be printed.
// Enter 'f' followed by a name to print out found xx and data for nodes with the same name. 
// If not found, print out Not found.
// Enter ‘l’ to print out the contents of all nodes in the list
// Type 'q' to exit the program

#include <iostream>
#include <string>
using namespace std;

struct Node {
  string name;
  string email;
  int phone;
  Node* next;
};

// Set Head Node* as Null to create an empty linked list
Node* head = NULL;

// Function to add data to the linked list
void insertAtEnd(string name, string email, int phone){
    Node* newNode = new Node;
    newNode->name = name;
    newNode->email = email;
    newNode->phone = phone;
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

// Function to find the name
Node* findName(Node* head, string target){
     Node* current = head;
     while (current->next != NULL){
        if(current->name == target){
            return current;
        }
        current = current->next;
     }
    return current;
}

// Deleting a node from a linked list involves three steps:

// 1.Locating the node to be deleted: Traverse the linked list until you find the node with the value you want to delete.

// 2.Updating the links: Once you have found the node to be deleted, you need to update the links of the surrounding nodes. 
// This involves setting the next pointer of the previous node to point to the next node of the node to be deleted.

// 3.Deallocating the memory: Finally, you need to free the memory that was allocated for the node to be deleted. 
// This is typically done using the delete operator in C++.

bool deleteNode(Node* head, string target){
    //  The prev pointer keeps track of the previous node
     Node* prev = NULL;
    //  The curr pointer keeps track of the current node
     Node* curr = head;
     // curr != NULL to check if the linked list is empty
     while (curr != NULL){
         if (curr->name == target){
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
            string name, email;
            int phone;
            cin >> name;
            cin >> email;
            cin >> phone;
            insertAtEnd(name,email,phone);
        }
        else if (choice == 'd'){
            string data;
            cin >> data;
            if (deleteNode(head,data)){
                cout << "Delete ok" << endl;
            } else {
                cout << "Can not delete" << endl;
            }
        }
        else if (choice == 'f'){
            string data;
            cin >> data;
            Node* temp = findName(head,data);
            if (findName(head,data) != NULL){;
               cout << "found " << endl;
               cout << temp->name << endl;
               cout << temp->email << endl;
               cout << temp->phone << endl;
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
                   cout << temp->name << endl;
                   cout << temp->email << endl;
                   cout << temp->phone << endl;
                   temp = temp->next;
                if (temp != NULL)
                   cout << endl;
            };
                   
        } 
        else if (choice == 'q')
           return 0;
    
    }

    return 0;
}