// Define a linked list, store the sequentially input data in the dynamic data structure (ex: enter 5 entries), 
// and then print out the sequence data sequentially

#include <bits/stdc++.h>  // to include all the standard libraries
#include <iostream>
using namespace std;


// The 'Node' UDT has two members:
// data: An integer variable that stores the actual data associated with the node.
// next: A pointer to another 'Node' structure. 
// This pointer is used to link nodes together, forming the linked list.
// The 'next' pointer is crucial for the operation of a linked list. 
// It allows each node to reference the next node in the sequence, enabling traversal and manipulation of the list.
struct Node {
  int data;
  Node* next;
};

// The statement Node* head = NULL; declares a global variable named 'head' of type 'Node*'. 
// This variable acts as a reference to the first node in the linked list. 
// Initially, it is set to NULL, indicating an empty list
Node* head = NULL;

void insertAtEnd(int data) {
  // Creating a new node and setting its data and next pointer to NULL
  // syntax: pointer-variable = new data-type;
  // https://eng.libretexts.org/Courses/Delta_College/C_-_Data_Structures/03%3A_Arrays/3.01%3A_Dynamic_memory_allocation
  Node* newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;
  
  // if the head pointer of the linked list is NULL. 
  // If it is, then the linked list is empty and the head pointer should be set to the new node
  if (head == NULL) {
    head = newNode;
  } 
  // This code traverses the linked list until the last node is reached. 
  // The last node is the node whose next pointer is NULL. 
  // The temp variable is used to keep track of the current node in the linked list
  else {
    Node* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    // This code sets the next pointer of the last node to the new node. 
    // This makes the new node the last node in the linked list
    temp->next = newNode;
  }
}

int main() {

  for (int i = 0; i < 5; i++) {
    int data;
    cin >> data;
    insertAtEnd(data);
  }
  
  Node* temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  };

  return 0;
}