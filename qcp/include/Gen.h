#ifndef qcp_GEN_H
#define qcp_GEN_H

#include <cstdlib>
using std::rand;
#include <memory>
using std::shared_ptr;
using std::make_shared;

namespace qcp {
    
template <typename T>
class Gen {};

template <>
class Gen<int> {
public:
    int Sample() const { return rand(); }
};

template <typename T>
shared_ptr<Gen<T>> gen() {
    static auto instance = make_shared<Gen<T>>();
    return instance;
}

}

#endif // qcp_GEN_H
