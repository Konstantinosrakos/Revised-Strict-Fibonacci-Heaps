#pragma once
class Node;
class HeapRecord;

class StrictFibonacciHeap {
private:
    HeapRecord* heapRecord;

    // Helper methods
    void linkToRoot(Node* x, Node* y);
    bool activeRootReduction();
    bool rootDegreeReduction();
    bool lossReduction();
    void updateFixList(Node* node);
    

public:
    void link(Node* x, Node* y);
    StrictFibonacciHeap();
    ~StrictFibonacciHeap();

    void* findMin() const;
    void insert(void* item,int key);
    void decreaseKey(Node* x, int newKey);
    void* deleteMin();
    void meld(StrictFibonacciHeap* otherHeap);
};
