#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int arr[], int n){
	
	for(int i=1;i<n;i++){
		int temp=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>temp){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
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
	insertion_sort(arr,n);
	printf("After sorting the array: ");
	display(arr,n);
	
}
