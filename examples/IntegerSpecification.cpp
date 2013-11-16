#include "qcp.h"
using namespace qcp;

//class Integer {
//public:
//    Integer() : _value(0) {}
//    Integer(int value) : _value(value) {}
//
//    int value() const { return _value; }
//
//    friend bool operator== (Integer lhs, Integer rhs) {
//        return lhs.value() == rhs.value();
//    }
//
//    friend bool operator== (int lhs, Integer rhs) {
//        return lhs == rhs.value();
//    }
//
//private:
//    int _value;
//};
//
//template <>
//class Generator<Integer> {
//public:
//    Integer next() {
//        return Integer(generator<int>()->next());
//    }
//};

SPECIFICATION(integer_specification) {

    Property<int, int>("add 2 integer is no greater than add their absolute values") = [](int lhs, int rhs) {
        return lhs + rhs <= abs(lhs) + abs(rhs);
    };

    //Property<Integer, Integer>("Integer with same value should equal") = [](Integer lhs, Integer rhs) {
    //    if (lhs.value() == rhs.value())
    //        ASSERT_EQ(lhs, rhs);
    //};

    //Property<Integer, int>("Integer with same value int should equal") = [](Integer lhs, int rhs) {
    //    if (lhs.value() == rhs)
    //        ASSERT_EQ(lhs, rhs);
    //};

    //Property<int>("Integer should equal to int type") = [](int n) {
    //    ASSERT_EQ(n, Integer(n));
    //    cout << n << endl;
    //};
}

