#include <iostream>
using namespace std;

#define n 100

class Stack {
  int *arr;
  int top;

  public:
  Stack(){
     arr =  new int[n];
     top = -1;
  }

  void push(int data){
    if(top >= n-1){
        cout<<"Stack Overflow!"<<endl;
        return;
    }
    top++;
    arr[top] = data;
  }

  void pop(){
    if (top == -1)
    {   
        cout<<"Stack Underflow!"<<endl;
        return ;
    }
    cout<<"Element has been popped : "<<arr[top]<<endl;
    top--;
  }

  bool empty(){
    if (top == -1)
    {
        return true;
    }
    else return false;
  }

   int Top(){
        if (top == -1)
    {   
        cout<<"Stack Underflow!"<<endl;
        return -1 ;
    }

    return arr[top];
    }

    void display()
    {
        // looping over the stack conditionally
        if (top >= 0)
        {
            cout << "The Stack elements are: " << endl;
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << "  ";
            }
            cout << endl;
        }
        // if stack is empty then else block is executed
        else
        {
            cout << "[WARNING]Please fill the elements first" << endl;
            return;
        }
    }
};


int main(){
    Stack s;
    s.push(12);
    s.push(11);
    s.push(13);
    s.push(33);
    s.push(02);
   cout<< s.Top();
   s.display();
    return 0;
}