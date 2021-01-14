//Implementation of stack using linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

struct node *top=NULL;           //declare & initialize the global variable      

//push operation for inserting data
void push(int ele){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=ele;
	temp->link=top;
	top=temp;	
}

void pop(){
	struct node *temp;
	if(top==NULL) return ;
	temp=top;
	top=top->link;
	free(temp);
}
void display(){
	struct node *x=top;
	if(x==NULL) return;
	printf("Stack elements are:\n");
	while(x!=NULL){
		printf("%d\n",x->data);
		x=x->link;
	}
}
int main(){
	int ch,ele;
	printf("\t.....MENU.....\n\t1.Push\n\t2.Pop\n\t3.Display\n\t4.Exit\n");
	do{
		printf("enter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:{
				printf("enter element you want to insert:");
				scanf("%d",&ele);
				push(ele);
				break;
			}
			case 2:{
				pop();
				break;
			}
			case 3:{
				display();
				break;
			}
			case 4:{
				printf("..........EXIT.........\n");
				break;
			}
			default:{
				printf("Wrong choice......\n");
				break;
			}
		}
	}
	while(ch!=4);
	return 0;
}
