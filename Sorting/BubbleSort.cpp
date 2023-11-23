#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n) {

    for(int i = 0; i < n - 1; i++) {

        for(int j = 0; j < n - 1 - i; j++) {

            if(arr[j] > arr[j + 1]) {
                swap(arr[j] , arr[j+1]);
            }
        }
    }
}

int main(){
    
    int array[] = { 6 , 4 , 2 , 1, 3, 5, };

    int sizeOfArray = sizeof(array) / sizeof(array[0]);
    BubbleSort(array, sizeOfArray);

    cout<< " the sorted array is " << endl;

    for (int i = 0; i < sizeOfArray; i++)
    {
        cout<<array[i]<<endl;
    }
    

    return 0;
}