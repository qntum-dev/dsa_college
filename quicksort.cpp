#include <stdio.h>
#include <stdlib.h>

int partition(int arr[],int start, int end){
	int pivot=arr[end];
	int i=start-1;
	
	for(int j=start;j<=end-1;j++){
		if(arr[j]<pivot){
			i++;
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	
	i++;
	int temp = arr[i];
	arr[i]=arr[end];
	arr[end]=temp;
	
	return i;
}

void quickSort(int arr[], int start, int end){
	if(end<=start){
		return;
	}
	int pivot=partition(arr, start, end);
	quickSort(arr,start,pivot-1);
	quickSort(arr,pivot+1, end);
	
	
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
	quickSort(arr,0,n-1);
	printf("After sorting the array: ");
	display(arr,n);
	
}


