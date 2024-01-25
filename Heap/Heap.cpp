#include <iostream>
using namespace std;

class heap {
    public: 
        int arr[20];
        int size = 0;

        heap(){
            arr[0] = -1;
            size = 0;
        }

   	
	void insert(int val){
		size = size + 1;
		int index = size;
		arr[index] = val;
			
			while (index > 1){
				int parent = index / 2;
				if(arr[parent] < arr[index]){
					swap(arr[parent], arr[index]);
					index = parent;
				}
				else{
					return;
				}
			}	

    }

    void del(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }

        //step 1: put last node in first index
        arr[1] = arr[size];
        //step 2: remove last element;
        size--;

        // step 3: take root node to its correct position
        int index = 1;
        while(index <= size){
            int leftIndex = 2* index;
            int rightIndex = 2 * index + 1;

            if(leftIndex < size && arr[leftIndex] > arr[index]){
                swap(arr[leftIndex] , arr[index]);
                index = leftIndex;
            }

            else if(rightIndex < size && arr[rightIndex] > arr[index]){
                swap(arr[rightIndex] , arr[index]);
                index = rightIndex;
            }
            else {
                return;
            }
        }
    }
   void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
  
    if (left <= n && arr[left] > arr[largest])
      largest = left;
  
    if (right <= n && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(arr[i], arr[largest]);
      heapify(arr, n, largest);
    }
  }

  void heapSort(int arr[] , int n){

    int size = n;
    while (size > 1)
    {
        // step 1: swap
    swap( arr[1] , arr[n]);
    size--;

    //step 2: put the root in its correct position
    heapify(arr, size, 1);
    }
    
  }

    void print(){
        for(int i = 1; i <= size; i++){
            cout << arr[i] << " ";
        }cout<<endl;
    }
    
};
int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(56);
    h.insert(57);
    h.insert(58);

    h.print();
    h.del();
    h.print();

    int arr[7] = {-1, 1, 12, 9, 5, 6, 10};
	int n = 6;
	for (int i = n/2; i > 0; i--){
		h.heapify(arr, n, i);
	}
	cout<<"Print Array: ";
	for(int i = 1; i <= n; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;

        h.heapSort(arr,n);
	cout<<"Print Sorted Array: ";
	for(int i = 1; i <= n; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		
    return 0;
}