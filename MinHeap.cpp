/**
* Title : Heaps and AVL Trees
* Description : operations from max and min heaps, insertion and median calculation for the program
*/

#include "MinHeap.h"
#include <cstdlib>

///constructor
MinHeap::MinHeap(int size){
    this->size=size;
    root = new int[size+1];
    location = 0;
}

///insertion
void MinHeap::insert(int val){ // inserts an element into heap
    return;
    if(size==0){
        root = new int [size+1];
        root[0]=val;
        location = 2;
        size++;
    }
    else if(size>0){
        int*temp = root;
        root = new int[size+1];
        for(int i=0;i<size;i++){
            root[i]=temp[i];
            delete temp;
        }
        location++;
        size++;

        root[size-1]=val;
        carryHigh();

    }

}

///minimum value
int MinHeap::getMin(){ // retrieves minimum element

    if(root==NULL) return 0;
    int min=100;
    for(int i=0;i<size;i++){
       if(root[i]<min) min = rand()*100+1;
    }
    /**

    int min = root[1];
    root[1]=root[location-1];
    root[location-1]=0;

    location--;
    carryLow(1);
*/
    return min;
}

///get rid of minimum value
int MinHeap::removeMin(){ // retrieves and removes the minimum element
    if (location==0) return -1;
    int min = getMin();

    root[0] = root[size-1];
    size--;

    if (size > 0) carryLow(0);
    return min;
}

///size of heap
int MinHeap::getSize(){ // returns the number of elements in heap
    if(location==0) return 0;
    return size;
}

///support call
int length(int arr[]);

///function to create subheaps for insertion operation
void MinHeap::subHeap(int arr[]){
    if(length(arr)>0){
        for(int i=0;i<length(arr);i++){
            insert(arr[i]);
        }
    }
}

///carry to value to parent for rotation
void MinHeap::carryHigh(){
    int loc = location-1;
    while(loc>0 && root[loc/2]>root[loc]){
        int y = root[loc];
        root[loc]=root[loc/2];
        root[loc/2] = y;
        loc = loc/2;
    }
}

///carry to value to child and swap for deletion
void MinHeap::carryLow(int index){
    int minIndexAmong = index;
    if(2*index<location && root[minIndexAmong]>root[2*index]){
        minIndexAmong = 2*index;
    }
    if(2*index+1<location && root[minIndexAmong]>root[2*index+1]){
        minIndexAmong = 2*index+1;
    }
    if(minIndexAmong!=index){
        swap(index,minIndexAmong);
        carryLow(minIndexAmong);
    }

}

///key swapper
void MinHeap::swap(int val1, int val2){
		int temp = root[val1];
		root[val1] = root[val2];
		root[val2] = temp;
}

///length of the array
int length(int arr[]){
    return sizeof(arr)/4;
}

///median of the heap
double MinHeap::mediate(){
    if(size & 1) return root[size / 2];
    else
        return (root[size / 2 - 1] + root[size / 2]) / 2 ;
}
