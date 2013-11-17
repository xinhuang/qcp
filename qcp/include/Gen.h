#ifndef qcp_GEN_H
#define qcp_GEN_H

#include <cstdlib>
using std::rand;
#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <vector>
using std::vector;

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
    int Sample() const { return rand(); }
};

template <>
class Gen<bool> {
public:
    bool Sample() const { return gen<int>()->Sample() % 2 == 0; }
};

#define choose(lhs, rhs)\
    (gen<bool>()->Sample()) ? (lhs) : (rhs)

template <typename T>
class Gen<vector<T>> {
public:
    vector<T> Sample() const {
        return choose(vector<T>(), concat<T>(Sample(), gen<T>()->Sample()));
    }
};

}

#endif // qcp_GEN_H
