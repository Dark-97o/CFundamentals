#include <stdio.h>
void merge(int arr[],int low,int mid,int high);
void merge_sort(int arr[],int low,int high);
void merge_sort(int arr[],int low,int high){
	int mid;
	while(low<high){
		int mid=(low+high)/2;
	    merge_sort(arr,low,mid);
	    merge_sort(arr,mid+1,high);
	    merge(arr,low,mid,high);	
	}	
}
void merge(int arr[],int low,int mid,int high){
	int i,j,k;
	int n1=mid-low+1;
	int n2=high - mid;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
	    L[i]=arr[low+1];
    
	for(j=0;j<n2;j++)
	    R[j]=arr[mid+1+j];
	i=0;
    j=0;
	k=low; 
	while(i<n1&&j<n2){ 
	    if(L[i]<=R[j]){
	    	
		   arr[k]=L[i];
		   i++;
	    }
	    else{
		    arr[k]=R[j];
		    j++;
     	}
     	k++;
    }
    while(i<n1){
	   arr[k]=L[i];
	   i++;
	   k++;
    }
    while(j<n2){
	   arr[k]=R[j];
	   j++;
	   k++;
    }
}
void print_array(int arr[], int size) {
	int i;
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);
        printf("\n");
}

int main(){
	int i,n;
	printf("Enter the size of array:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter tha elements of array:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	merge_sort(arr,0,n-1);
	  printf("array after sorting");
	for(i=0;i,n;i++){
		printf("%d",arr[i]);
	}
	return 0;
}
    

