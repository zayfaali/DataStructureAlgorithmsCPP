#include <iostream>
using namespace std;

class Node {
	public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
	this -> data = val;
	this -> next= NULL;
	this -> prev = NULL;	 
} };

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
	front = NULL;
	rear = NULL;
}

    void enqueue(int data) {
        Node* newNode = new Node(data);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }

        cout << "Enqueued: " << data << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty";
            return -1; 
        }

        Node* temp = front;
        int data = temp->data;

        if (front == rear) {
            front = rear = NULL;
        } else {
            front = front->next;
            front->prev = NULL;
        }

        delete temp;
        cout << "Dequeued: " << data << endl;

        return data;
    }

    bool isEmpty() {
        return front == NULL && rear == NULL;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty";
            return;
        }

        cout << "Queue elements: ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(40);
    q.enqueue(50);

    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();

    return 0; }