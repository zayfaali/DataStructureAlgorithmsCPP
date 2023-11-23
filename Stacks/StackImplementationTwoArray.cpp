#include <iostream>
using namespace std;

#define n 100

class TwoStack {
  int *arr;
  int top1;
  int top2;

  public:
  TwoStack(){
     arr =  new int[n];
     top1 = -1;
     top2 = n;
  }

    void push1(int data){
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = data;
        }
        else cout<<"Stack1 Overflow"<<endl;
    }

    void push2(int data){
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = data;
        }
        else cout<<"Stack2 Overflow"<<endl;
    }

    int pop1(int data){
        if (top1 > -1)
        {
        int popped = arr[top1];
        top1--;
        return popped;
        }
        else cout<<"Stack1 Underflow"<<endl;
        
    }

    int pop2(int data){
        if (top2 < n)
        {
        int popped = arr[top2];
        top2++;
        return popped;
        }
        else cout<<"Stack2 Underflow"<<endl;
        
    }

    void display1() {
        cout << "Stack 1: ";
        for (int i = top1; i >= 1; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void display2() {
        cout << "Stack 2: ";
        for (int i = top2; i <= n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


  void Top1() {
        if (top1 > -1) {
            cout << "Top of Stack 1: " << arr[top1] << endl;
        } else {
            cout << "Stack 1 is empty" << endl;
        }
    }

    void Top2() {
        if (top2 < n) {
            cout << "Top of Stack 2: " << arr[top2] << endl;
        } else {
            cout << "Stack 2 is empty" << endl;
        }
    }
};


int main() {
    TwoStack s;
    s.push1(12);
    s.push2(11);
    s.push1(13);
    s.push2(33);
    s.push1(2);

    s.display1(); // Display elements of stack 1
    s.display2(); // Display elements of stack 2

    s.Top1(); // Display top element of stack 1
    s.Top2(); // Display top element of stack 2

    return 0;
}