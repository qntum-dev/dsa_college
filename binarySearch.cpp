#include <stdio.h>
#include <stdlib.h>

int partition(int arr[],int start, int end){
	int pivot=arr[end];
	int i=start-1;
	for(int j=start;j<=end;j++){
		if(arr[j]<pivot){
			i++;
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	i++;
	int temp=arr[i];
	arr[i]=arr[end];
	arr[end]=temp;
	return i;
}

void quickSort(int arr[],int start, int end){
	if(end<=start){
		return;
	}
	int pivotIndex=partition(arr,start,end);
	quickSort(arr,start,pivotIndex-1);
	quickSort(arr,pivotIndex+1,end);
}

int binarySearch(int arr[],int low,int high,int target){
	
	if(low<=high){
		int mid = low+(high-low)/2;
		if(arr[mid]==target){
			
			return mid;
		}
		
		if(arr[mid]>target){
			return binarySearch(arr,low,mid-1,target);
		}
		else{
			return binarySearch(arr,mid+1,high,target);
		}
		
		return -1;
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
	int n=6;
	int arr[n]={4,5,6,7,8,9};
	display(arr,n);
	quickSort(arr,0,n-1);
	display(arr,n);
	int target=7;
	int pos=binarySearch(arr,0,n-1,target);
	if(pos!=-1){
		printf("\nElement %d is found at index %d",target, pos);
	}
	else{
		printf("\nElement %d not found",target);
	}
}
