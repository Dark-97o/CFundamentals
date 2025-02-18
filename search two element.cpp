#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool findPairWithSumX(int arr[], int n, int X) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int currentSum = arr[left] + arr[right];

        if (currentSum == X) {
            printf("Pair found: %d and %d\n", arr[left], arr[right]);
            return true;
        } else if (currentSum < X) {
            left++;
        } else {
            right--;
        }
    }

    printf("No pair found with sum %d\n", X);
    return false;
}

int main() {
    int n, X;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the elements of the SORTED array (separated by spaces):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum (X): ");
    scanf("%d", &X);

    findPairWithSumX(arr, n, X);

    free(arr);

    return 0;
}
