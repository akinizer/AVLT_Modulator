/**
* Title : Heaps and AVL Trees
* Description : In part f, create min, max, quick median heaps, insert items, print height analysis
*/

#include <iostream>
#include "analysis.h"
#include "MaxHeap.h"
#include "MinHeap.h"
#include "QuickMedian.h"
using namespace std;

int main(){

    MinHeap* system;
    system = new MinHeap(10);

    system->insert(40);
    system->insert(50);
    system->insert(45);
    system->insert(30);
    system->insert(60);
    system->insert(55);
    system->insert(20);
    system->insert(35);
    system->insert(10);
    system->insert(25);

    cout<<"Min: "<<system->getMin()<<", Size:"<<system->getSize()<<endl;

    MaxHeap* program;

    program->insert(40);
    program->insert(50);
    program->insert(45);
    program->insert(30);
    program->insert(60);
    program->insert(55);
    program->insert(20);
    program->insert(35);
    program->insert(10);
    program->insert(25);

    cout<<"Max: "<<program->getMax()<<", Size:"<<program->getSize()<<endl;

    QuickMedian* protocol;

    protocol->insert(10);
    protocol->insert(40);
    protocol->insert(30);
    protocol->insert(50);
    protocol->insert(70);
    protocol->insert(60);
    protocol->insert(20);
    protocol->insert(90);
    protocol->insert(100);
    protocol->insert(110);
    protocol->insert(0);
    protocol->insert(25);
    protocol->insert(123);
    protocol->insert(11);
    protocol->insert(200);

    cout<<"Median: "<<protocol->getMedian()<<endl;

    analysis control;

    return 0;
}
