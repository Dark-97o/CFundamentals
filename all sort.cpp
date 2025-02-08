#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shellsort(int arr[], int size) {
    int gap, i, j;
    for (gap = size / 2; gap >= 1; gap /= 2) {
        for (j = gap; j < size; j++) {
            for (i = j - gap; i >= 0; i -= gap) {
                if (arr[i + gap] > arr[i]) {
                    break;
                } else {
                    swap(&arr[i + gap], &arr[i]);
                }
            }
        }
    }
}

void quicksort(int arr[], int start, int end) {
    if (start < end) {
        int pivot = start, i = start + 1, j = end;
        while (i <= j) {
            while (arr[i] <= arr[pivot] && i < end) i++;
            while (arr[j] > arr[pivot]) j--;
            if (i < j) swap(&arr[i], &arr[j]);
        }
        swap(&arr[pivot], &arr[j]);
        quicksort(arr, start, j - 1);
        quicksort(arr, j + 1, end);
    }
}

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void merge_sort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int choice, size;
    int arr[100];

    printf("Enter the size of array (max 100): ");
    scanf("%d", &size);

    printf("Enter the elements of array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nSort operation:");
        printf("\n1 for Shell Sort\n2 for Quick Sort\n3 for Merge Sort\n4 for Bubble Sort\n5 for Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                shellsort(arr, size);
                printf("Array after Shell Sort: ");
                print_array(arr, size);
                break;
            case 2:
                quicksort(arr, 0, size - 1);
                printf("Array after Quick Sort: ");
                print_array(arr, size);
                break;
            case 3:
                merge_sort(arr, 0, size - 1);
                printf("Array after Merge Sort: ");
                print_array(arr, size);
                break;
            case 4:
                bubble_sort(arr, size);
                printf("Array after Bubble Sort: ");
                print_array(arr, size);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid input. Please try again.\n");
        }
    }
    return 0;
}

