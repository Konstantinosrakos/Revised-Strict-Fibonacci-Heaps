#include "StrictFibonacciHeap.h"
#include "Node.h"
#include "HeapRecord.h"
#include "FixListRecord.h"
#include "RankListRecord.h"
#include "ActiveRecord.h"
#include <stdexcept>
#include <iostream>

void StrictFibonacciHeap::link(Node* x, Node* y) {

    x->detachFromParent();

    Node* leftMostChild = y->getLeftChild();
    if (x->getActive()->getFlag())
    {
        if (leftMostChild)
        {
            x->setRight(leftMostChild);
            x->setLeft(leftMostChild->getLeft());
            leftMostChild->getLeft()->setRight(x);
            leftMostChild->setLeft(x);
        }
        else
        {
            x->setRight(x);
            x->setLeft(x);
        }
        y->setLeftChild(x);

    }
    else
    {
        if (leftMostChild)
        {
            x->setLeft(leftMostChild->getLeft());
            x->setRight(leftMostChild);
            leftMostChild->getLeft()->setRight(x);
            leftMostChild->setLeft(x);
        }
        else
        {

            y->setLeftChild(x);
            x->setRight(x);
            x->setLeft(x);
        }
    }

    x->setParent(y);
}
void StrictFibonacciHeap::linkToRoot(Node* x, Node* root)
{
    // Detach x from its parent, if it has one
    x->detachFromParent();

    // Get the leftmost child of the root (active children)
    Node* leftMostChild = root->getLeftChild();

    // Access the heap record of the root to check for the non-linkable child
    Node* nonLinkableChild = heapRecord->getNonLinkableChild();

    // If x is active
    if (x->getActive()->getFlag()) {
        if (leftMostChild) {
            // Insert x as the leftmost active child
            x->setRight(leftMostChild);
            x->setLeft(leftMostChild->getLeft());
            leftMostChild->getLeft()->setRight(x);
            leftMostChild->setLeft(x);
        }
        else {
            // If root has no children, x becomes its sole child
            x->setRight(x);
            x->setLeft(x);
        }
        // Set the leftmost child of the root to be x
        root->setLeftChild(x);
        if (!nonLinkableChild)
        {
            heapRecord->setNonLinkableChild(x);
        }
        else
        {
            if (nonLinkableChild->getActive()->getFlag())
            {
                heapRecord->setNonLinkableChild(x);
            }
        }
    }
    // If x is passive
    else {
        // Check if x is linkable or non-linkable
        if (x->isLinkable()) {
            // Insert x in the proper position (after the active children)
            if (leftMostChild) {
                x->setLeft(leftMostChild->getLeft());
                x->setRight(leftMostChild);
                leftMostChild->getLeft()->setRight(x);
                leftMostChild->setLeft(x);
            }
            else {
                // If no children exist, x becomes the sole child
                root->setLeftChild(x);
                x->setRight(x);
                x->setLeft(x);
            }
        }
        else {
            // Handle the non-linkable passive case
            if (nonLinkableChild) {
                if (nonLinkableChild->getActive()->getFlag())
                {
                    x->setLeft(nonLinkableChild);
                    x->setRight(nonLinkableChild->getRight());
                    nonLinkableChild->getRight()->setLeft(x);
                    nonLinkableChild->setRight(x);
                }
                else
                {
                    x->setLeft(nonLinkableChild->getLeft());
                    x->setRight(nonLinkableChild);
                    nonLinkableChild->getLeft()->setRight(x);
                    nonLinkableChild->setLeft(x);
                }
                heapRecord->setNonLinkableChild(x);
            }
            else {
                // If there is no non-linkable child, insert x and update the heap record
                if (leftMostChild) {
                    x->setLeft(leftMostChild->getLeft());
                    x->setRight(leftMostChild);
                    leftMostChild->getLeft()->setRight(x);
                    leftMostChild->setLeft(x);
                }
                else {
                    root->setLeftChild(x);
                    x->setRight(x);
                    x->setLeft(x);
                }
                heapRecord->setNonLinkableChild(x);  // Set x as the new non-linkable child
            }
        }
    }

    // Set the parent of x to root
    x->setParent(root);
}

bool StrictFibonacciHeap::activeRootReduction() {


    FixListRecord* fix_list_record = heapRecord->getFixList();
    FixListRecord* x_record;

    if (fix_list_record)
    {
        if (fix_list_record->getNode()->isActiveRoot())
        {
            x_record = fix_list_record;
        }
        else
        {
            x_record = fix_list_record->getRight();
        }
    }else { 
        return false; 
    }

    FixListRecord* y_record = x_record->getRight();

    if (x_record == y_record) return false;

    if (!(x_record->getNode()->isActiveRoot()) || !(y_record->getNode()->isActiveRoot())) return false;

    if (x_record->getRank() != y_record->getRank()) return false;

    
    Node* x = x_record->getNode();
    Node* y = y_record->getNode();

    if (x->getKey() > y->getKey())
    {
        std::swap(x, y);
        std::swap(x_record, y_record);
    }

    std::cout <<"Active root reduction on " << x->getKey() << ", " << y->getKey() << std::endl;
    link(y, x);

    x->getRank()->decrementRefCount();
    if (x->getRank()->getActiveRoots() == x_record || x->getRank()->getActiveRoots() == y_record)
    {
        x->getRank()->setActiveRoots(nullptr);
    }
    

    
    y_record->getLeft()->setRight(y_record->getRight());
    y_record->getRight()->setLeft(y_record->getLeft());
    delete y_record;

    if (x_record != x_record->getRight())
    {
        x_record->getLeft()->setRight(x_record->getRight());
        x_record->getRight()->setLeft(x_record->getLeft());
    }
    else
    {
        heapRecord->setFixList(x_record);
    }
    
    x->increaseRank();
    x_record->setRank(x->getRank());
    

    Node* z = x->getLeftChild()->getLeft();

    if (z && !z->getActive())
    {
        std::cout << "Made " << z->getKey() << " child of the root." << std::endl;
        linkToRoot(z, heapRecord->getRoot());
    }

    

    return true;

   
    

}

