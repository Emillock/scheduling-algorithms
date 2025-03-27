#include <iostream>
#include "string"
#include "structs/output_struct.h"
#include "structs/p_struct.h"
#include "structs/test_case_struct.h"
#include "tests/test_cases.h"
#include "algs/fcfs.h"
#include "algs/sjf.h"

using namespace std;


int main() {
    int cnt = 0;

    for (const testCase &testCase: testCases) {
        cout << "Test number " << cnt++ << endl;

        algOut resFcfs = fcfs(testCase.processes);
        algOut resSjf = sjf(testCase.processes);
        algOut expected = testCase.fcfsRes;
        cout<<"FCFS Results: ";
        cout << "order: ";
        for (const string &s: resFcfs.pOrder) cout << s << " ";
        cout << (resFcfs.pOrder == expected.pOrder ? "+" : "-") << endl;

        cout << "avgTurnaround: " << resFcfs.avgTurnaround <<
             (resFcfs.avgTurnaround == expected.avgTurnaround ? " +" : " -") << endl;

        cout << "avgWait: " << resFcfs.avgWait <<
             (resFcfs.avgWait == expected.avgWait ? " +" : " -") << endl;

        cout << endl;

        cout<<"SJF Results: ";
        cout << "order: ";
        for (const string &s: resSjf.pOrder) cout << s << " ";
        cout << (resSjf.pOrder == expected.pOrder ? "+" : "-") << endl;

        cout << "avgTurnaround: " << resSjf.avgTurnaround <<
             (resSjf.avgTurnaround == expected.avgTurnaround ? " +" : " -") << endl;

        cout << "avgWait: " << resSjf.avgWait <<
             (resSjf.avgWait == expected.avgWait ? " +" : " -") << endl;

        cout << endl;
    }

    return 0;
}
