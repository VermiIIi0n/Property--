#define BOOST_UT_DISABLE_MODULE
#include "ut.hpp"
#include "property.hpp"

using namespace boost::ut;
using namespace ppp;

class A
{
    int _i = 0;

public:
    Property<int> i{
        [this]() -> int
        { return this->_i; },
        [this](const int v)
        { this->_i = v; }};

    Property<int &> i2{
        [this]() -> int &
        { return this->_i; },
        [this](const int &v)
        { this->_i = v; }};

    Property<const int &> i3{
        [this]() -> const int &
        { return this->_i; },
        [this](const int &v)
        { this->_i = v; }};

    // Property<int &&> i4{
    //     [this]() -> int&& { return std::move(this->_i); },
    //     [this](const int&& v) { this->_i = std::move(v); }
    // };

    const Property<int> ci{
        [this]() -> int
        { return this->_i; }};

    const Property<int &> ci2{
        [this]() -> int &
        { return this->_i; }};

    const Property<const int &> ci3{
        [this]() -> const int &
        { return this->_i; }};

    Property<int> i_ro{
        [this]() -> int
        { return this->_i; }};
};

int main()
{
    A a, a1;
    expect(0_i == a.i);
    a.i = 1;
    expect(1_i == a.i);
    a.i2 = 2;
    expect(2_i == a.i2);
    a.i3 = 3;
    expect(3_i == a.i3);
    // a.i4 = 4;
    // expect(4_i == a.i4);

    expect(3_i == a.ci);
    expect(3_i == a.ci2);
    expect(3_i == a.ci3);

    expect(0_i == a1.i);

    static_assert(std::is_same_v<decltype(a.i()), int>);
    static_assert(std::is_same_v<decltype(a.i2()), int &>);
    static_assert(std::is_same_v<decltype(a.i3()), const int &>);
    // static_assert(std::is_same_v<decltype(a.i4()), int&&>);
    static_assert(std::is_same_v<decltype(a.ci()), int>);
}