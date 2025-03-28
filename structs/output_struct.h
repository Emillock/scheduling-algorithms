//
// Created by User on 07.03.2025.
//

#ifndef THREADS_AS_1_THREAD_DATA_TYPE_H
#define THREADS_AS_1_THREAD_DATA_TYPE_H
#include "string"
#include "vector"
using namespace std;

struct algOut{
    vector<string> pOrder;
    vector<int> cTimes;
    vector<int> tTimes;
    vector<int> wTimes;
    float  avgTurnaround;
    float  avgWait;
};

#endif //THREADS_AS_1_THREAD_DATA_TYPE_H