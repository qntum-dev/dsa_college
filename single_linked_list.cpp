#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node{
	int data;
	struct node *next;
};

struct node* createNode(int data){
	struct node* newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
};

void insertBeg(struct node** head,int data){
	struct node* newNode=createNode(data);
	if(*head==NULL){
		*head=newNode;
	}
	else{
		newNode->next=*head;
		*head=newNode;
	}
}

void insertEnd(struct node** head,int data){
	struct node* newNode=createNode(data);
	if(*head==NULL){
		*head=newNode;
	}
	else{
		struct node* temp=*head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newNode;
		
	}
}

void insertAtAny(struct node **head,int data, int pos){
	struct node* newNode= createNode(data);
	if(*head==NULL || pos==1){
		insertBeg(head,data);
	}
	else{
		struct node* temp = *head;
		int count=1;
		while(count<pos-1 && temp!=NULL){
			
			temp=temp->next;
			count++;
		}
		if(temp==NULL){
			printf("invalid position");
		}
		else{
			newNode->next=temp->next;
			
			temp->next=newNode;
		}
	}
}

void display(struct node **head){
	struct node *temp=*head;
	
	while(temp!=NULL){
		if(temp->next!=NULL){
			printf("%d->",temp->data);
		}
		else{
			printf("%d",temp->data);
		}
		temp=temp->next;
	}
}

int main(){
	struct node* head=createNode(2);
	insertBeg(&head,1);
	insertEnd(&head,3);
	insertAtAny(&head,4,2);
	
	display(&head);
}
