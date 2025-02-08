#include <stdio.h>

void findTwoSum(int arr[], int n, int X) {
    int left = 0;          
    int right = n - 1;     

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == X) {
            printf("Elements found: %d and %d\n", arr[left], arr[right]);
            return;
        } else if (sum < X) {
            left++;        
        } else {
            right--;       
        }
    }

    
    printf("No such pair exists.\n");
}

int main() {
    int arr[] = {2, 4, 7, 11, 14, 16, 20, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    int X = 18;

    findTwoSum(arr, n, X);

    return 0;
}
