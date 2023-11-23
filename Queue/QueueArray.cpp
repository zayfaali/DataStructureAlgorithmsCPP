#include <iostream>
using namespace std;

// write simple implentation of queue using array
class Queue{
    int *arr;
    int front;
    int back;
    int size;
    int capacity;

    public:
    Queue(int cap){
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        back = 0;
        size = 0;
    }

    bool isEmpty(){
        return size == 0;
    }

    bool isFull(){
        return size == capacity;
    }

    void enqueue(int data){
        if(isFull()){
            cout<<"Queue is Full"<<endl;
            return;
        }
        arr[back] = data;
        back = (back + 1) % capacity;
        size++;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    int getFront(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return arr[front];
    }

    int getBack(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return arr[back];
    }

    int getSize(){
        return size;
    }
};

int main(){
    
    return 0;
}