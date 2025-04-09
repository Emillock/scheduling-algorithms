//
// Created by User on 09.04.2025.
//

#ifndef UNTITLED3_RR_H
#define UNTITLED3_RR_H
#include <iostream>
#include <map>
#include <algorithm>
#include "../structs/p_struct.h"
#include "../structs/output_struct.h"
#include "../utils/round_func.h"
using namespace std;

algOut roundRobin(const vector<process> &processes, int quantum) {
    unsigned long long n=processes.size();
    vector<int> remaining_burst; // Remaining burst times
    vector<int> waiting_time;   // Waiting times
    vector<int> turnaround_time;  // Turnaround times
    vector<int> completion_time; // Completion times
    vector<int> start_time;      // Start times
    vector<int> end_time;     // End times
    int current_time = 0;    // Current time tracker
    int completed = 0;       // Number of completed processes
    vector<int> executed;      // To track if a process started execution
    vector<string> order;
    // Initialize remaining burst times
    for (int i = 0; i < n; i++) {
        remaining_burst[i] = processes[i].bTime;
        waiting_time[i] = 0;
        executed[i] = 0;
    }

    printf("\nRound Robin Scheduling:\n");
    printf("\nProcess | Arrival Time | Burst Time | Start Time | End Time | Completion Time | Turnaround Time | Waiting Time\n");
    printf("--------------------------------------------------------------------------------------------------------------\n");

    // Process queue execution loop
    while (completed < n) {
        int has_executed = 0;  // Flag to check if any process was executed in this cycle

        for (int i = 0; i < n; i++) {
            if (remaining_burst[i] > 0) {
                has_executed = 1; // At least one process is executing

                if (!executed[i]) {
                    start_time[i] = (current_time < processes[i].aTime) ? processes[i].aTime : current_time;
                    executed[i] = 1;
                }

                int execution_time = (remaining_burst[i] > quantum) ? quantum : remaining_burst[i];
                remaining_burst[i] -= execution_time;
                current_time += execution_time;
                end_time[i] = current_time;

                if (remaining_burst[i] == 0) {  // Process completed
                    order.push_back(processes[i].id);
                    completed++;
                    completion_time[i] = current_time;
                    turnaround_time[i] = completion_time[i] - processes[i].aTime;
                    waiting_time[i] = turnaround_time[i] - processes[i].bTime;
                }
            }
        }

        if (!has_executed) break; // If no process was executed, exit loop
    }
    // Calculate and print average waiting and turnaround times
    float avgWait = 0, avgTurnaround = 0;
    for (int i = 0; i < n; i++) {
        avgWait += waiting_time[i];
        avgTurnaround += turnaround_time[i];
    }
    avgWait /= processes.size();
    avgTurnaround /= processes.size();
    return {order, completion_time, turnaround_time, waiting_time, round2D(avgTurnaround), round2D(avgWait)};;
}

#endif //UNTITLED3_RR_H
