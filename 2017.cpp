// Define a linked list, store the sequentially input data in the dynamic data structure (enter -1 to end), 
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
  } 

  else {
    Node* temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

int main() {

    while (true) {
    int data;
    cin >> data;
    insertAtEnd(data);
    if (data == -1)
        break;
    }
 
  
  Node* temp = head;
  while (temp->next != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  };

  return 0;
}