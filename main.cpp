#include <iostream>
#include "string"
#include "structs/output_struct.h"
#include "structs/p_struct.h"
#include "structs/test_case_struct.h"
#include "tests/test_cases.h"
#include "algos/fcfs.h"

using namespace std;


int main() {
    int cnt = 0;

    for (const testCase &testCase: testCases) {
        cout << "Test number " << cnt++ << endl;

        algOut res = fcfs(testCase.processes);
        algOut expected = testCase.fcfsRes;
        cout << "order: ";
        for (const string &s: res.pOrder) cout << s << " ";
        cout << (res.pOrder == expected.pOrder ? "+" : "-") << endl;

        cout << "avgTurnaround: " << res.avgTurnaround <<
             (res.avgTurnaround == expected.avgTurnaround ? " +" : " -") << endl;

        cout << "avgWait: " << res.avgWait <<
             (res.avgWait == expected.avgWait ? " +" : " -") << endl;

        cout << endl;
    }

    return 0;
}
