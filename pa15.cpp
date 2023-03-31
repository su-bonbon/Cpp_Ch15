/// @file pa15.cpp
/// @author Sujin Lee
/// @date 2022-04-28
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief Catch2 Unit tests for the recursive.hpp

#define CATCH_CONFIG_MAIN
#if defined __linux__
#include <catch.hpp>
#elif defined __MACH__
#include </opt/local/include/catch2/catch.hpp>
#else
#include "catch.hpp"
#endif

#include <iostream>
#include <cassert>
#include <initializer_list>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstddef>

#include "List.hpp"
#include "List.hpp"  // check include guard
#include "recursive.hpp"
#include "recursive.hpp"  // check include guard

TEMPLATE_TEST_CASE("size(Iter first, Iter last)", "", int, double, char) {
    List<TestType> list1 {};
    List<TestType> REF { 65, 66, 67, 68, 69, 70, 71, 72 };

    REQUIRE(cs202::size(list1.begin(), list1.end()) == 0);
    REQUIRE(cs202::size(REF.begin(), REF.end()) == 8);
}

TEMPLATE_TEST_CASE("count(Iter first, Iter last, const T& value)",
                   "", char, int, double) {
    const List<TestType> REF { 65, 66, 67, 68, 69, 70, 72, 72 };

    REQUIRE(cs202::count(REF.begin(), REF.end(), 65) == 1);
    REQUIRE(cs202::count(REF.begin(), REF.end(), 72) == 2);
    REQUIRE(cs202::count(REF.begin(), REF.end(), 99) == 0);
}


TEMPLATE_TEST_CASE("smallest(Iter first, Iter last)", "", char, int, double) {
    const List<TestType> REF { 65, 66, 67, 68, 69, 70, 71, 72 };
    const List<TestType> REF1 { 65, 66, 33, 68, 69, 70, 71, 72 };

    REQUIRE(*(cs202::smallest(REF.begin(), REF.end())) == 65);
    REQUIRE(*(cs202::smallest(REF1.begin(), REF1.end())) == 33);
}

TEMPLATE_TEST_CASE("largest(Iter first, Iter last)", "", char, int, double) {
    const List<TestType> REF { 65, 66, 67, 68, 69, 70, 71, 72 };
    const List<TestType> REF1 { 65, 99, 67, 68, 69, 70, 71, 72 };

    REQUIRE(*cs202::largest(REF.begin(), REF.end()) == 72);
    REQUIRE(*cs202::largest(REF1.begin(), REF1.end()) == 99);
}

TEMPLATE_TEST_CASE("sort(Iter first, Iter last)", "", char, int, double) {
    List<TestType> REF { 48, 49, 50, 65, 66, 67, 68, 69, 70, 71, 72};
    List<TestType> REF1 { 65, 66, 67, 68, 69, 70, 71, 72, 48, 49, 50 };

    CHECK(REF1 != REF);

    cs202::sort(REF1.begin(), REF1.end());

    CHECK(REF1 == REF);
}

TEST_CASE("fprint(Iter first, Iter last)<int>") {
    const List<int> REF { 65, 66, 67, 68, 69 };
    ostringstream actual;                        // memory output stream
    auto original = cout.rdbuf(actual.rdbuf());  // save/re-assign buffer
    constexpr auto EXPECTED = "65 66 67 68 69";

    cs202::fprint(REF.begin(), REF.end());
    cout.rdbuf(original);  // restore std::cout's original buffer
    CHECK(actual.str() == EXPECTED);
}

TEST_CASE("fprint(Iter first, Iter last)<double>") {
    const List<double> REF { 65, 66, 67, 68, 69 };
    ostringstream actual;                        // memory output stream
    auto original = cout.rdbuf(actual.rdbuf());  // save/re-assign buffer
    constexpr auto EXPECTED = "65.0 66.0 67.0 68.0 69.0";

    std::cout << std::fixed << std::showpoint << std::setprecision(1);

    cs202::fprint(REF.begin(), REF.end());
    cout.rdbuf(original);  // restore std::cout's original buffer
    CHECK(actual.str() == EXPECTED);
}

TEST_CASE("fprint(Iter first, Iter last)<char>") {
    const List<char> REF { 65, 66, 67, 68, 69 };
    ostringstream actual;                        // memory output stream
    auto original = cout.rdbuf(actual.rdbuf());  // save/re-assign buffer
    constexpr auto EXPECTED = "A B C D E";

    cs202::fprint(REF.begin(), REF.end());
    cout.rdbuf(original);  // restore std::cout's original buffer
    CHECK(actual.str() == EXPECTED);
}

TEST_CASE("rprint(Iter first, Iter last)<int>") {
    const List<int> REF { 65, 66, 67, 68, 69 };
    ostringstream actual;                        // memory output stream
    auto original = cout.rdbuf(actual.rdbuf());  // save/re-assign buffer
    constexpr auto EXPECTED = "69 68 67 66 65";

    cs202::rprint(REF.begin(), REF.end());
    cout.rdbuf(original);  // restore std::cout's original buffer
    CHECK(actual.str() == EXPECTED);
}
TEST_CASE("rprint(Iter first, Iter last)<double>") {
    const List<double> REF { 65, 67, 66, 69, 68 };
    ostringstream actual;                        // memory output stream
    auto original = cout.rdbuf(actual.rdbuf());  // save/re-assign buffer
    constexpr auto EXPECTED = "68.0 69.0 66.0 67.0 65.0";

    std::cout << std::fixed << std::showpoint << std::setprecision(1);

    cs202::rprint(REF.begin(), REF.end());
    cout.rdbuf(original);  // restore std::cout's original buffer

    CHECK(actual.str() == EXPECTED);
}
TEST_CASE("rprint(Iter first, Iter last)<char>") {
    const List<char> REF { 65, 67, 66, 69, 68 };
    ostringstream actual;                        // memory output stream
    auto original = cout.rdbuf(actual.rdbuf());  // save/re-assign buffer
    constexpr auto EXPECTED = "D E B C A";

    cs202::rprint(REF.begin(), REF.end());
    cout.rdbuf(original);  // restore std::cout's original buffer

    CHECK(actual.str() == EXPECTED);
}
TEST_CASE("pattern(unsigned n)") {
    ostringstream actual;                        // memory output stream
    auto original = cout.rdbuf(actual.rdbuf());  // save/re-assign buffer
    constexpr auto EXPECTED = "*\n**\n***\n****\n*****\n";

    pattern(5);

    cout.rdbuf(original);  // restore std::cout's original buffer

    CHECK(actual.str() == EXPECTED);
}
TEST_CASE("power(double base, int exp)") {
    CHECK((power(3.0, 2) - 9.0) < 0.0000001);
    CHECK((power(4.2, 3) - 74.088) < 0.0000001);
    CHECK((power(9.1, 0) - 1 )< 0.0000001);
}
