#ifndef qcp_UNITTESTAPI_H
#define qcp_UNITTESTAPI_H

#include <string>
using std::string;
#include <functional>
using std::function;

#include <gtest/gtest.h>
#define ASSERT(condition) ASSERT_TRUE(condition)

namespace qcp { namespace unittest {

void Register(const string& spec_name, const string& prop_name,
              function<void()> test);

}}

#endif // qcp_UNITTESTAPI_H
