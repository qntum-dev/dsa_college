#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node{
	int data;
	struct node* next;
};

struct queue{
	struct node* front;
	struct node* rear;
};

void enqueue(int data, struct queue **q){
	struct node* newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=NULL;
	if((*q)->front==NULL){
		(*q)->front=newNode;
		(*q)->rear=newNode;
		(*q)->front->next=(*q)->rear->next=NULL;
	
	}
	else{
		(*q)->rear->next=newNode;
		(*q)->rear=newNode;
		(*q)->rear->next=NULL;
	}
}

void dequeue(struct queue **q){
	if((*q)->front==NULL){
		printf("underflow");
	}
	else{
		
		(*q)->front=(*q)->front->next;
	}
}

void displayQueue(struct queue **q){
	struct node* newNode=(*q)->front;
	
	while(newNode!= NULL){
		printf("%d",newNode->data);
		if(newNode->next!=NULL){
			printf("->");
		}
		newNode=newNode->next;
	}
	printf("\n");
}

void create_queue(struct queue **q){
	(*q)->front = NULL;
	(*q)->rear = NULL;
}

int main(){
	struct queue *q=(struct queue*)malloc(sizeof(struct queue));
	create_queue(&q);
	enqueue(1,&q);
	enqueue(2,&q);
	displayQueue(&q);
	dequeue(&q);
	displayQueue(&q);
}
