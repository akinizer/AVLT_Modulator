/**
* Title : Heaps and AVL Trees
* Descriptipon: Analyze the average height of AVL trees and determine
if different patterns of insertion affect the height of AVL trees. With a global function,
void heightAnalysis(), we observe and show height of AVL trees depending of size and item order
*/


#include "analysis.h"
#include <cstdlib>

///supportive functions
void heightAnalysis();

///constructor
analysis::analysis(){
    heightAnalysis();
}

///height analysis with supportive functions
void heightOutput(int, int, int, int);

void heightAnalysis(){

    ///title
    cout<<"\n\nPart e - Height analysis of AVL trees"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"Array Size\t"<<"Random\t\t"<<"Ascending\t"<<"Descending\t\t"<<endl;
    cout<<"----------------------------------------------------------"<<endl;

    ///controller

    for(int curSize = 2000;curSize<=20000;curSize+=2000){
        ///initial variables
        int height1 = 0, height2, height3 = 0;

        ///pointer based
        AVLTree sample1, sample2, sample3;

        ///calculator loops

            ///random 1000 numbers
        for(int i=0;i<curSize;i++){
            sample1.insert((rand()%1000)+1);
        }
        height1 = sample1.getHeight();

            ///ascending
        for(int i=0;i<curSize;i++){
            sample2.insert(i);
        }
        height2 = sample2.getHeight();

            ///descending
        for(int i=0;i<curSize;i++){
            sample3.insert(curSize-i-1);
        }

        height3 = sample3.getHeight();

        ///output
        heightOutput(curSize, height1, height2, height3);

    }
}

///supportive functions///

/// testing height and obtaining results
void heightOutput(int sizeInput, int height1, int height2, int height3){

    cout<<sizeInput<<"\t\t"<<height1<<"\t\t"<<height2<<"\t\t"<<height3<<endl;
}
