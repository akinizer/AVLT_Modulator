/**
* Title : Heaps and AVL Trees
* Description : design and implement a data structure QuickMedian
for maintaining a list of integers in which insert operation is processed in O(log n)
and finding median is processed in O(1)
*/

class QuickMedian {
private:

	int location;


public:
    QuickMedian(int size);
    void insert(int val); // inserts an element into QuickMedian
    double getMedian(); // returns the median of elements

	int size;
    int*root;

    int getMin(); // retrieves the minimum element
    int removeMin(); // retrieves and removes the minimum element
    int getSize(); // returns the number of elements in heap

protected:
    void subHeap(int*arr);
	void carryHigh();
	void carryLow(int index);

	void swap(int val1, int val2);
};


