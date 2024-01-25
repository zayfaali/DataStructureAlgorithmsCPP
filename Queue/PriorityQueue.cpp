#include <iostream>
using namespace std;
class Node {
	public:
    int data;
    int priority;
    Node* next;

    Node(int val, int prio) {
    this -> data = val;
	this -> priority = prio;
	this -> next = NULL;	
	}
};
class PriorityQueue {
public:
    Node* front;
    
    PriorityQueue()
	{
	front = NULL;		
	}

    void enqueue(int data, int priority) {
        Node* newNode = new Node(data, priority);
		// If the queue is empty or the new node has higher priority than the front
        if (front == NULL || priority > front->priority) {
            newNode->next = front;
            front = newNode;
        } 
		else {
            Node* temp = front;

            // Find the position to insert the new node
            while (temp->next != NULL && temp->next->priority >= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue is empty";
            return -1; 
        }

        Node* temp = front;
        int data = temp->data;
        front = front->next;
        delete temp;

        return data;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void display() {
        if (isEmpty()) {
            cout << "Priority Queue is empty.\n";
            return;
        }

        cout << "Priority Queue elements: ";
        Node* temp = front;
        while (temp != NULL) {
            cout << "(" << temp->data << ", " << temp->priority << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.enqueue(10, 2);
    pq.enqueue(20, 1);
    pq.enqueue(30, 3);

    pq.display();

    cout << "Dequeue: " << pq.dequeue() << endl;

    pq.display();

    return 0;
}