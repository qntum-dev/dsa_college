#include <stdio.h>
#include <stdlib.h>

void selection_sort(int arr[], int n){
	for(int i=0;i<n-1;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if(arr[min]>arr[j]){
				min=j;
			}
		}
		int temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
		
	}
}


void display(int arr[],int n){
	printf("The array is: [");
	for(int i=0;i<n;i++){
		if(i<n-1){
			printf("%d ",arr[i]);
		}
		else{
			printf("%d",arr[i]);
		}
		
	}
	printf("]");
}

int main(){
	int n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements of the array\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("\n");
	display(arr,n);
	printf("\n");
	selection_sort(arr,n);
	printf("After sorting the array: ");
	display(arr,n);
	
}
