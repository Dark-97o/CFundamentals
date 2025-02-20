#include <stdio.h>
#include <stdbool.h>

// Structure to represent a job
typedef struct {
    char* name;
    int deadline;
    int profit;
} Job;

// Function to sort jobs by profit in descending order
void sortJobs(Job jobs[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (jobs[i].profit < jobs[j].profit) {
                // Swap jobs
                Job temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }
}

// Function to perform job sequencing
void job_sequencing(Job jobs[], int n) {
    // Sort jobs by profit
    sortJobs(jobs, n);

    // Find maximum deadline to create time slots
    int max_deadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > max_deadline)
            max_deadline = jobs[i].deadline;
    }

    // Array to track free time slots
    bool time_slots[max_deadline];
    for (int i = 0; i < max_deadline; i++)
        time_slots[i] = false;

    // Array to store selected jobs
    char* result[max_deadline];
    int total_profit = 0;

    // Assign jobs to time slots
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (!time_slots[j]) {
                result[j] = jobs[i].name;
                time_slots[j] = true;
                total_profit += jobs[i].profit;
                break;
            }
        }
    }

    // Print the result
    printf("Selected Jobs:\n");
    for (int i = 0; i < max_deadline; i++) {
        if (time_slots[i])
            printf("%s\n", result[i]);
    }
    printf("Total Profit: %d\n", total_profit);
}

int main() {
    // Initialize jobs
    Job jobs[] = {
        {"Maruti Wagon R", 5, 500},
        {"Nisan Micra", 3, 400},
        {"Toyota Innova", 3, 1200},
        {"TATA Neyon", 2, 700},
        {"Renault Kiger", 4, 750},
        {"Maruti Grand Viattara", 2, 1100}
    };
    int n = sizeof(jobs)/sizeof(jobs[0]);

    // Perform job sequencing
    job_sequencing(jobs, n);

    return 0;
}
