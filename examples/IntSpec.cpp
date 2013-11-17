#include "qcp.h"
using namespace qcp;

SPECIFICATION(int_arithmatics) {

    //Property<int, int>("add 2 integer is no greater than add their absolute values") = [](int lhs, int rhs) {
    //    return lhs + rhs <= abs(lhs) + abs(rhs);
    //};

    Property<int>("WRONG: bad math, a integer is greater than it plus 1") = [](int a) {
        return a > a + 1;
    };

}
