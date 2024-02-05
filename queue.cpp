#include <stdion.h>
#include <stdlib.h>
#include <malloc.h>

struct node{
	int data;
	strcut node* next;
};

struct queue{
	struct node* front;
	struct node* rear;
};

struct queue *push(struct queue *q,int val){
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(strcut node));
	ptr->data=val;
	ptr->next=NULL;
	if(q->front==NULL){
		q->front=ptr;
		q->rear=ptr;
		q->front->next=q->rear->next=NULL;
	}
	else{
		q->rear->next=ptr;
		q->rear=ptr;
		
	}
	return q;
}

struct queue *display(struct queue *q){
	struct node *ptr;
	ptr=q->front;
	if(ptr==NULL){
		printf("\n QUEUE is empty");
	}
	else{
		printf("\n");
		while(ptr!=q->rear){
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
		printf("%d\t",ptr->data);
	}
	return q;
}
