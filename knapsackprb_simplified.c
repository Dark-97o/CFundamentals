#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 5
#define MAX_WEIGHT 60

typedef struct {
    int weight;
    int value;
    double ratio;
} Item;

int compare(const void *a, const void *b) {
    return ((Item *)b)->ratio - ((Item *)a)->ratio;
}

double fractionalKnapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare);
    double totalValue = 0.0;

    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += items[i].ratio * capacity;
            break;
        }
    }
    return totalValue;
}

int main() {
    Item items[MAX_ITEMS] = {
        {5, 30, 0},
        {10, 40, 0},
        {15, 45, 0},
        {22, 77, 0},
        {25, 90, 0}
    };

    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    double maxValue = fractionalKnapsack(items, MAX_ITEMS, MAX_WEIGHT);
    printf("Maximum value the thief can carry: %.2f", maxValue);
    return 0;
}