bool StrictFibonacciHeap::rootDegreeReduction() {
    // Implementation of root degree reduction
    // This is a complex operation that needs to be implemented carefully
    // based on the description in the paper
    Node* x = heapRecord->getRoot()->getLeftChild();
    Node* y;
    Node* z;
    if (x && x->isLinkable())
    {
        y = x->getLeft();
        z = y->getLeft();  
    }
    else
    {
        return false;
    }
    
    if (!(x != y && x != z && y != z)) return false;
    if (!(x->isLinkable() && y->isLinkable() && z->isLinkable())) return false;

    std::cout << "Performing root degree reduction on " << x->getKey() << ", " << y->getKey() << ", " << z->getKey() << ".\n";

    if (x->getKey() > z->getKey())
    {
        std::swap(x, z);
    }
    if (x->getKey() > y->getKey())
    {
        std::swap(x, y);
    }
    if (y->getKey() > z->getKey())
    {
        std::swap(y, z);
    }
    x->setActive(heapRecord->getActiveRecord());
    y->setActive(heapRecord->getActiveRecord());
    link(z, y);
    link(y, x);
    linkToRoot(x, heapRecord->getRoot());
    x->setLoss(0);
    y->setLoss(0);
    RankListRecord* rankRecord = heapRecord->getRankList();
    if (rankRecord)
    {
        y->setRank(rankRecord);
    }
    else
    {
        heapRecord->setRankList(new RankListRecord());
        rankRecord = heapRecord->getRankList();
        y->setRank(rankRecord);
    }
    rankRecord->incrementRefCount();
    rankRecord = rankRecord->getInc();
    if (rankRecord)
    {
        x->setRank(rankRecord);
        rankRecord->incrementRefCount();
    }
    else
    {
        heapRecord->setRankList(new RankListRecord());
        x->setRank(rankRecord);
        rankRecord->incrementRefCount();
        heapRecord->addToFixList(x);
    }
}

bool StrictFibonacciHeap::lossReduction() {

    FixListRecord* fix_list_record = heapRecord->getFixList();
    if (fix_list_record)
    {
        if (fix_list_record->getNode()->isActiveRoot())
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    if (fix_list_record->getNode()->getLoss() >= 2)
    {
        // one node loss reduction
    }
    FixListRecord* fix_list_record_left = heapRecord->getFixList();
    if ((fix_list_record != fix_list_record_left) && (fix_list_record->getRank() == fix_list_record_left->getRank()))
    {
        if (fix_list_record_left->getLeft() == fix_list_record)
        {
            heapRecord->setFixList(nullptr);
        }
        else
        {
            heapRecord->setFixList(fix_list_record_left->getLeft());
            fix_list_record_left->getLeft()->setRight(fix_list_record->getRight());
            fix_list_record->getRight()->setLeft(fix_list_record_left->getLeft());
        }
        Node* x = fix_list_record->getNode();
        Node* y = fix_list_record_left->getNode();

        if (x->getKey() > y->getKey())
        {
            std::swap(x, y);
            std::swap(fix_list_record, fix_list_record_left);
        }
        if (fix_list_record == fix_list_record->getRank()->getLoss() || fix_list_record_left == fix_list_record->getRank()->getLoss())
        {
            fix_list_record->getRank()->setLoss(nullptr);
        }
        fix_list_record->getRank()->decrementRefCount();
        x->setFix(nullptr);
        y->setFix(nullptr);
        y->setRank(fix_list_record->getRank());
        x->increaseRank();

        x->setLoss(0);
        y->setLoss(0);

        Node* z = x->getParent();
        if (!(z->isActiveRoot()))
        {
            z->setLoss(z->getLoss() + 1);
            updateFixList(z);
        }
    }
    else
    {
        return false;
    }


}

void StrictFibonacciHeap::updateFixList(Node* node) {

}


StrictFibonacciHeap::StrictFibonacciHeap() : heapRecord(new HeapRecord()) {}

StrictFibonacciHeap::~StrictFibonacciHeap() {
    // Implement proper cleanup of all allocated memory
    delete heapRecord;
    // Need to implement recursive deletion of nodes and other structures
}

void* StrictFibonacciHeap::findMin() const {
    if (heapRecord->getRoot() == nullptr) {
        return nullptr;
    }
    return nullptr;
}

void StrictFibonacciHeap::insert(void* item, int key) {

}

void StrictFibonacciHeap::decreaseKey(Node* x, int newKey) {

}

void* StrictFibonacciHeap::deleteMin() {

}

void StrictFibonacciHeap::meld(StrictFibonacciHeap* otherHeap) {

}
