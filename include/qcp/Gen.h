#ifndef qcp_GEN_H
#define qcp_GEN_H

#include <cstdlib>
using std::rand;
#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <vector>
using std::vector;

#include "to_string.h"

namespace qcp {

template <typename T>
vector<T> concat(vector<T> v, const T& elem) {
    v.push_back(elem);
    return v;
}

template <typename T>
class Gen {};

template <typename T>
shared_ptr<Gen<T>> gen() {
    static auto instance = make_shared<Gen<T>>();
    return instance;
}

template <>
class Gen<int> {
public:
    int Next() const { return rand(); }
};

template <>
class Gen<bool> {
public:
    bool Next() const { return gen<int>()->Next() % 2 == 0; }
};

#define choose(lhs, rhs)\
    (gen<bool>()->Next()) ? (lhs) : (rhs)

template <typename T>
class Gen<vector<T>> {
public:
    vector<T> Next() const {
        return choose(vector<T>(), concat<T>(Next(), gen<T>()->Next()));
    }
};

}

#endif // qcp_GEN_H
