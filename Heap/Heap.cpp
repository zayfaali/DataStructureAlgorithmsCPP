#include <iostream>
using namespace std;

class heap {
	
	public:
		int arr[20];
		int size;
	
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
            cout<<"nothing to delete ";
            return;
        }
        //step 1: put last element into first index
        arr[1]=arr[size];
        //step 2: remove last element 
        size--;
        //step 3:take root node to its correct position
        int i = 1;
   		while ( i <= size )
		{
      		int left=2*i;
      		int right=2*i+1;
      		if(left <= size && right<=size){
        		if (arr[left]>arr[right] && arr[left]>arr[i])
        		{
            	swap(arr[left],arr[i]);
            	i=left;
        		}
        		else if(arr[left]<arr[right] && arr[right]>arr[i]){
            	swap(arr[right],arr[i]);
            	i=right;
        		}
        		else{
            	return;
        		}   
      		}
      		else if(left<=size &&arr[left]>arr[i]){
        	swap(arr[left],arr[i]);
        	i=left;
      		}
      		else if(right<=size && arr[right]>arr[i]){
        	swap(arr[right],arr[i]);
        	i=right;
      		}
     		else{
        	return;
      		}
     		}   
    }

	void print(){
		for(int i = 1; i <= size; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
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


  	void heapSort(int arr[], int n) {
      int size = n;
      while(size > 1){
      	swap(arr[size], arr[1]);
      	size--;
	  
      heapify(arr, size, 1);
  		}    
  	}
	
};

int main(){
	heap Heap;
	Heap.insert(44);
	Heap.insert(42);
	Heap.insert(35);
	Heap.insert(33);
	Heap.insert(31);
	Heap.insert(19);
	Heap.insert(27);
	Heap.insert(10);
	Heap.insert(26);
	Heap.insert(14);
	Heap.print();
	
	Heap.del();
	Heap.print();
	
	int arr[7] = {-1, 1, 12, 9, 5, 6, 10};
	int n = 6;
	for (int i = n/2; i > 0; i--){
		Heap.heapify(arr, n, i);
	}
	cout<<"Print Array: ";
	for(int i = 1; i <= n; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;

		
	Heap.heapSort(arr,n);
	cout<<"Print Sorted Array: ";
	for(int i = 1; i <= n; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		
	
	return 0;
}