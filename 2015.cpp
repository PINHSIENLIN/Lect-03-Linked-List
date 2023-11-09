// Define a link sequence, store the sequentially input data in the dynamic data structure (ex: enter 5 entries), 
// and then print out the sequence data sequentially

#include <bits/stdc++.h>  // to include all the standard libraries
#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

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

void printLinkedList() {
  Node* temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {

  for (int i = 0; i < 5; i++) {
    int data;
    cin >> data;
    insertAtEnd(data);
  }
  
  printLinkedList();

  return 0;
}