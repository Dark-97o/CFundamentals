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
                Job temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }
}

void job_sequencing(Job jobs[], int n) {
    sortJobs(jobs, n);
    int dmax = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > dmax)
            dmax = jobs[i].deadline;
    }
    bool time_slots[dmax];
    for (int i = 0; i < dmax; i++)
        time_slots[i] = false;
    char* result[dmax];
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

    printf("Sequenced Jobs:\n");
    for (int i = 0; i < dmax; i++) {
        if (time_slots[i])
            printf("%d> %s\n",i+1, result[i]);
    }
    printf("Total Profit: %d\n", total_profit);
}

int main() {
    Job jobs[] = {
        {"Customer 1 \t Maruti Wagon R", 5, 500},
        {"Customer 2 \t Nisan Micra", 3, 400},
        {"Customer 3 \t Toyota Innova", 3, 1200},
        {"Customer 4 \t TATA Neon", 2, 700},
        {"Customer 5 \t Renault Kiger", 4, 750},
        {"Customer 6 \t Maruti Grand Vittara", 2, 1100}
    };
    int n = sizeof(jobs)/sizeof(jobs[0]);
    job_sequencing(jobs, n);
    return 0;
}
