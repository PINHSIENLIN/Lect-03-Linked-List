// Please design a program that allows users to enter a number n
// The program can list the factors of n and determine whether the factors are prime numbers (prime)
// And put its factors into the linked list so that the user can select
// 1.print out sequentially
// 2.Print out in reverse order
// 3.leave

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    // Constructor to initialize data and next pointer (Member Initialization)
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
    private:
    Node* head;  // Points to the first node in the list

    public:
    // Constructor to initialize an empty linked list
    LinkedList() : head(nullptr){}

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        
        // If the list is empty, make the new node the head
        if (head == nullptr){
            head = newNode;
            return;
        }

        Node* current = head;
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    void displayReverse(Node* current){
        if (current == nullptr)
            return;
        
        displayReverse(current->next);
        cout << current->data << endl;
    }

    void displayReverse(){
        displayReverse(head);
    }

};

int main() {
    
    int num,choice;
    cin >> num;

    // Create a linked list
    LinkedList myList;
    
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0){
            cout << i << " ";
            myList.insertAtEnd(i);
        }
        
        // Tell if a prime
    }
    cout << endl;

    while (true){
        cin >> choice;
        if (choice == 1){ 
            myList.display();
        } 
        else if (choice == 2){
            myList.displayReverse();
        } 
        else if (choice == 3)
            return 0;
    }

    return 0;
}