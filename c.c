#include <stdio.h>

// Structure to represent a process
struct Process {
    int pid;       // Process ID
    int at;        // Arrival Time
    int bt;        // Burst Time
    int ct;        // Completion Time
    int tat;       // Turnaround Time
    int wt;        // Waiting Time
};

// Function to sort processes by arrival time (FCFS Order)
void sortByArrival(struct Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

// Function to implement FCFS Scheduling
void fcfsScheduling(struct Process p[], int n) {
    int currentTime = 0;
    float totalWT = 0, totalTAT = 0;

    // Sorting the processes based on arrival time
    sortByArrival(p, n);

    // Calculating Completion Time, Turnaround Time, and Waiting Time
    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].at) {
            currentTime = p[i].at;  // If CPU is idle, move to process arrival time
        }
        p[i].ct = currentTime + p[i].bt;   // Completion Time
        p[i].tat = p[i].ct - p[i].at;      // Turnaround Time
        p[i].wt = p[i].tat - p[i].bt;      // Waiting Time

        // Update total waiting time and turnaround time
        totalWT += p[i].wt;
        totalTAT += p[i].tat;

        currentTime = p[i].ct; // Update the current time
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

    // Function call to execute FCFS scheduling
    fcfsScheduling(p, n);

    return 0;
}