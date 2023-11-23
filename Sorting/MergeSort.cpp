// idea : divide the array into two parts , sort the left part , sort the right part and merge the array
// TimeComplexity : O(N log N)
// Space Complexity : O(N)

#include <iostream>
using namespace std;

void merge( int arr[] , int l , int mid , int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }

    int i=0;
    int j=0;
    int k=l;

    while( i < n1 && j < n2){
        if(a[i] < b[j]){
            arr[k] = a[i];
            k++ ; i++;
        }
        else{
            arr[k]=b[j];
            k++; j++;
        }
    }

    while(i < n1){
        arr[k] = a[i];
        k++; i++;
    }

    while(j < n2){
        arr[k] = b[j];
        k++; j++;
    }
    
}

void mergeSort(int arr[] , int l ,int r){
    if(l<r){
        int mid= (l + r) / 2;


        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1 , r);
        merge(arr , l , mid, r);
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
   
    mergeSort(arr, 0, size - 1);

    cout<<"Sorted Array is: ";
    for(int i = 0; i < size; i++) {
        cout<<arr[i]<<"  ";
    }
    return 0;
}