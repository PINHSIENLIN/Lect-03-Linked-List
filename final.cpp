// Please design a program that allows users to enter a number n
// The program can list the factors of n and determine whether the factors are prime numbers (prime)
// And put its factors into the linked list so that the user can select
// 1.print out sequentially
// 2.Print out in reverse order
// 3.leave

#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
        int data;
        char is_prime;
        Node* next;
    // Constructor to initialize data and next pointer (Member Initialization)
    Node(int value, char prime) : data(value), is_prime(prime), next(nullptr) {}
};

class LinkedList {
    private:
    Node* head;  // Points to the first node in the list

    public:
    // Constructor to initialize an empty linked list
    LinkedList() : head(nullptr){}

    void insertAtEnd(int value, char prime) {
        Node* newNode = new Node(value, prime);
        
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
            cout << current->data << " " << current->is_prime << endl;
            current = current->next;
        }
    }

    void displayReverse(Node* current){
        if (current == nullptr)
            return;
        
        displayReverse(current->next);
        cout << current->data << " " << current->is_prime << endl;
    }

    void displayReverse(){
        displayReverse(head);
    }
};

char isPrime(int number) {
    // Handle cases where number is less than 2
    if (number < 2) {
        return 'N';
    }

    // Check for divisibility from 2 to the square root of the number
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return 'N'; // Number is divisible, not prime
        }
    }

    return 'P'; // Number is prime
}

int main() {
    
    int num,choice;
    cin >> num;

    // Create a linked list
    LinkedList myList;
    
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0){
            cout << i << " ";
            myList.insertAtEnd(i,isPrime(i));     
        }
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