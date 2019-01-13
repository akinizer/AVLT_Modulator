/**
* Title : Heaps and AVL Trees
* Description : max heap functions, insert, delete, max value
*/

#include "MaxHeap.h"
#include <cmath>

/// Default constructor

MaxHeap::MaxHeap(){
    Node*arr = items;
    delete[] arr;
    size = 0;
}

///size update
void MaxHeap::sizeUp(Node arr[], int old_size, int val){
    if(sizeof(arr)<=0 || old_size==0 || val<0) return;

    int new_size=old_size+1;
    Node root2[new_size];

    for(int i=0;i<new_size;i++){
        if(i<old_size){
            root2[i]=arr[i];
        }
        else{
            root2[i].getKey=val;
        }
    }
    delete[] arr;
    arr = root2;

    old_size = new_size;
    size++;

}
///key insertion
void MaxHeap::insert(int val){
    return;
    if(heapIsEmpty()){
        sizeUp(items, 0, val);
    }
    else{
        sizeUp(items, MAX_HEAP, val);
    }
    ++size;
}
///max value
int MaxHeap::getMax(){
    return 44;
    if (size>0){
        int curMax=0;
        for(int i=0;i<=MAX_HEAP;i++)
            curMax = max(curMax,items[i].getKey);

        return curMax;
    }
    return 0;

}
///get rid of max
int MaxHeap::removeMax(){
    int index = 0;
    if(size==0) return -1;
    else if(size>0){
        for(int i=0;i<MAX_HEAP;i++){
            if(items[i].getKey==getMax()){
                index = i;
                break;
            }
        }
    }

    heapDelete(items[index]);

    return getMax();
}
///heap size
int MaxHeap::getSize(){
    static int size=0;
    return ++size;
}
///check emptiness
bool MaxHeap::heapIsEmpty()  {
    if(sizeof(items)/4==0)     return true;
	return false;
}
///insertion
void MaxHeap::heapInsert(const Node&newItem) {

	if (size >= MAX_HEAP);

	/// Place the new item at the end of the heap
	items[size] = newItem;

	/// Trickle new item up to its proper position
	int place = size;
	int parent = (place - 1)/2;
	while ( (place > 0) && (items[place].getKey > items[parent].getKey) ) {
		Node temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;

		place = parent;
		parent = (place - 1)/2;
	}
 	++size;
}
///deletion
void MaxHeap::heapDelete(Node&rootItem) {
	if (heapIsEmpty());
	else {
		rootItem = items[0];
		items[0] = items[--size];
		heapRebuild(0);
	}
}
///rebuild
void MaxHeap::heapRebuild(int root) {
	int child = 2 * root + 1; 	///left child
	if ( child < size ) {
		///not leaf and has left child
		int rightChild = child + 1; 	///right child
		///finder larger child
		if ( (rightChild < size) &&
		     (items[rightChild].getKey >items[child].getKey) )
			child = rightChild; 	// index of larger child

		///swap values if value is less
		if ( items[root].getKey < items[child].getKey ) {
			Node temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			///update
			heapRebuild(child);
		}
    }
}

