#pragma once
class RankListRecord;
class ActiveRecord;
class FixListRecord;

class Node {
private:
    int key;

    Node* left;
    Node* right;
    Node* parent;
    Node* leftChild;
    ActiveRecord* active;
    Node* qPrev;
    Node* qNext;
    int loss;
    RankListRecord* rank;
    FixListRecord* fix;

public:
    Node(void* item, int key);
    ~Node();

    // Getters and setters
    int getKey() const;
    void setKey(int newKey);
    Node* getLeft() const;
    void setLeft(Node* left);
    Node* getRight() const;
    void setRight(Node* right);
    Node* getParent() const;
    void setParent(Node* parent);
    Node* getLeftChild() const;
    void setLeftChild(Node* leftChild);
    ActiveRecord* getActive() const;
    void setActive(ActiveRecord* active);
    Node* getQPrev() const;
    void setQPrev(Node* qPrev);
    Node* getQNext() const;
    void setQNext(Node* qNext);
    int getLoss() const;
    void setLoss(int loss);
    RankListRecord* getRank() const;
    void setRank(RankListRecord* rank);
    FixListRecord* getFix() const;
    void setFix(FixListRecord* rank);
    bool isActiveRoot();
    void increaseRank();
    void detachFromParent();
    bool isLinkable();
};