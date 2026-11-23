#include<iostream>
using namespace std;

class MaxHeap{
    int *arr;
    int size;
    int total_size;

    public:

    MaxHeap(int value){
        arr = new int[value];
        size = 0;
        total_size = value;
    }

    // insert element into the heap
    // insertion in heap is O(logn)
    // heap creation is O(n log n)
    void insert(int val){
        // check if arr is full or not
        if(size == total_size) {
            cout<<"heap is overflow"<<endl;
            return ;
        }

        // insert new element 
        arr[size]=val;
        int index  = size;
        size++;

        // check the parent node

        while(index > 0 && arr[(index-1)/2] < arr[index]){
           swap(arr[(index-1)/2],arr[index]);
           index = (index-1)/2;
           cout<<"element is inserted at "<<index << endl;
        }
    }
    

    // deletion of element from the heap
    // deletion in heap is O(logn)
    void deletion(){
       if(size == 0){
        cout<<"heap is underflow"<<endl;
        return;
       }

       cout<<"element deleted is"<<arr[0]<<endl;
       arr[0]=arr[size-1];
       size--;
       int index = 0;

       while(index < size){
         int largest = index;
        int left = 2*index +1;
        int right = 2*index + 2;
        
         if (left < size && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(arr[index], arr[largest]);
            index = largest;
        } else {
            break; // Heap property is restored
        }
       } 
    }
    
    void print(){
        for(int i=0; i<size; i++){
          cout<<arr[i]<<endl;
        }
    }
};

int main(){
    MaxHeap H1(6);
    H1.insert(1);
     H1.insert(14);
      H1.insert(16);
      H1.print();
      H1.deletion();
        H1.print();
      return 0;
}