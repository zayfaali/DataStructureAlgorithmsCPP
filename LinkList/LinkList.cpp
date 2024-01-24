#include <iostream>
using namespace std;

class Node {
  public:
  int val;
  Node* next;

  Node(int data){
    this-> val = data;
    this->next = NULL;
  }
};

void InsertAtHead(Node* &head , int data){
  Node* temp = new Node(data);
  temp -> next = head;
  head = temp;
}

void insertAtTail(Node* &head, int data){
  if(head == NULL){
    InsertAtHead(head, data);
    return;
  }

    Node* n = new Node(data);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}void insertAtPosition(Node* &head, int data, int position) {
    if (position < 1) {
        cout << "Error: Invalid position. Position should be greater than or equal to 1." << endl;
        return;
    }

    Node* newNode = new Node(data);

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Error: Invalid position. Position exceeds the length of the linked list." << endl;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}



void deleteAtPosition(Node* &head, int position) {
    if (position < 1) {
        cout << "Error: Invalid position. Position should be greater than or equal to 1." << endl;
        return;
    }

    if (head == NULL) {
        cout << "Error: Linked list is empty. Cannot delete from an empty list." << endl;
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    int i = 1;

    while (i < position - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp->next == NULL) {
        cout << "Error: Invalid position. Position exceeds the length of the linked list." << endl;
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


int main(){
  Node* head = NULL;

    // Example: Insert nodes into the linked list
    for (int i = 1; i <= 5; i++) {
        Node* newNode = new Node(i);
        newNode->next = head;
        head = newNode;
    }

    cout << "Linked List before deletion: ";
    displayList(head);

    // Example: Delete node at a position specified by the user
    int position;
    cout << "Enter the position to delete: ";
    cin >> position;

    deleteAtPosition(head, position);

    cout << "Linked List after deletion: ";
    displayList(head);

    return 0;
}

