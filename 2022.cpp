// Integrate link string functionality into one program
// Function
// Enter 'i', then enter a number to insert the data in the node as value at the end of the string
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

int main(){
    
    //Size of Array
    int n = 0;
    
    // Declare an array
    int arr[n];

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
            n++;
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