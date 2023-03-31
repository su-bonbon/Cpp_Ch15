/// @file recursive.hpp
/// @author Sujin Lee
/// @date 4/27/2022
/// @note I pledge my word of honor that I have complied with the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief source file(function definitions)
/// @note 20hr
/// 2022-04-27: Sujin created
/// 2022-04-28: Sujin removed sum(Iter first, Iter last)

#ifndef RECURSIVE_HPP
#define RECURSIVE_HPP

#include <iostream>
#include <cassert>
#include <initializer_list>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <string>
#include <string_view>
#include <cstddef>

/// -------------------------------------------------------------
/// PROTOTYPES---------------------------------------------------
/// -------------------------------------------------------------
namespace cs202 {
template <class Iter> size_t size(Iter first, Iter last);
template <class Iter, class T> size_t count(Iter first, Iter last,
                                            const T& value);
//template <class Iter, class T> T sum(Iter first, Iter last);
template <class Iter> Iter smallest(Iter first, Iter last);
template <class Iter> Iter largest(Iter first, Iter last);
template <class Iter> void sort(Iter first, Iter last);
template <class Iter> void fprint(Iter first, Iter last);
template <class Iter> void rprint(Iter first, Iter last);
}  // namespace cs202

void pattern(unsigned n);
double power(double base, int exp);
/// -------------------------------------------------------------
/// DEFINITION---------------------------------------------------
/// -------------------------------------------------------------
template <class Iter> size_t cs202::size(Iter first, Iter last) {
    // base case
    if (first == last) {
        return 0;
    }
    // general case
    return 1 + cs202::size(++first, last);
}
/// -------------------------------------------------------------
template <class Iter, class T> size_t cs202::count(Iter first, Iter last,
                                            const T& value) {
    // base case
    if (first == last) {
        return 0;
    }
    // general case
    return *first == value ? 1 + cs202::count(++first, last, value)
                           : cs202::count(++first, last, value);
}
/// -------------------------------------------------------------
template <class Iter> Iter cs202::smallest(Iter first, Iter last) {
    Iter next = first;
    // base case
    if (first == last) {
        return last;
    } else if (++next == last) {
        return first;
    } else {
        Iter small = smallest(next, last);
        return (*first <= *small ? first : small);
    }
}
/// -------------------------------------------------------------
template <class Iter> Iter cs202::largest(Iter first, Iter last) {
    Iter next = first;
    // base case
    if (first == last) {
        return last;
    } else if (++next == last) {
        return first;
    } else {
        Iter large = largest(next, last);
        return (*first >= *large ? first : large);
    }
}
/// -------------------------------------------------------------
template <class Iter> void cs202::sort(Iter first, Iter last) {
    /*auto next = first;

    // base case
    if (first == last || ++next == last) {
        return;
    // general case
    } else if (next != nullptr) {
        if(*first > *next) {
            std::swap(first, next);
        }
        cs202::sort(next, last);
    }*/
    // general case
    if (first != last) {
        auto next = Iter(first).operator++();
        Iter min = smallest(first, last);

        if (*min != *first) {
            std::swap(*min, *first);
        }

        sort(next, last);
    // base case
    } else {
    }
}
/// -------------------------------------------------------------
template <class Iter> void cs202::fprint(Iter first, Iter last) {
    // base case
    if (first == last) {
        return;
    } else if (cs202::size(first, last) == 1) {
        std::cout << *first;
    } else {
    // general case
        std::cout << *first << ' ';
        cs202::fprint(++first, last);
    }
}
/// -------------------------------------------------------------
template <class Iter> void cs202::rprint(Iter first, Iter last) {
    auto next = first;
    // base case
    if (first == last) {
        return;
    } else if (cs202::size(first, last) == 1) {
        std::cout << *first;
    } else {
    // general case
        cs202::rprint(++next, last);
        std::cout << ' ' << *first;
    }

}
/// -------------------------------------------------------------
void pattern(unsigned n) {
    // base case
    if (n == 0) {
        return;
    }
    // general case
    pattern(n - 1);
    std::cout << std::string(n, '*') << std::endl;
}
/// -------------------------------------------------------------
double power(double base, int exp) {
    if (exp == 0) {
        return 1;
    }
    return base * (power(base, exp-1));
}
/// -------------------------------------------------------------
#endif /* RECURSIVE_HPP */
/* EOF */
