#ifndef qcp_PROP_H
#define qcp_PROP_H

#include <string>
using std::string;
#include <functional>
using std::function;

#include "QuickCheck.h"

namespace qcp {

class PropBase {
public:
    PropBase(const string& name) : name_(name) {}

    virtual bool Check() = 0;

    const string& name() const { return name_; }

private:
    const string name_;
};

template <typename... Ts>
class Prop : public PropBase {
    typedef PropBase base;
public:
    Prop(const string& name) : base(name) {
        QuickCheck::Instance()->Add(this);
    }

    template<typename T>
    void operator=(T f) {
        check_ = [=]() {
            return true;
        };
    }

    bool Check() override {
        return check_();
    }

private:
    function<bool()> check_;
};

template <typename... Ts>
class PropContainer {
public:
    PropContainer(const string& name) : prop_(new Prop<Ts...>(name)) {}

    template<typename T>
    void operator=(T f) {
        (*prop_) = f;
    }

private:
    Prop<Ts...>* prop_;
};

template <typename... Ts>
PropContainer<Ts...> Property(const string& property_name) {
    return PropContainer<Ts...>(property_name);
}

}

#endif // qcp_PROP_H
