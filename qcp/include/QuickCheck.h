#ifndef qcp_QUICKCHECK_H
#define qcp_QUICKCHECK_H

#include <memory>
using std::shared_ptr;
#include <vector>
using std::vector;

namespace qcp {

class Spec;
class PropBase;

class QuickCheck {
public:
    static shared_ptr<QuickCheck> Instance() {
        static shared_ptr<QuickCheck> instance(new QuickCheck());
        return instance;
    }

    ~QuickCheck();

    void Add(Spec* spec);
    void Add(PropBase* prop);

private:
    QuickCheck() {}

    vector<Spec*> specs_;
};

}

#endif // qcp_QUICKCHECK_H
