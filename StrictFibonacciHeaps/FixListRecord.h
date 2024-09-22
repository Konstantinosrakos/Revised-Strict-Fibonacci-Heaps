#pragma once
class Node;
class RankListRecord;

class FixListRecord
{
private:
	Node *node;
	FixListRecord* left ;
	FixListRecord* right;
	RankListRecord* rank;

public:
	FixListRecord(Node *node);
	~FixListRecord();

	// Getters and setters
	Node *getNode() const;
	void setNode(Node *node);
	FixListRecord *getLeft() const;
	void setLeft(FixListRecord* left);
	FixListRecord* getRight() const;
	void setRight(FixListRecord* right);
	RankListRecord* getRank() const;
	void setRank(RankListRecord* rank);
};
