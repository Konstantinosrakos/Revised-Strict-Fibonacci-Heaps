#include "Node.h"
#include "ActiveRecord.h"
#include "RankListRecord.h"

Node::Node(void* item, int key) : key(key), left(this), right(this), parent(nullptr),
leftChild(nullptr), active(nullptr), qPrev(nullptr), qNext(nullptr),
loss(0), rank(nullptr) {}



Node::~Node() = default;


int Node::getKey() const { return key; }
void Node::setKey(int newKey) { key = newKey; }
Node* Node::getLeft() const { return left; }
void Node::setLeft(Node* newLeft) { left = newLeft; }
Node* Node::getRight() const { return right; }
void Node::setRight(Node* newRight) { right = newRight; }
Node* Node::getParent() const { return parent; }
void Node::setParent(Node* newParent) { parent = newParent; }
Node* Node::getLeftChild() const { return leftChild; }
void Node::setLeftChild(Node* newLeftChild) { leftChild = newLeftChild; }
ActiveRecord* Node::getActive() const { return active; }
void Node::setActive(ActiveRecord* newActive) { active = newActive; }
Node* Node::getQPrev() const { return qPrev; }
void Node::setQPrev(Node* newQPrev) { qPrev = newQPrev; }
Node* Node::getQNext() const { return qNext; }
void Node::setQNext(Node* newQNext) { qNext = newQNext; }
int Node::getLoss() const { return loss; }
void Node::setLoss(int newLoss) { loss = newLoss; }
RankListRecord* Node::getRank() const { return rank; }
void Node::setRank(RankListRecord* newRank)

{
	// MORE IMPLEMENTATION
	 rank = newRank; }

bool Node::isActiveRoot()
{
	return false;
}

void Node::increaseRank()
{
	//wathch out for implementing increase rank. it should only increase the rank and setting it to the node.
}

void Node::detachFromParent()
{
	return;
	//detach from parent
	//update ranks fix list 
}

bool Node::isLinkable()
{
	if (!this->getActive()->getFlag())
	{
		if (this->getLeftChild() || !this->getLeftChild()->getActive()->getFlag())
		{
			return true;
		}
	}
	return false;
}
