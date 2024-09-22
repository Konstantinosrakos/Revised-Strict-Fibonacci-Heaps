#pragma once
#include "Node.h"
#include "RankListRecord.h"
#include "FixListRecord.h"

class FiboHeap {
public:
    // Constructors
    FiboHeap();

    // Core Heap Operations
    void insert(int value);                  // Insert a new node
    void deleteMin();                        // Delete the node with the minimum key
    void decreaseKey(FiboNode* node, int value); // Decrease the key of a node
    FiboNode* findMin() const;               // Find the node with the minimum key
    FiboHeap* meld(FiboHeap* otherHeap);     // Meld this heap with another

    // Debugging
    void printHeap() const;                  // Print the heap structure for debugging

private:
    FiboNode* root;
    int size;
    ActiveRecord* active;
    RankListRecord* rankList;
    FixListRecord* fixList[6];

    // Helper Methods
    void link(FiboNode* child, FiboNode* parent);    // Link two nodes
    void cut(FiboNode* node);                        // Cut a node from the heap
    void consolidate();                              // Consolidate trees after deletion
    void performLossReduction();                     // Perform loss reduction
};
