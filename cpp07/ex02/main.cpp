/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:30:53 by mykle             #+#    #+#             */
/*   Updated: 2025/05/26 12:36:36 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define RESET   "\033[0m"

int tests_passed = 0;
int tests_failed = 0;

void print_result(const std::string& test, bool passed) {
    if (passed) {
        std::cout << GREEN << "[PASS] " << RESET << test << std::endl;
        ++tests_passed;
    } else {
        std::cout << RED << "[FAIL] " << RESET << test << std::endl;
        ++tests_failed;
    }
}

void test_default_constructor() {
    Array<int> arr;
    print_result("Default constructor size == 0", arr.size() == 0);
    try {
        arr[0];
        print_result("Accessing empty array throws", false);
    } catch (...) {
        print_result("Accessing empty array throws", true);
    }
}

void test_size_constructor() {
    Array<int> arr(3);
    print_result("Size constructor size == 3", arr.size() == 3);
    bool zero = true;
    for (unsigned i = 0; i < arr.size(); ++i)
        if (arr[i] != 0) zero = false;
    print_result("Default int initialization", zero);

    Array<std::string> sarr(2);
    bool empty = true;
    for (unsigned i = 0; i < sarr.size(); ++i)
        if (!sarr[i].empty()) empty = false;
    print_result("Default string initialization", empty);
}

void test_copy_and_assignment() {
    Array<int> a(2);
    a[0] = 42; a[1] = 24;
    Array<int> b(a);
    print_result("Copy constructor copies values", b[0] == 42 && b[1] == 24);
    a[0] = 100;
    print_result("Copy is deep", b[0] == 42);

    Array<int> c;
    c = a;
    print_result("Assignment operator copies values", c[0] == 100 && c[1] == 24);
    a[1] = 200;
    print_result("Assignment is deep", c[1] == 24);
}

void test_operator_bracket() {
    Array<double> arr(2);
    arr[0] = 1.5; arr[1] = 2.5;
    print_result("operator[] assignment and access", arr[0] == 1.5 && arr[1] == 2.5);
    bool threw = false;
    try { arr[2]; } catch (...) { threw = true; }
    print_result("operator[] throws on out-of-bounds", threw);
}

void test_const_array() {
    Array<int> arr(1);
    arr[0] = 7;
    const Array<int> carr(arr);
    print_result("const operator[] access", carr[0] == 7);
}

int main() {
    test_default_constructor();
    test_size_constructor();
    test_copy_and_assignment();
    test_operator_bracket();
    test_const_array();
    std::cout << "\nSummary: " << tests_passed << " passed, " << tests_failed << " failed." << std::endl;
    return tests_failed ? 1 : 0;
}
