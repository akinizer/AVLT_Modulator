/**
* Title : Heaps and AVL Trees
* Description : implement min-heap data structure named as MinHeap for maintaining a
list of integer keys.
*/
#include <iostream>
using namespace std;
class MinHeap{

///variables and functions
private:

	int location;

protected:
    void subHeap(int arrA[]);
	void carryHigh();
	void carryLow(int index);

	void swap(int val1, int val2);

public:
    int size;
    int*root;
    double mediate();
    MinHeap(int size);

    ///requested
    void insert(int val); // inserts an element into heap
    int getMin(); // retrieves the minimum element
    int removeMin(); // retrieves and removes the minimum element
    int getSize(); // returns the number of elements in heap

};
