//
// Created by User on 26.03.2025.
//

#ifndef UNTITLED3_FCFS_H
#define UNTITLED3_FCFS_H
#include <iostream>
#include <map>
#include <algorithm>
#include "../structs/p_struct.h"
#include "../structs/output_struct.h"
#include "../utils/round_func.h"

algOut fcfs(const vector<process> &processes) {
    vector<string> ids;
    map<string, int> bTimes;
    map<string, int> aTimes;
    float avgTurnaround = 0;
    float avgWait = 0;

    for (const process &p: processes) {
        ids.push_back(p.id);
        bTimes.insert({p.id, p.bTime});
        aTimes.insert({p.id, p.aTime});
    }

    sort(ids.begin(), ids.end(), [&](const string &id1, const string &id2) {
        return aTimes.at(id1) < aTimes.at(id2);
    });

    int startT = aTimes.at(ids[0]);

    vector<int> cTimes;
    vector<int> tTimes;
    vector<int> wTimes;
    for (int i = 0; i < ids.size(); ++i) {
        string id = ids[i];
        int cTime = startT + bTimes.at(id);
        cTimes.push_back(cTime);
        startT = i != ids.size() - 1 && aTimes.at(ids[i + 1]) > cTime ? aTimes.at(ids[i + 1]) : cTime;

        int aTime = aTimes.at(id);
        int bTime = bTimes.at(id);
        int tTime = cTime - aTime;
        tTimes.push_back(tTime);
        avgTurnaround += tTime;

        int wTime = tTime - bTime;
        wTimes.push_back(wTime);
        avgWait += wTime;
//        cout << id << " " << startT << " " << cTime << " " << tTime << " " << wTime << endl;
    }
    avgWait /= processes.size();
    avgTurnaround /= processes.size();

    return {ids, cTimes, tTimes, wTimes, round2D(avgTurnaround), round2D(avgWait)};
}

#endif //UNTITLED3_FCFS_H
