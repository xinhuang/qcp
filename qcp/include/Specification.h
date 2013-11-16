#ifndef qcp_SPECIFICATION_H
#define qcp_SPECIFICATION_H

#include <string>
using std::string;
#include <vector>
using std::vector;

namespace qcp {

class PropBase;

class Spec {
public:
    Spec(const string& name);
    virtual ~Spec();

    void Add(PropBase* prop);

private:
    const string name_;
    vector<PropBase*> props_;
};

#define qcp_CAT(A, B) A##B
#define qcp_CATM(A, B) qcp_CAT(A, B)

#define SPECIFICATION(name)\
    class qcp_CATM(Spec_, name) : private Spec {\
    public:\
        qcp_CATM(Spec_, name)();\
    };\
    qcp_CATM(Spec_, name)* qcp_CATM(Spec_instance_, name) = new qcp_CATM(Spec_, name);\
    qcp_CATM(Spec_, name) :: qcp_CATM(Spec_, name)() : Spec(#name)

}

#endif // qcp_SPECIFICATION_H
