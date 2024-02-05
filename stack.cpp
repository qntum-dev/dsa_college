// Stack using array

#include <stdio.h>
#include <stdlib.h>

int n,top=-1;

void push(int arr[],int data){
	if(top==n-1){
		printf("Stack overflow");
		return;
	}
	top++;
	arr[top]=data;
	printf("\n added %d to the stack",data);
}

int pop(int arr[]){
	if(top==-1){
		printf("Stack underflow");
		return -1;
	}
	int data=arr[top];
	top--;
	return data;
	
}

int peek(int arr[]){
	if(top==-1){
		printf("stack is empty");
		return -1;
	}
	return (arr[top]);
}

int main(){
	printf("Enter the size of the array :");
	scanf("%d",&n);
	int arr[n];
	printf("enter the element");

	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
//		push(arr,)	
	}
//	int ele;
//	printf("enter the element");
//	scanf("%d",ele);
	
	push(arr,1);
	push(arr,2);
	pop(arr);
	int data=peek(arr);
	printf("\n %d is at the top of the stack",data);
}


