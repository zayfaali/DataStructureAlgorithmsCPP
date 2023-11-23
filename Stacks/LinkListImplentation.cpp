#include <bits/stdc++.h>
#include<iostream>
using namespace std;
 
// creating a linked list;
class Node {
public:
    int data;
    Node* next;
   
    // Constructor
    Node(int n)
    {
        this->data = n;
        this->next = NULL;
    }
};
 
class Stack {
public:
    Node* top;
 
    Stack() 
	{ 
	top = NULL; 
	}
 
    int push(int data)
    {
        Node* temp = new Node(data);
        temp->data = data;
        temp->next = top;
        top = temp;
    }
 
    bool isEmpty()
    {
        return top == NULL;
    }
 
    int peek()
    {

        if (!isEmpty())
            return top->data;
        else
            return -1;
    }

    int pop()
    {
        Node* temp;
        if (top == NULL) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else {
            temp = top;
            top = top->next;
            free(temp);
        }
    }

    int display()
    {
        Node* temp;
 
        if (top == NULL) {
            cout << "Stack Underflow";
            return -1;
        }
        else {
            temp = top;
            while (temp != NULL) {

                cout << temp->data<<"->";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }
    }
};
 
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40); 
    s.display();
    cout << "\nTop element is " << s.peek() << endl;
 
    s.pop();
 
    s.display();
 
    cout << "\nTop element is " << s.peek() << endl;
 
    return 0;
}