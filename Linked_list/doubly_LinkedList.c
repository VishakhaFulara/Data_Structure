//Program for inserting element in a linked list.
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
}node;

/////////////////// //////////function to get the node/////////////////////////
node* get_node(int ele){
	node *newnode=(node *)malloc(sizeof(node));
	newnode->data=ele;
	newnode->next=NULL;
	newnode->prev=NULL;
	return newnode;
}
////////////////////////////////insertion at begining///////////////////////////////
void insert_beg(node** head,int ele){
	node *newnode=get_node(ele);                        //calling the get_node()
	if(*head==NULL){
		(*head)=newnode;
		return;
	}
	newnode->next=(*head);
	(*head)->prev=newnode;
	*head=newnode;
}

/////////////////////////insertion at end///////////////////////////////
void insert_end(node** head,int ele){
	node* newnode=get_node(ele),*temp=*head;
	if(*head==NULL){
		(*head)=newnode;
		return;
	}
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;
}
//////////////////////////////////reversing doubly linked list///////////////////////////////
void reverse_list(node* head){
	node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	printf("\nReverse linked list is:");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->prev;
	}
}
/////////////////////Display doubly linked list//////////////////////////////
void display(struct node* head){
	if(head==NULL){
		return;               //linked list is empty
	}
	else{
		printf("%d ",head->data);
		display(head->next);
	}

}
///////////////////inserting node at any position/////////////////////////////////////////////
void insert_pos(node** head,int pos,int ele,int c){
	int i;
	node* newnode=get_node(ele),*temp=*head;
	if(*head==NULL){                  //empty linked list
		return;
	}
	//if you add node at 1st position
	if(pos==1)
	{
		insert_beg(head,ele);
		return;
	}
	
	//if inserting node at the end
	if(pos==c+1)
	{
		insert_end(head,ele);
		return ;
	}
	
	//if inserting node at the middle 
	for(i=0;i<pos-2;i++){
		temp=temp->next;
	}
	newnode->next=temp->next;
	temp->next=newnode;
	newnode->prev=temp;
	newnode->next->prev=newnode;
	
}

int main(){
	int i,x,n,pos,c=0;                          //c=no. of elements in a linked list
	node *head=NULL;                            //local variable
	printf("How many numbers at the begining?\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("enter the number:\n");
		scanf("%d",&x);
		c++;
		insert_beg(&head,x);
	}
	printf("List is:");
	display(head);
	reverse_list(head);
	
	//////////////////////////////////
	printf("\nHow many numbers at the end?\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("enter the number:\n");
		scanf("%d",&x);
		c++;
		insert_end(&head,x);
	}	
	printf("List is:");
	display(head);
	
	
	printf("\nenter the position where you want to add the element?\n");
	scanf("%d",&pos);
	printf("\nenter the number:\n");
	scanf("%d",&x);
	insert_pos(&head,pos,x,c);
	printf("List is:");
	display(head);
	return 0;
}

