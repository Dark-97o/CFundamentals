#include <stdio.h>

// Question 2

void ruvariable(int arr[], int n, int var){
    int flag=0;
    for(int i=0;i<n;i++){
        if(arr[i]==var){
            flag=flag+1;
        }
    }
    printf("Total number of occurences: %d",flag);
}

int main(){
    int n;
    printf("Enter the length of an array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int sum2;
    printf("Enter number: ");
    scanf("%d",&sum2);
    printf("Entered array: ");
    for(int i=0;i<n;i++){
        printf("%d \t",arr[i]);
    }
    printf("\n");
    ruvariable(arr,n,sum2);
    return 0;
}

// Question 1 

// void intsum(int arr[],int n, int sum2){
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(arr[i]+arr[j]==sum2){
//                 printf("Pair Found with: %d %d \n",arr[i],arr[j]);
//             }
//         }
//     }
// }

// int main(){
//     int n;
//     printf("Enter the length of an array: ");
//     scanf("%d",&n);
//     int arr[n];
//     printf("Enter elements: ");
//     for(int i=0;i<n;i++){
//         scanf("%d",&arr[i]);
//     }
//     int sum2;
//     printf("Enter the sum: ");
//     scanf("%d",&sum2);
//     printf("Enter array: ");
//     for(int i=0;i<n;i++){
//         printf("%d \t",arr[i]);
//     }
//     printf("\n");
//     intsum(arr,n,sum2);
//     return 0;
// }