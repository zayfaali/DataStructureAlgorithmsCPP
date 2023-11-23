#include <iostream>
using namespace std;

int binarySearch(int arr[] , int size ,  int key){

int start = 0;
int end = size;

while (start <= end)
{
    int mid = (start + end)/2;

    if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid]>key)
    {
        end = mid - 1;
    }
    else {
        start = mid + 1;
    }
    
    
}

return -1;
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

     cout<<binarySearch(arr, size , 40)<<endl;

    return 0;
}