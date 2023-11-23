#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int val){
      Node* n = new Node(val);
      n->next = head;
      head = n;
}

void insertAtTail(Node* &head,int data){
    Node* n = new Node(data);
    if(head == NULL){
        head = n;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void deleteAtHead(Node* &head){
    Node* toDelete = head;
    head = head->next;

    delete toDelete;
}

void deleteAtTail(Node* &head, int val){
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    else if(head->next == NULL){
        cout<<"List is now empty"<<endl;
        deleteAtHead(head);
        return;
    }

  Node* temp = head;
  while(temp->next->data != val){
    temp = temp->next;
  }

  Node* toDelete = temp ->next;
  temp->next = temp->next->next;

  delete toDelete;
}

void display(Node* head){
    Node* temp = head;

    while (temp !=NULL )
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}



int main(){
    Node* n1 = NULL;        
    insertAtTail(n1,11);
    insertAtTail(n1,12);
    insertAtTail(n1,13);
    display(n1);
    insertAtHead(n1,14);
    insertAtHead(n1,15);
    display(n1);
    deleteAtHead(n1);
     display(n1);
     deleteAtTail(n1,13);
     display(n1);
    return 0;
}