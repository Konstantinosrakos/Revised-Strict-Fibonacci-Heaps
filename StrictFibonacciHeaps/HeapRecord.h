#pragma once
class ActiveRecord;
class RankListRecord;
class FixListRecord;
class Node;

class HeapRecord {
private:
    int size;
    Node* root;
    ActiveRecord* activeRecord;
    Node* nonLinkableChild;
    Node* qHead;
    RankListRecord* rankList;
    FixListRecord* fixList;
    FixListRecord* singles;

public:
    HeapRecord();
    ~HeapRecord();

    // Getters and setters
    int getSize() const;
    void setSize(int size);
    Node* getRoot() const;
    void setRoot(Node* root);
    ActiveRecord* getActiveRecord() const;
    void setActiveRecord(ActiveRecord* activeRecord);
    Node* getNonLinkableChild() const;
    void setNonLinkableChild(Node* nonLinkableChild);
    Node* getQHead() const;
    void setQHead(Node* qHead);
    RankListRecord* getRankList() const;
    void setRankList(RankListRecord* rankList);
    FixListRecord* getFixList() const;
    void setFixList(FixListRecord* fixList);
    FixListRecord* getSingles() const;
    void setSingles(FixListRecord* singles);
    void addToFixList(Node* node);
};

