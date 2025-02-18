#include <stdio.h>
void swap(int *a,int *b){
	int temp = *a;
    *a = *b;
    *b = temp;
}
void shellsort(int arr[],int size){
	int gap,i,j;
	for(gap = (size)/2 ; gap>=1;gap/=2){
		for(j=gap; j<size; j++){
			for(i=j-gap;i>=0;i-=gap){
				if(arr[i+gap]>arr[i]){
					break;
				}
				else{
					swap(&arr[i+gap],&arr[i]);
				}
			}
		}
	}
}
int main(){
	int i,size;
	printf("Enter the size of array:");
	scanf("%d",&size);
	int arr[size];
	printf("Enter tha elements of array:");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	shellsort(arr,size);
	printf("array after sorting:\n");
	for(i=0;i<size;i++){
		printf("%d\t",arr[i]);
	}
	return 0;
}
