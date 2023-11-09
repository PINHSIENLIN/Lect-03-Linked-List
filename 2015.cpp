// Define a link sequence, store the sequentially input data in the dynamic data structure (ex: enter 5 entries), 
// and then print out the sequence data sequentially
// https://www.softwaretestinghelp.com/linked-list/
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
  Node* newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    Node* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
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