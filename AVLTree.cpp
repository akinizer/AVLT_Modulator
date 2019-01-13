/**
* Title : Heaps and AVL Trees
* Description : AVL Tree functions, insert, delete, find height
*/

#include "AVLTree.h"

///constructor
AVLTree::AVLTree(){
    head=NULL;
}

///insertion
void AVLTree::insert(int key){
    ///check whether tree is empty
    if(head!=NULL){
        insertKey(key, head);
    }

    ///if empty, create a new node then insert
    else{
        head=new Node;
        head->key=key;
        head->left=NULL;
        head->right=NULL;
    }
}

///height
int AVLTree::getHeight(){
    return curCalcHeight(head);
}

///find key node
AVLTree::Node*AVLTree::findKey(int key, Node*tree){
    if(!isEmpty(tree)){
        findKey(key, tree->left);
        findKey(key, tree->right);

        if(tree->key == key) return tree;
    }
    return NULL;
}

///emptiness
bool AVLTree::isEmpty(Node*tree){
    return tree==NULL;
}

///functions to calculate max height of the tree
int AVLTree::curCalcHeight(Node*tree){
    ///whether empty
    if (tree!=NULL){
        int leftChildHeight = curCalcHeight(tree->left); ///calculated height of left child
        int rightChildHeight = curCalcHeight(tree->right);  ///calculated height of right child

        if (leftChildHeight > rightChildHeight)         ///compare children then return deeper one
           return leftChildHeight+1;
        else
            return rightChildHeight+1;
    }
    return 0; ///empty
}

void AVLTree::insertKey(int key, Node*tree){
    ///if item is less than item of current node
    if(key < tree->key){
        ///if left child is not empty
        if(tree->left!=NULL)
            insertKey(key, tree->left); ///advance to left child

        ///if left child is empty, left child becomes a new node available to insert child, new grandchildren becomes empty
        else{
            tree->left = new Node;
            (tree->left)->key = key;
            (tree->left)->left = NULL;    //Sets the left child of the child node to null
            (tree->left)->right=NULL;   //Sets the right child of the child node to null
        }
    }
    ///if item is greater than item of current node
    else if(key>=tree->key){
        ///if not empty advance to right child
        if(tree->right!=NULL)
            insertKey(key, tree->right);

        ///if left child is empty, make it available, insert item, make grandchildren empty
        else{
            tree->right = new Node;
            (tree->right)->key = key;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
        }
    }
}


