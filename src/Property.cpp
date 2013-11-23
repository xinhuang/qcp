#include "Property.h"

#include "QuickCheck.h"

namespace qcp {

PropBase::PropBase(const string& name) : name_(name) {
    QuickCheck::Instance()->Add(this);
}

}