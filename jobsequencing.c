#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char* name;
    int deadline;
    int profit;
} Job;

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

void job_sequencing(Job jobs[], int n) {
    sortJobs(jobs, n);
    int max_deadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > max_deadline)
            max_deadline = jobs[i].deadline;
    }

    bool time_slots[max_deadline];
    for (int i = 0; i < max_deadline; i++)
        time_slots[i] = false;
    char* result[max_deadline];
    int total_profit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (!time_slots[j]) {
                result[j] = jobs[i].name;
                time_slots[j] = true;
                total_profit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Selected Jobs:\n");
    for (int i = 0; i < max_deadline; i++) {
        if (time_slots[i])
            printf("%s\n", result[i]);
    }
    printf("Total Profit: %d\n", total_profit);
}

int main() {
    Job jobs[] = {
        {"1> Maruti Wagon R", 5, 500},
        {"2> Nisan Micra", 3, 400},
        {"3> Toyota Innova", 3, 1200},
        {"4> TATA Neyon", 2, 700},
        {"5> Renault Kiger", 4, 750},
        {"6> Maruti Grand Viattara", 2, 1100}
    };
    int n = sizeof(jobs)/sizeof(jobs[0]);
    job_sequencing(jobs, n);
    return 0;
}
