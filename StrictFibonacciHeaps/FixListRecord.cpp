#include "FixListRecord.h"
#include "RankListRecord.h"

FixListRecord::FixListRecord(Node* node) : node(node), left(nullptr), right(nullptr), rank(nullptr) {}
FixListRecord::~FixListRecord() = default;

Node* FixListRecord::FixListRecord::getNode() const { return node; }
void FixListRecord::setNode(Node* newNode) { node = newNode; }
FixListRecord* FixListRecord::getLeft() const { return left; }
void FixListRecord::setLeft(FixListRecord* newLeft) { left = newLeft; }
FixListRecord* FixListRecord::getRight() const { return right; }
void FixListRecord::setRight(FixListRecord* newRight) { right = newRight; }
RankListRecord* FixListRecord::getRank() const { return rank; }
void FixListRecord::setRank(RankListRecord* newRank) { rank = newRank; } //when set rank it must check where to put it
