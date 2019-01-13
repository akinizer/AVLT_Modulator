/**
* Title : Heaps and AVL Trees
* Description : implement max-heap data structure named as MaxHeap for maintaining a
list of integer keys
*/

#include <iostream>
using namespace std;

///variables, supportive and requested functions, items array holding heap

class MaxHeap{
private:
    struct Node{
        int getKey;
    };
    int MAX_HEAP;
    Node items[100];
///supportive
protected:
    Node findKey(int key);
	void heapRebuild(int root);		///semi heap is rebuilt to heap
	void sizeUp(Node root[], int, int);  ///size update
    int size;
public:
    MaxHeap();

	bool heapIsEmpty() ;
	void heapInsert(const Node& newItem) ;
	void heapDelete(Node& rootItem) ;

	///requested
    void insert(int val); // inserts an element into heap
    int getMax(); // retrieves maximum element
    int removeMax(); // retrieves and removes the maximum element
    int getSize(); // returns the number of elements in heap

};

