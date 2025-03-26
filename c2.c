#include <stdio.h>
#include <stdbool.h>

// Structure to store process details
struct Process {
    int pid;       // Process ID
    int at;        // Arrival Time
    int bt;        // Burst Time
    int ct;        // Completion Time
    int tat;       // Turnaround Time
    int wt;        // Waiting Time
    bool completed; // Flag to check if process is completed
};

// Function to find the next shortest job available
int findShortestJob(struct Process p[], int n, int currentTime) {
    int minIndex = -1;
    int minBurstTime = __INT_MAX__;

    for (int i = 0; i < n; i++) {
        if (!p[i].completed && p[i].at <= currentTime) { // Select only available processes
            if (p[i].bt < minBurstTime || (p[i].bt == minBurstTime && p[i].at < p[minIndex].at)) {
                minBurstTime = p[i].bt;
                minIndex = i;
            }
        }
    }
    return minIndex;
}

// Function to implement SJF Scheduling
void sjfScheduling(struct Process p[], int n) {
    int currentTime = 0;
    int completedProcesses = 0;
    float totalWT = 0, totalTAT = 0;

    // Mark all processes as incomplete
    for (int i = 0; i < n; i++) {
        p[i].completed = false;
    }

    while (completedProcesses < n) {
        int shortestJob = findShortestJob(p, n, currentTime);

        if (shortestJob == -1) {
            currentTime++; // No available process, so increment time
            continue;
        }

        // Process execution
        p[shortestJob].ct = currentTime + p[shortestJob].bt;  // Completion Time
        p[shortestJob].tat = p[shortestJob].ct - p[shortestJob].at; // Turnaround Time
        p[shortestJob].wt = p[shortestJob].tat - p[shortestJob].bt; // Waiting Time

        // Update total waiting time and turnaround time
        totalWT += p[shortestJob].wt;
        totalTAT += p[shortestJob].tat;

        currentTime = p[shortestJob].ct; // Update current time
        p[shortestJob].completed = true; // Mark process as completed
        completedProcesses++;
    }

    // Displaying Process Table
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    // Displaying Average Turnaround Time and Waiting Time
    printf("\nAverage Turnaround Time: %.2f", totalTAT / n);
    printf("\nAverage Waiting Time: %.2f\n", totalWT / n);
}

// Main function
int main() {
    int n;

    // Taking input for number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Taking input for process details
    printf("Enter Process ID, Arrival Time, and Burst Time:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &p[i].pid, &p[i].at, &p[i].bt);
    }

    // Function call to execute SJF scheduling
    sjfScheduling(p, n);

    return 0;
}