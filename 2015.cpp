// Define a link sequence, store the sequentially input data in the dynamic data structure (ex: enter 5 entries), 
// and then print out the sequence data sequentially

#include <bits/stdc++.h>  // to include all the standard libraries
#include <iostream>
using namespace std;

// Creating a node bu using class
class Node {
    public:
    // 1. data item
    int data;
    // 2. An address of another node
    Node* next;
};

int main() {
// Set default of pointers in NULL
Node* head;
Node* one = NULL;
Node* two = NULL;
Node* three = NULL;
Node* four = NULL;
Node* five = NULL;

// Allocate memory
one = new Node();
two = new Node();
three = new Node();
four = new Node();
five = new Node();

// Assign value values
one->data = 1;
two->data = 2;
three->data = 3;
four->data = 4;
five->data = 5;

// Connect nodes
one->next = two;
two->next = three;
three->next = four;
four->next = five;
five->next = NULL;

head = one;
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
 return 0;
}