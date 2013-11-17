#include "qcp.h"
using namespace qcp;

#include <vector>

using namespace std;

#include <iostream>

SPECIFICATION(int_vector) {

    Property<vector<int>>("WRONG: size should always be less than 3") = [](vector<int>& v) {
        return v.size() < 3;
    };

}
