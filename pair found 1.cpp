#include <stdio.h>

void intsum(int arr[], int sum2, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { 
            if (arr[i] + arr[j] == sum2) {
                printf("Pair found: %d, %d\n", arr[i], arr[j]);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum2;
    printf("Enter the sum: ");
    scanf("%d", &sum2);

    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

   
    intsum(arr, sum2, n);

    return 0;
}

