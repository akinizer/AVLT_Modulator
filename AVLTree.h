/**
* Title : Heaps and AVL Trees
* Description : In part d we implement AVL tree data structure named as AVLTree for maintaining a
list of integer keys
*/

#include <iostream>
using namespace std;


class AVLTree {
private:
    ///support
    struct Node{
        Node*left;
        Node*right;
        int key;
    };
    Node*head;

    Node*findKey(int key, Node*tree);
    bool isEmpty(Node*tree);
    void insertKey(int key, Node*tree);
    int curCalcHeight(Node*tree);

    Node*rotterR(Node*targetRoot);
    Node*rotterL(Node*curRoot);

public:
    AVLTree();

    ///requested
    void insert(int key);
    int getHeight();


};
