#include <stdio.h>
#include <stdlib.h>

// A structure to represent a job
typedef struct {
    char id;     // Job ID
    int deadline; // Deadline of job
    int profit;  // Profit if job is completed before or on deadline
} Job;

// Function to compare two jobs according to their profits
int compare(const void *a, const void *b) {
    Job *job1 = (Job *)a;
    Job *job2 = (Job *)b;
    return job2->profit - job1->profit;
}

// Function to print the sorted deadlines with respect to profit and job index
void job_sequencing(Job jobs[], int n) {
    // Sort all jobs according to decreasing order of profit
    qsort(jobs, n, sizeof(Job), compare);

    int result[n]; // To store result (sequence of jobs)
    int slot[n];   // To keep track of free time slots

    // Initialize all slots to be free
    for (int i = 0; i < n; i++)
        slot[i] = 0;

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (Note that we start from the last possible slot)
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            // Free slot found
            if (slot[j] == 0) {
                result[j] = i;  // Add this job to result
                slot[j] = 1;    // Mark this slot as occupied
                break;
            }
        }
    }

    // Print the result
    printf("Job sequence with maximum profit:\n");
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            printf("Job ID: %d, Deadline: %d, Profit: %d\n", jobs[result[i]].id, jobs[result[i]].deadline, jobs[result[i]].profit);
        }
    }
}

int main() {
    Job jobs[] = {{"Car", 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    job_sequencing(jobs, n);
    return 0;
}