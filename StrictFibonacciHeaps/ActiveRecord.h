#pragma once
class ActiveRecord {
private:
    bool flag;
    int refCount;

public:
    ActiveRecord();
    ~ActiveRecord();

    bool getFlag() const;
    void setFlag(bool flag);
    int getRefCount() const;
    void incrementRefCount();
    void decrementRefCount();
};
