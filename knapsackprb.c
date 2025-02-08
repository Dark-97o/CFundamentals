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
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    return (item2->ratio > item1->ratio) - (item2->ratio < item1->ratio);
}

double fractionalKnapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare);
    double totalValue = 0.0;
    int remainingWeight = capacity;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingWeight) {
            totalValue += items[i].value;
            remainingWeight -= items[i].weight;
        } else {
            totalValue += items[i].ratio * remainingWeight;
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
    printf("Maximum value the thief can carry: %.2f\\n", maxValue);
    return 0;
}
