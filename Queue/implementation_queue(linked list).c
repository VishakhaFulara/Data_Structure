#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *new_node(int ele){
	node *temp_node=(node *)malloc(sizeof(node));
	temp_node->data=ele;
	temp_node->next=NULL;
	return temp_node;
}
void enqueue(node **rear,int ele,node **front){
	if((*rear)==NULL && (*front)==NULL){
		(*rear)=new_node(ele);
		(*front)= *rear;
	}
	else {
		node *temp=new_node(ele);
		(*rear)->next=temp;
		*rear=temp;
	}
}
void dequeue(node **rear,node **front){
	node *temp=*front;
	if((*rear)==NULL){
		printf("Queue is empty");
		return;
	}
	printf("%d is deleted",temp->data);
	*front=temp->next;
	
	if(*front==NULL){
		(*rear)=NULL;
	}
	free(temp);	
}

void display(node *front,node *rear){
	node *temp=front;
	if(rear==NULL){
		printf("Queue is empty");
		return;
	}
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}
int main(){
	int ch,n,ele;
	node *front=NULL,*rear=NULL;
	printf("\tQueue Operation Using Linked list\t\n");
	printf("\t-------------------------------\t\n");
	printf("\t1.Enqueue\n \t2.Dequeue\n \t3.Display\n \t4.Exit\n");
	do{
		printf("\nEnter choice:");
		scanf("%d",&ch);	
		switch(ch){
			case 1:printf("enter elements you want to insert:");
					scanf("%d",&ele);
					enqueue(&rear,ele,&front);
					break;
			case 2:dequeue(&rear,&front);
					break;
			case 3:display(front,rear);
					break;
			case 4:printf("...EXIT POINT...");
					break;
			default:printf("....invalid choice....\n");
					break;	
	}
}
	while(ch!=4);
	return 0;
}



