#include "UnitTest.h"

namespace qcp { namespace unittest {

class NoFixture {};

void nop() {}

class FunctionTest : public ::testing::Test {
public:
    FunctionTest(function<void()> function) 
        : function_(function) 
    {}

private:
    const function<void()> function_;

    void TestBody() override { function_(); }
};

class TestFactory : public ::testing::internal::TestFactoryBase {
public:
    TestFactory(function<void()> function) 
        : function_(function) {}
    
    ::testing::Test* CreateTest() override {
        return new FunctionTest(function_);
    }

private:
    const function<void()> function_;
};

void Register(const string& spec_name, const string& prop_name, function<void()> test) {
    static auto fixture_class_id = ::testing::internal::GetTypeId<NoFixture>();
    ::testing::internal::MakeAndRegisterTestInfo(spec_name.c_str(), prop_name.c_str(), nullptr, nullptr,
        fixture_class_id, nop, nop, new TestFactory(test));
}

}}