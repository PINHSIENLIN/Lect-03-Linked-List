// Integrate linked list functionality into one program
// Function
// Enter ‘i’ to add a new node at the end of the list. You can enter your name, email, and phone number.
// Enter 'd' followed by a name to delete those with the same name in the node 
// (assuming that the entered name will not be repeated). Delete ok will be printed after successful deletion. 
// If there is no data with the same name, Can not delete will be printed.
// Enter 'f' followed by a name to print out found xx and data for nodes with the same name. 
// If not found, print out Not found.
// Enter ‘l’ to print out the contents of all nodes in the list
// Type 'q' to exit the program

#include <iostream>
#include <string>
using namespace std;

struct Node {
  string name;
  string email;
  string phone;
  Node* next;
};

// Set Head Node* as Null to create an empty linked list
Node* head = NULL;

// Function to add data to the linked list
void insertAtEnd(string name, string email, string phone){
    Node* newNode = new Node;
    newNode->name = name;
    newNode->email = email;
    newNode->phone = phone;
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

// Function to find the name
Node* findName(Node* head, string target){
     Node* current = head;
     while (current->next != NULL){
        if(current->name == target){
            return current;
        }
        current = current->next;
     }
    return current;
}

// Deleting a node from a linked list involves three steps:

// 1.Locating the node to be deleted: Traverse the linked list until you find the node with the value you want to delete.

// 2.Updating the links: Once you have found the node to be deleted, you need to update the links of the surrounding nodes. 
// This involves setting the next pointer of the previous node to point to the next node of the node to be deleted.

// 3.Deallocating the memory: Finally, you need to free the memory that was allocated for the node to be deleted. 
// This is typically done using the delete operator in C++.

bool deleteNode(Node*& head, string target){
    //  The prev pointer keeps track of the previous node
     Node* prev = NULL;
    //  The curr pointer keeps track of the current node
     Node* curr = head;

    // Target is on the first node and curr != NULL to check if the linked list is empty
    if (curr != NULL && curr->name == target){
        head = curr->next;
        delete curr;
        return true;
    }     

    // Target is not on the first node
    while(curr != NULL && curr->name != target){
         prev = curr;
         curr = curr->next;
    }
    // If the node with the key is not found, do nothing
    if (curr == NULL){
        return false;
    }
    
    prev->next = curr->next;
    delete curr;
    return true;
}

int LengthofLinkedList(Node* head){
      int count = 0;
      Node* temp = head;
      while(temp != NULL){
        temp = temp->next;
        count++;
      }
      return count;
}

// Function which return string by concatenating it. 
string repeat(string s, int n) 
{ 
    // Copying given string to temporary string. 
    string s1 = s; 
  
    for (int i=1; i<n;i++) 
        s += s1; // Concatenating strings 
  
    return s; 
}


int main(){
    
    // Choice
    char choice;
    
    while (true)
    {
        cin >> choice;

        // if Choice = i, insert a data
        if (choice == 'i') {
            string name, email, phone;
            string s = "0";
            cin >> name;
            cin >> email;
            cin >> phone;
            int str_length = phone.length();

            if (phone.length() != 10){
                phone = repeat(s,10-str_length) + phone;
            }
            insertAtEnd(name,email,phone);
        }
        else if (choice == 'd'){
            string data;
            cin >> data;
            if (deleteNode(head,data)){
                cout << "Delete ok" << endl;
            } else {
                cout << "Can not delete" << endl;
            }
        }
        else if (choice == 'f'){
            string data;
            cin >> data;
            Node* temp = findName(head,data);
            if (findName(head,data) != NULL){;
               cout << "found" << endl;
               cout << temp->name << endl;
               cout << temp->email << endl;
               cout << temp->phone << endl;
               cout << endl;
            } else {
               cout << "Not found" << endl;
            }
        }
        else if (choice == 'g'){
              
              cout << LengthofLinkedList(head) << endl;
        }
        else if (choice == 'l'){
             Node* temp = head;
            while (temp != NULL) {
                   cout << temp->name << endl;
                   cout << temp->email << endl;
                   cout << temp->phone << endl;
                   temp = temp->next;
                   cout << endl;
            };
                   
        } 
        else if (choice == 'q')
           return 0;
    
    }

    return 0;
}