#ifndef qcp_PROP_H
#define qcp_PROP_H

#include <string>
using std::string;
#include <functional>
using std::function;

#include <gtest/gtest.h>

#include "Gen.h"

namespace qcp {

class PropBase {
public:
    PropBase(const string& name);
    PropBase(const PropBase&) = delete;
    PropBase(const PropBase&&) = delete;
    virtual ~PropBase() {}

    virtual void Check() = 0;

    const string& name() const { return name_; }

private:
    const string name_;
};

template <typename... Ts>
class Prop : public PropBase {
    typedef PropBase base;
public:
    Prop(const string& name) : base(name) {}

    template<typename T>
    void operator=(T f) {
        check_ = [=]() {
            for (int i = 0; i < kTimes; ++i) {
                if (!f(gen<Ts>()->Sample()...)) {
                    ASSERT_TRUE(false);
                    return;
                }
            }
        };
    }

    void Check() override {
        check_();
    }

private:
    static const int kTimes = 100;
    function<void()> check_;
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
