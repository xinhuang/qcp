#include "Specification.h"

#include "Property.h"

#include "UnitTest.h"
using namespace qcp::unittest;

namespace qcp {

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