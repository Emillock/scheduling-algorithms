//
// Created by User on 26.03.2025.
//

#ifndef UNTITLED3_TEST_CASES_H
#define UNTITLED3_TEST_CASES_H

#include "vector"
#include "../structs/p_struct.h"
#include "../structs/test_case_struct.h"

using namespace std;

vector<testCase> testCases = {
        {
                {
                        {"A", 24, 0, 0},
                        {"B", 3, 0, 0},
                        {"C", 4, 0, 0}
                },
                {
                        {"A", "B", "C"},
                        27.33,
                        17
                }
        },
        {
                {
                        {"A", 24, 15, 0},
                        {"B", 3, 10, 0},
                        {"C", 4, 5, 0}
                },
                {
                        {"C", "B", "A"},
                        14,
                        10
                }
        },
};

#endif //UNTITLED3_TEST_CASES_H
