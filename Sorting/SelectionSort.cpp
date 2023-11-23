#include <iostream>
using namespace std;


void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
       
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[j] , arr[i]);
            }
        }
    }
}

int main(){
        
    int size;
    cout<<"enter the size"<<endl;
    cin>>size;
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    cout<< " the sorted array is " << endl;
    
    SelectionSort(arr , size);

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<endl;
    }
    
    return 0;
}