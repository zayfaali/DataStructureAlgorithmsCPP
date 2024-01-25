#include<iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  
  Node(int n)
    {
        this->data = n;
        this->next = NULL;
    }
};

class CircularQueue
{
public:

  Node * front, * rear;

    CircularQueue ()
  {
    front = rear = NULL;
    }  

  void enqueue (int data)
  {
    Node *temp = new Node (data);
    if (front == NULL)
      {
	front = rear = temp;
	rear->next = front;
      }  
    else
      {
	rear->next = temp;
	rear = temp;
	rear->next = front;
      }  
    cout << data << " has been enqueued." << endl;
  }

  void dequeue ()
  {
  	Node *temp = front;
    if (front == NULL)
      {
	cout << "Queue is empty." << endl;
      }
    else if (front == rear)
      {
	front = rear = NULL;
	delete temp;
      }
      
    else
      {
	front = front->next;
	rear->next = front;
	delete temp;

      }
  }

  void display ()
  {
    if (front == NULL)
      {
	cout << "Queue is empty." << endl;
      }
    else
      {
	Node *temp = front;
	cout << "Circular Queue: ";
	do
	  {
	    cout << temp->data << " ";
	    temp = temp->next;
	  }
	while (temp != front);
	cout << endl;
      }
  }
};

int main ()
{
  CircularQueue q;

  q.enqueue (10);
  q.enqueue (20);
  q.enqueue (30);
  q.enqueue (40);
  q.display ();

  q.dequeue ();
  q.dequeue ();
  q.display ();

  q.enqueue (50);
  q.enqueue (60);
  q.display ();

  return 0;
}