//
// Created by User on 07.03.2025.
//

#ifndef THREADS_AS_1_THREAD_DATA_TYPE_H
#define THREADS_AS_1_THREAD_DATA_TYPE_H
#include "string"
#include "vector"
using namespace std;

struct algOut{ // structure of data passed to reader/writer as an object (change it if different arguments are needed)
    vector<string> pOrder;
    float  avgTurnaround;
    float  avgWait;
};

#endif //THREADS_AS_1_THREAD_DATA_TYPE_H