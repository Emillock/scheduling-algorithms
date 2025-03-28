//
// Created by User on 27.03.2025.
//

#ifndef UNTITLED3_SJF_H
#define UNTITLED3_SJF_H

#include <map>
#include <algorithm>
#include "../structs/p_struct.h"
#include "../structs/output_struct.h"
#include "../utils/round_func.h"

algOut sjf(const vector<process> &processes) {
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
        if (aTimes.at(id1) != aTimes.at(id2))return aTimes.at(id1) < aTimes.at(id2);
        else return bTimes.at(id1) < bTimes.at(id2);
    });

    int t = aTimes.at(ids[0]) + bTimes.at(ids[0]);
    vector<string> order = {ids[0]};
    vector<string> queue;

    for (int i = 1; i < ids.size(); ++i) {
        if (aTimes.at(ids[i]) > t)break;
        queue.push_back(ids[i]);
    }

    if (queue.empty() && order.size() < ids.size()) {
        int prevT = t;
        t = aTimes.at(ids[order.size()]);
        for (auto &id: ids) {
            if (aTimes.at(id) <= prevT)continue;
            if (aTimes.at(id) > t)break;
            queue.push_back(id);
        }
    }

    sort(queue.begin(), queue.end(), [&](const string &id1, const string &id2) {
        return bTimes.at(id1) < bTimes.at(id2);
    });

    cout << endl;
    while (!queue.empty()) {
        order.push_back(queue[0]);
        int prevT = t;
        t += bTimes.at(queue[0]);
        queue.erase(queue.begin());
        for (auto &id: ids) {
            if (aTimes.at(id) <= prevT)continue;
            if (aTimes.at(id) > t)break;
            queue.push_back(id);
        }
        if (queue.empty() && order.size() < ids.size()) {
            prevT = t;
            t = aTimes.at(ids[order.size()]);
            for (auto &id: ids) {
                if (aTimes.at(id) <= prevT)continue;
                if (aTimes.at(id) > t)break;
                queue.push_back(id);
            }
        }
        sort(queue.begin(), queue.end(), [&](const string &id1, const string &id2) {
            return bTimes.at(id1) < bTimes.at(id2);
        });
    }


    int startT = aTimes.at(ids[0]);

    vector<int> cTimes;
    vector<int> tTimes;
    vector<int> wTimes;
    for (int i=0;i<ids.size();++i) {
        string id=ids[i];
        int cTime = startT + bTimes.at(id);
        cTimes.push_back(cTime);
        startT = i!=ids.size()-1 && aTimes.at(ids[i + 1]) > cTime ? aTimes.at(ids[i + 1]) : cTime;

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

    return {order, cTimes, tTimes, wTimes, round2D(avgTurnaround), round2D(avgWait)};
}

#endif //UNTITLED3_SJF_H
