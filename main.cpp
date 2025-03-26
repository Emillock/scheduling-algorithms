#include <iostream>
#include <map>
#include <algorithm>
#include "string"
#include "structs/output_struct.h"
#include "structs/p_struct.h"
#include "utils/round_func.h"
#include "tests/test_cases.h"

using namespace std;

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

int main() {
    int cnt = 0;

    for (const vector<process> &processes: testCases) {
        cout << "Test number " << cnt++ << endl;

        algOut res = fcfs(processes);

        cout << "order: ";
        for (const string &s: res.pOrder) cout << s << " ";
        cout << endl;

        cout << "avgTurnaround: " << res.avgTurnaround << endl;

        cout << "avgWait: " << res.avgWait << endl;

        cout << endl;
    }

    return 0;
}
