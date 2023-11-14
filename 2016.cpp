// Define a linked list, store the sequentially input data in the dynamic data structure (ex: enter 5 entries), 
// and then print out the sequence data in reverse order

#include <bits/stdc++.h>  // to include all the standard libraries
#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* head = NULL;

void insertNewNode(int data){
    Node* NewNode = new Node;
    NewNode->data = data;
    NewNode->next = NULL;

    if (head == NULL) {
        head = NewNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = NewNode;
    }
}

void printReverse(Node* head) {
    if (head == NULL) {
        return;
    }

    // Recursively print the rest of the list in reverse order
    printReverse(head->next);

    // Print the current node's data
    cout << head->data << " ";
}

int main(){

    for (int i = 0; i < 5; i++)
    {
        int data;
        cin >> data;
        insertNewNode(data);
    }
    
    printReverse(head);

    return 0;
}