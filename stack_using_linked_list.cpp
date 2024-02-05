#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct stack{
	int data;
	struct stack *next;
};

struct stack *top = NULL;

struct stack *push(struct stack *top, int val){
	struct stack *ptr;
	ptr=(struct stack*)malloc(sizeof(struct stack));
	ptr->data =val;
	if(top == NULL){
		ptr->next=NULL;
		top = ptr;
	}
	else{
		ptr->next=top;
		top=ptr;		
	}

	return top;
}

struct stack *pop(struct stack *top){
	struct stack *ptr;
	ptr=top;
	if(top==NULL){
		printf("Stack underflow");
	}
	else{
		top=top->next;
		printf("\n the value being deleted is %d",ptr->data);
		free(ptr);
	}
	return top;
}

struct stack *display(struct stack *top){
	struct stack *ptr;
	ptr=top;
	if(top == NULL){
		printf("\n stack is empty");
	}
	else{
		printf("\n");
		while(ptr!=NULL){
			if(ptr->next!=NULL){
				printf("%d->",ptr->data);
			}
			else{
				printf("%d",ptr->data);
			}
			
			ptr=ptr->next;
		}
	}
}

void peek(struct stack *top){
	if(top==NULL){
		printf("stack is empty");
		return;
	}
	else{
	printf("\n The topmost element in the stack is %d",top->data);
	return;
	}
	
}

int main(){
	top=push(top,1);
	top=push(top,2);
	top=push(top,3);
	display(top);
	top=pop(top);
	display(top);
	top=push(top,4);
	display(top);


}
