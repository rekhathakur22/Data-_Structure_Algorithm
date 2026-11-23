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

    void print(){
        for(int i=0; i<=size; i++){
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
      return 0;
}