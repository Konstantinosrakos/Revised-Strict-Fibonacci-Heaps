#include "RankListRecord.h"


RankListRecord::RankListRecord() : inc(nullptr), dec(nullptr), loss(nullptr), activeRoots(nullptr), refCount(0) {}
RankListRecord::~RankListRecord() = default;

RankListRecord* RankListRecord::getInc() const { return inc; }
void RankListRecord::setInc(RankListRecord* newInc) { inc = newInc; }
RankListRecord* RankListRecord::getDec() const { return dec; }
void RankListRecord::setDec(RankListRecord* newDec) { dec = newDec; }
FixListRecord* RankListRecord::getLoss() const { return loss; }
void RankListRecord::setLoss(FixListRecord* newLoss) { loss = newLoss; }
FixListRecord* RankListRecord::getActiveRoots() const { return activeRoots; }
void RankListRecord::setActiveRoots(FixListRecord* newActiveRoots) { activeRoots = newActiveRoots; }
int RankListRecord::getRefCount() const { return refCount; }
void RankListRecord::incrementRefCount() { refCount++; }
void RankListRecord::decrementRefCount() { refCount--; }

