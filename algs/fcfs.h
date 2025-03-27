//
// Created by User on 26.03.2025.
//

#ifndef UNTITLED3_FCFS_H
#define UNTITLED3_FCFS_H
#include <map>
#include <algorithm>
#include "../structs/p_struct.h"
#include "../structs/output_struct.h"
#include "../utils/round_func.h"

algOut fcfs(const vector<process> &processes) {
    vector<string> ids;
    map<string, int> cTimes;
    map<string, int> aTimes;
    float avgTurnaround = 0;
    float avgWait = 0;

    for (const process &p: processes) {
        ids.push_back(p.id);
        cTimes.insert({p.id, p.cTime});
        aTimes.insert({p.id, p.aTime});
    }

    sort(ids.begin(), ids.end(), [&](const string &id1, const string &id2) {
        return aTimes.at(id1) < aTimes.at(id2);
    });

    int sum = 0;
    int aSum = 0;
    for (const string &id: ids) {
        int cTime = cTimes.at(id);
        avgTurnaround += sum + cTime;
        sum += cTime;

        int aTime = aTimes.at(id);
        bool isATimeBigger = aTime > aSum;
        avgWait += isATimeBigger ? aTime : aSum;
        if (isATimeBigger)aSum = aTime + cTime;
        else aSum += cTime;
    }
    avgWait /= processes.size();
    avgTurnaround /= processes.size();

    return {ids, round2D(avgTurnaround), round2D(avgWait)};
}

#endif //UNTITLED3_FCFS_H
