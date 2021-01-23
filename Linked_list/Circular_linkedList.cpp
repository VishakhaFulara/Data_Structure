//Program to create and display circular linked list.
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct node{
	int data;
	struct node *link;
}node;

node* get_node(int ele){
	node* newnode=(node *)malloc(sizeof(node));
	newnode->data=ele;
	newnode->link=NULL;
	return newnode;
}

void create(node **head,node **tail,int ele){
	node* newnode=get_node(ele);
	if(*head==NULL){
		(*head)=newnode;
		(*tail)=newnode;
		return;
	}
	(*tail)->link=newnode;
	(*tail)=newnode;
	(*tail)->link=*head;

}


void display(node *head){
	node* temp=head;
	if(head==NULL){
		return;                       //empty linked list
	}
	while(temp->link!=head){
		printf("%d  ",temp->data);
		temp=temp->link;
	}
	printf("%d  ",temp->data);
}
int main()
{
	node *head=NULL,*tail=NULL;                    //empty linked list
	int ele,ch;
	do{
		system("cls");
		printf("\t\t.....MENU......\n");
		printf("\t\t1.creating node\n");
		printf("\t\t2.Display circular linked list\n");
		printf("\t\t3.Exit\n");
		printf("\t\tPlease enter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:{
					printf("enter element you want to insert:");
					scanf("%d",&ele);
					create(&head,&tail,ele);
					break;
				}
			case 2:{
					printf("circular linked list is:");
					display(head);
					getch();
					break;
			}
			case 3:{
					break;
				}
			default:printf("Wrong choice....\n");
			break;
		}
	}
	while(ch!=3);
	return 0;
}
	
