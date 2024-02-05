#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

struct node* createNode(int data){
	struct node* newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->prev=NULL;
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
		(*head)->prev=newNode;
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
		newNode->prev=temp;
		
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
			newNode->prev=temp;
			newNode->next=temp->next;
			if(temp->next!=NULL){
				temp->next->prev=newNode;
				
			}
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
	printf("\n");
}

void deleteBeg(struct node** head){
	struct node* temp =*head;
	*head=(*head)->next;
	(*head)->prev=NULL;
	free(temp);
	
}

void deleteEnd(struct node** head){
	struct node* temp = *head;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	struct node* ptr=temp->next;
	temp->next=NULL;
	free(ptr);
}

void deleteAny(struct node** head, int pos){
	
	struct node* temp=*head;
	int count=0;
	while(count<pos-1 && temp!=NULL){
		temp=temp->next;
		count++;
	}
	if(temp->next!=NULL){
//		struct node* temp2=temp;
		temp->next->prev=temp->prev;
		
		
	}
	temp->prev->next=temp->next;
	
}
int main(){
	struct node* head=createNode(1);
	insertEnd(&head,2);
	insertEnd(&head,4);
	insertAtAny(&head,3,3);
	display(&head);
//	deleteAny(&head,3);
//	display(&head);
//	deleteAny(&head,3);
//	display(&head);
//	deleteAny(&head,2);
//	display(&head);
//	deleteAny(&head,1);
//	display(&head);
//	deleteEnd(&head);
//	display(&head);	
//	deleteEnd(&head);
//	display(&head);	
//	deleteEnd(&head);
//	display(&head);	
	deleteBeg(&head);
	display(&head);	
	deleteBeg(&head);
	display(&head);	
	deleteBeg(&head);
	display(&head);
}
