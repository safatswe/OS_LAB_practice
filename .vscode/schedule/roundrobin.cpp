#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime = 0;
    int waitingTime = 0;
    int turnaroundTime = 0;
};

int main() {
    int n, quantum;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter arrival time and burst time for process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].id = i + 1;
        processes[i].remainingTime = processes[i].burstTime;
    }

    cout << "Enter time quantum: ";
    cin >> quantum;

    // Sort processes by arrival time
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.arrivalTime < b.arrivalTime;
    });

    queue<int> q;
    int time = 0, completed = 0;
    vector<bool> inQueue(n, false);

    while (completed < n) {
        // Add all processes that have arrived to the queue
        for (int i = 0; i < n; ++i) {
            if (processes[i].arrivalTime <= time && !inQueue[i] && processes[i].remainingTime > 0) {
                q.push(i);
                inQueue[i] = true;
            }
        }

        if (!q.empty()) {
            int idx = q.front();
            q.pop();

            int execTime = min(quantum, processes[idx].remainingTime);
            processes[idx].remainingTime -= execTime;
            time += execTime;

            // Add newly arrived processes during execution
            for (int i = 0; i < n; ++i) {
                if (processes[i].arrivalTime <= time && !inQueue[i] && processes[i].remainingTime > 0) {
                    q.push(i);
                    inQueue[i] = true;
                }
            }

            if (processes[idx].remainingTime > 0) {
                q.push(idx);
            } else {
                processes[idx].completionTime = time;
                processes[idx].turnaroundTime = processes[idx].completionTime - processes[idx].arrivalTime;
                processes[idx].waitingTime = processes[idx].turnaroundTime - processes[idx].burstTime;
                completed++;
            }
        } else {
            time++;
        }
    }

    // Display results
    cout << "\nProcess\tAT\tBT\tWT\tTAT\n";
    double totalWT = 0, totalTAT = 0;
    for (const auto& p : processes) {
        cout << "P" << p.id << "\t" << p.arrivalTime << "\t" << p.burstTime
             << "\t" << p.waitingTime << "\t" << p.turnaroundTime << "\n";
        totalWT += p.waitingTime;
        totalTAT += p.turnaroundTime;
    }

    cout << "Average Waiting Time: " << totalWT / n << endl;
    cout << "Average Turnaround Time: " << totalTAT / n << endl;

    return 0;
}
