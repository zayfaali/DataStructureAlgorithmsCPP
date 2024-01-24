#include <iostream>
using namespace std;

// Node class for creating linked list nodes
class Node {
public:
  int data;
  Node* next;

  Node(int value) {
    data = value;
    next = NULL;
  }
};

// Queue class
class Queue {
public:
  Node* front;
  Node* rear;

  Queue() {
    front = NULL;
    rear = NULL;
  }

  // Function to check if the queue is empty
  bool isEmpty() {
    return front == NULL;
  }

  // Function to enqueue an element
  void enqueue(int value) {
    Node* newNode = new Node(value);

    if (isEmpty()) {
      front = newNode;
      rear = newNode;
    } else {
      rear->next = newNode;
      rear = newNode;
    }

    cout << value << " enqueued to the queue." << endl;
  }

  // Function to dequeue an element
  void dequeue() {
    if (isEmpty()) {
      cout << "Queue is empty. Cannot dequeue." << endl;
      return;
    }

    Node* temp = front;
    front = front->next;

    if (front == NULL) {
      rear = NULL;
    }

    cout << temp->data << " dequeued from the queue." << endl;
    delete temp;
  }

  // Function to get the front element of the queue
  int getFront() {
    if (isEmpty()) {
      cout << "Queue is empty." << endl;
      return -1;
    }

    return front->data;
  }

  // Function to get the rear element of the queue
  int getRear() {
    if (isEmpty()) {
      cout << "Queue is empty." << endl;
      return -1;
    }

    return rear->data;
  }

  void displayQueue(){
  if(front == NULL){
    cout << endl;
    return;
  }

  Node* temp = front;
  while(temp != NULL){
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout<<"NULL"<<endl;
}

};


int main() {
  Queue queue;

  queue.enqueue(10);
  queue.enqueue(20);
  queue.enqueue(30);

  queue.displayQueue();

  cout << "Front element: " << queue.getFront() << endl;
  cout << "Rear element: " << queue.getRear() << endl;

  queue.dequeue();
  queue.dequeue();

  queue.displayQueue();
  
  cout << "Front element: " << queue.getFront() << endl;
  cout << "Rear element: " << queue.getRear() << endl;

  return 0;
}
