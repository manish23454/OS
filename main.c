#include <stdio.h>

struct process {
    int id;
    int burst_time; // Fixed the typo: "burrust_time" -> "burst_time"
};

void sjfScheduling(struct process processes[], int n) {
    // Sorting processes based on burst time using Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                struct process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Now print the order of execution and completion times
    int completion_time = 0;
    printf("Order of execution:\n");
    for (int i = 0; i < n; i++) {
        completion_time += processes[i].burst_time;
        printf("P%d (Completion time: %d)\n", processes[i].id, completion_time);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    sjfScheduling(processes, n);
    return 0;
}
