/* This algorithm is based on the sorting algorithm called Insertion Sort
  Time Complexity = O(n^2)
  space complexity = O(1)

*/ 
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int current = arr[i];
        int j = i - 1;

        while(arr[j] > current && j >=0  ) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = current;
    }
}

int main() {
    int size;
    cout<<"enter the size"<<endl;
    cin>>size;
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    cout<< " the sorted array is " << endl;
    insertionSort(arr, size);

    cout<<"Sorted Array is: ";
    for(int i = 0; i < size; i++) {
        cout<<arr[i]<<"  ";
    }
}
