#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 300

void mergeSort(int arr[], int left, int right);
void quickSort(int arr[], int low, int high);
void bubbleSort(int arr[], int n);
int binarySearch(int arr[], int left, int right, int x);
void printArray(int arr[], int size);
void generateRandomArray(int arr[], int size);

int main() {
    int arr[SIZE], choice, num, index;
    generateRandomArray(arr, SIZE);
    printf("1. Merge Sort\n2. Quick Sort\n3. Bubble Sort\n");
    printf("Choose a sorting technique: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            mergeSort(arr, 0, SIZE - 1);
            printf("Array sorted using Merge Sort\n");
            printf("Merge Sort: O(n log n)\n");
            break;
        case 2:
            quickSort(arr, 0, SIZE - 1);
            printf("Array sorted using Quick Sort\n");
            printf("Quick Sort: O(n log n) on average, O(n^2) worst case\n");
            break;
        case 3:
            bubbleSort(arr, SIZE);
            printf("Array sorted using Bubble Sort\n");
            printf("Bubble Sort: O(n^2)\n");
            break;
        default:
            printf("Invalid choice. Exiting...\n");
            return 0;
    }

    printf("Enter a number to search: ");
    scanf("%d", &num);
    
    index = binarySearch(arr, 0, SIZE - 1, num);
    if (index != -1)
        printf("Number found at index: %d\n", index);
    else
        printf("Number not found.\n");
    return 0;
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

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

void generateRandomArray(int arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

