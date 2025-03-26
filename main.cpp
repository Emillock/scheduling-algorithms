#include <iostream>
#include "string"
#include "structs/output_struct.h"
#include "structs/p_struct.h"
#include "tests/test_cases.h"
#include "algos/fcfs.h"

using namespace std;



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
