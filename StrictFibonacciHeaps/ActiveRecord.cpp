#include "ActiveRecord.h"

ActiveRecord::ActiveRecord() : flag(true), refCount(0) {}
ActiveRecord::~ActiveRecord() = default;

bool ActiveRecord::getFlag() const { return flag; }
void ActiveRecord::setFlag(bool newFlag) { flag = newFlag; }
int ActiveRecord::getRefCount() const { return refCount; }
void ActiveRecord::incrementRefCount() { refCount++; }
void ActiveRecord::decrementRefCount() { refCount--; }
