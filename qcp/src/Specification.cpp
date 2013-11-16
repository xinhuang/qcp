#include "Specification.h"

#include "Property.h"
#include "QuickCheck.h"

#include "UnitTest.h"
using namespace qcp::unittest;

namespace qcp {

Spec::Spec(const string& name) : name_(name) { 
    QuickCheck::Instance()->Add(this); 
}

Spec::~Spec() {
    for (auto& prop : props_) {
        delete prop;
    }
    props_.clear();
}

void Spec::Add(PropBase* prop) {
    props_.push_back(prop);

    Register(name_, prop->name(), [=]() { 
        assert(prop->Check()); 
    });
}

}