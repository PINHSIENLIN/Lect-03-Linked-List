// Define a link sequence, store the sequentially input data in the dynamic data structure (ex: enter 5 entries), 
// and then print out the sequence data sequentially

#include <bits/stdc++.h>  // to include all the standard libraries
#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

// Initialize head pointer as null
Node* head = NULL;

void insertAtEnd(int data) {
  // Creating a new node and setting its data and next pointer to NULL
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