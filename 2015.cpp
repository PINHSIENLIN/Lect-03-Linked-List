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
    
    // Initialize head pointer as null
    Node* head = NULL;

    for (int i = 0; i < 5; i++)
    {
        // Create a new node by dynamic allocating memory
        Node* newNode = new Node;
        // Input data
        cin >> newNode->data;

        // Connect to next pointer
        newNode->next = head;

        // Update head to the new node
        head = newNode;
    }


  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
 return 0;
}