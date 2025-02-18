#include <stdio.h>
void swap(int *a,int *b){
	int temp = *a;
    *a = *b;
    *b = temp;
}
void quicksort(int arr[],int start, int end){
	int i,j,pivot;
	if(start<end){
		pivot=start;
	    i=start+1;
	    j=end;
	    if(i<=j){
	    	while(arr[i]<=arr[pivot]&&i<end)
	    	    i++;
	    	while(arr[j]>arr[pivot])
			    j--;
			if(i<j)
			    swap(&arr[i],&arr[j]);	    
		}
		swap(&arr[pivot],&arr[j]);
		quicksort(arr,start,j-1);
		quicksort(arr,j+1,end);
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
	quicksort(arr,0,size-1);
	printf("array after sorting:\n");
	for(i=0;i<size;i++){
		printf("%d\t",arr[i]);
	}
	return 0;
}
