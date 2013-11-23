#ifndef qcp_TO_STRING_H
#define qcp_TO_STRING_H

#include <string>
using std::string;

namespace qcp {

inline string to_s(int value) {
    return std::to_string(value);
}

inline string to_s(long value) {
    return std::to_string(value);
}

inline string to_s(long long value) {
    return std::to_string(value);
}

inline string to_s(unsigned value) {
    return std::to_string(value);
}

inline string to_s(unsigned long value) {
    return std::to_string(value);
}

inline string to_s(unsigned long long value) {
    return std::to_string(value);
}

inline string to_s(float value) {
    return std::to_string(value);
}

inline string to_s(double value) {
    return std::to_string(value);
}

inline string to_s(long double value) {
    return std::to_string(value);
}

template <typename T>
inline string to_s(const T& v) {
    return "<unknown>";
}

template <typename T, typename TAllocator>
inline string to_s(const vector<T, TAllocator>& v) {
    if (v.empty())
        return "[]";
    size_t kMax = 5;
    string text = "[";
    for (size_t i = 0; i < v.size() && i < kMax; ++i) {
        text += to_string(v[i]);
        text += ", ";
    }
    text.erase(text.end() - 2, text.end());
    if (v.size() > kMax)
        text += "... ";
    text.pop_back();
    return text + "]";
}

}

#endif // qcp_TO_STRING_H
