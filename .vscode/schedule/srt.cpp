#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int id, arrivalTime, burstTime, remainingTime;
    int completionTime, turnaroundTime, waitingTime;
    bool isCompleted = false;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time and burst time for process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].id = i + 1;
        processes[i].remainingTime = processes[i].burstTime;
    }

    int completed = 0, time = 0;
    while (completed < n) {
        int idx = -1, minRT = INT32_MAX;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= time && processes[i].remainingTime > 0 && processes[i].remainingTime < minRT) {
                minRT = processes[i].remainingTime;
                idx = i;
            }
        }

        if (idx != -1) {
            processes[idx].remainingTime--;
            time++;
            if (processes[idx].remainingTime == 0) {
                processes[idx].completionTime = time;
                processes[idx].turnaroundTime = time - processes[idx].arrivalTime;
                processes[idx].waitingTime = processes[idx].turnaroundTime - processes[idx].burstTime;
                processes[idx].isCompleted = true;
                completed++;
            }
        } else {
            time++;
        }
    }

    double totalWT = 0, totalTAT = 0;
    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &p : processes) {
        cout << "P" << p.id << "\t" << p.arrivalTime << "\t" << p.burstTime << "\t"
             << p.completionTime << "\t" << p.turnaroundTime << "\t" << p.waitingTime << "\n";
        totalWT += p.waitingTime;
        totalTAT += p.turnaroundTime;
    }

    cout << "Average Waiting Time: " << totalWT / n << endl;
    cout << "Average Turnaround Time: " << totalTAT / n << endl;
    return 0;
}
