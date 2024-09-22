#pragma once
class FixListRecord;

class RankListRecord {
private:
    RankListRecord* inc;
    RankListRecord* dec;
    FixListRecord* loss;
    FixListRecord* activeRoots;
    int refCount;

public:
    RankListRecord();
    ~RankListRecord();

    // Getters and setters
    RankListRecord* getInc() const;
    void setInc(RankListRecord* inc);
    RankListRecord* getDec() const;
    void setDec(RankListRecord* dec);
    FixListRecord* getLoss() const;
    void setLoss(FixListRecord* loss);
    FixListRecord* getActiveRoots() const;
    void setActiveRoots(FixListRecord* activeRoots);
    int getRefCount() const;
    void incrementRefCount();
    void decrementRefCount();
};

