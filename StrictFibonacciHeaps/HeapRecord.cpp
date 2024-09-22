#include "HeapRecord.h"
#include "ActiveRecord.h"

HeapRecord::HeapRecord() : size(0), root(nullptr), activeRecord(new ActiveRecord()), nonLinkableChild(nullptr),
qHead(nullptr), rankList(nullptr), fixList(nullptr), singles(nullptr) {}

HeapRecord::~HeapRecord() {
    delete activeRecord;
}

int HeapRecord::getSize() const { return size; }
void HeapRecord::setSize(int newSize) { size = newSize; }
Node* HeapRecord::getRoot() const { return root; }
void HeapRecord::setRoot(Node* newRoot) { root = newRoot; }
ActiveRecord* HeapRecord::getActiveRecord() const { return activeRecord; }
void HeapRecord::setActiveRecord(ActiveRecord* newActiveRecord) { activeRecord = newActiveRecord; }
Node* HeapRecord::getNonLinkableChild() const { return nonLinkableChild; }
void HeapRecord::setNonLinkableChild(Node* newNonLinkableChild) { nonLinkableChild = newNonLinkableChild; }
Node* HeapRecord::getQHead() const { return qHead; }
void HeapRecord::setQHead(Node* newQHead) { qHead = newQHead; }
RankListRecord* HeapRecord::getRankList() const { return rankList; }
void HeapRecord::setRankList(RankListRecord* newRankList) { rankList = newRankList; }
FixListRecord* HeapRecord::getFixList() const { return fixList; }
void HeapRecord::setFixList(FixListRecord* newFixList) { fixList = newFixList; }
FixListRecord* HeapRecord::getSingles() const { return singles; }
void HeapRecord::setSingles(FixListRecord* newSingles) { singles = newSingles; }

void HeapRecord::addToFixList(Node* node)
{
}
