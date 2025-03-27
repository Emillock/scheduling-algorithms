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
        if (aTimes.at(id1) != aTimes.at(id2))return aTimes.at(id1) < aTimes.at(id2);
        else return cTimes.at(id1) < cTimes.at(id2);
    });

    int t = aTimes.at(ids[0])+cTimes.at(ids[0]);
    vector<string> order = {ids[0]};
    vector<string> queue;

    for (int i = 1; i < ids.size(); ++i) {
        if (aTimes.at(ids[i]) > t)break;
        queue.push_back(ids[i]);
    }

    if(queue.empty() && order.size()<ids.size()){
        int prevT = t;
        t=aTimes.at(ids[order.size()]);
        for (auto &id: ids) {
            if (aTimes.at(id) <= prevT)continue;
            if (aTimes.at(id) > t)break;
            queue.push_back(id);
        }
    }

    sort(queue.begin(), queue.end(), [&](const string &id1, const string &id2) {
        return cTimes.at(id1) < cTimes.at(id2);
    });
    cout<<"queue: ";
    for(auto i:queue){
        cout<<i<<" ";
    }
    cout<<endl;
    while (!queue.empty()) {
        order.push_back(queue[0]);
        int prevT = t;
        t += cTimes.at(queue[0]);
        queue.erase(queue.begin());
        for (auto &id: ids) {
            if (aTimes.at(id) <= prevT)continue;
            if (aTimes.at(id) > t)break;
            queue.push_back(id);
        }
        if(queue.empty() && order.size()<ids.size()){
            prevT = t;
            t=aTimes.at(ids[order.size()]);
            for (auto &id: ids) {
                if (aTimes.at(id) <= prevT)continue;
                if (aTimes.at(id) > t)break;
                queue.push_back(id);
            }
        }
        sort(queue.begin(), queue.end(), [&](const string &id1, const string &id2) {
            return cTimes.at(id1) < cTimes.at(id2);
        });
    }


    int sum = 0;
    int aSum = 0;
    for (const string &id: order) {
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

    return {order, round2D(avgTurnaround), round2D(avgWait)};
}

#endif //UNTITLED3_SJF_H
