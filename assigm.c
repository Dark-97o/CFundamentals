#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int n = 50000;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    int x;
    printf("Enter the number to search: ");
    scanf("%d", &x);
    int result = binarySearch(arr, 0, n - 1, x);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");
    
    return 0;
}

// #define SIZE 50000

// void merge(int arr[], int left, int mid, int right) {
//     int i = left, j = mid + 1, k = 0;
//     int temp[right - left + 1];

//     while (i <= mid && j <= right) {
//         if (arr[i] < arr[j])
//             temp[k++] = arr[i++];
//         else
//             temp[k++] = arr[j++];
//     }

//     while (i <= mid) temp[k++] = arr[i++];
//     while (j <= right) temp[k++] = arr[j++];

//     for (i = left, k = 0; i <= right; i++, k++)
//         arr[i] = temp[k];
// }

// void mergeSort(int arr[], int left, int right) {
//     if (left < right) {
//         int mid = (left + right) / 2;
//         mergeSort(arr, left, mid);
//         mergeSort(arr, mid + 1, right);
//         merge(arr, left, mid, right);
//     }
// }

// int partition(int arr[], int low, int high) {
//     int pivot = arr[high], temp;
//     int i = low - 1;

//     for (int j = low; j < high; j++) {
//         if (arr[j] < pivot) {
//             i++;
//             temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//         }
//     }

//     temp = arr[i + 1];
//     arr[i + 1] = arr[high];
//     arr[high] = temp;

//     return i + 1;
// }

// void quickSort(int arr[], int low, int high) {
//     if (low < high) {
//         int pi = partition(arr, low, high);
//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }

// void generateRandomArray(int arr[], int size) {
//     for (int i = 0; i < size; i++) {
//         arr[i] = rand() % 10;
//     }
// }

// int main() {
//     srand(time(0));
//     int arr1[SIZE], arr2[SIZE];
//     generateRandomArray(arr1, SIZE);
//     for (int i = 0; i < SIZE; i++) arr2[i] = arr1[i];
//     printf("Generated random array\n");
//     mergeSort(arr1, 0, SIZE - 1);
//     printf("Merge Sort completed\n");
//     quickSort(arr2, 0, SIZE - 1);
//     printf("Quick Sort completed\n");
//     return 0;
// }