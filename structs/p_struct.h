//
// Created by User on 25.03.2025.
//

#ifndef UNTITLED3_P_STRUCT_H
#define UNTITLED3_P_STRUCT_H
#include "string"
#include "vector"
using namespace std;

struct process{ // structure of data passed to reader/writer as an object (change it if different arguments are needed)
    string id;
    int  cTime;
    int aTime;
    int priority;
};
#endif //UNTITLED3_P_STRUCT_H
