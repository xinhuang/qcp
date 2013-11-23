#include "QuickCheck.h"

#include <cassert>

using namespace std;

#include "Specification.h"

namespace qcp {

QuickCheck::~QuickCheck() {
    for (auto& spec : specs_) {
        delete spec;
    }
    specs_.clear();
}

void QuickCheck::Add(Spec* spec) {
    assert(spec);
    specs_.push_back(spec);
}

void QuickCheck::Add(PropBase* prop) {
    assert(prop);
    specs_.back()->Add(prop);
}

}