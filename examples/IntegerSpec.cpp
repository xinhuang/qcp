#include "qcp.h"
using namespace qcp;

class Integer {
public:
    Integer() : _value(0) {}
    Integer(int value) : _value(value) {}

    int value() const { return _value; }

    friend bool operator== (Integer lhs, Integer rhs) {
        return lhs.value() == rhs.value();
    }

    friend bool operator== (int lhs, Integer rhs) {
        return lhs == rhs.value();
    }

private:
    int _value;
};

string to_s(const Integer& v) {
    return "<Integer: " + std::to_string(v.value()) + ">";
}

template <>
class Gen<Integer> {
public:
    Integer Next() {
        return Integer(gen<int>()->Next());
    }
};

SPECIFICATION(integer_specification) {

    Property<Integer, Integer>("Integer with same value should equal") = [](Integer lhs, Integer rhs) {
        return (lhs == rhs) == (lhs.value() == rhs.value());
    };

    Property<Integer, int>("Integer with same value int should equal") = [](Integer lhs, int rhs) {
        return (lhs == rhs) == (lhs.value() == rhs);
    };

    Property<Integer, int>("WRONG: all Integers should be equal") = [](Integer lhs, int rhs) {
        return lhs == rhs;
    };

    Property<int>("Integer should equal to int type") = [](int n) {
        return n == Integer(n);
    };

}

