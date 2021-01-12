//Wap to implement Circular Queue using array.
#include<stdio.h>
void enqueue(int *rear,int n,int queue[],int ele,int *front){
	if(((*rear)+1)%n==(*front)){
		printf("Queue Overflow");
	}
	else if((*rear)==-1 && (*front)==-1){
			(*rear)=(*front)=0;
			queue[*rear]=ele;
	}
	else{
		(*rear)=((*rear)+1)%n;                //it make circular queue
		queue[*rear]=ele;
	}
}
void dequeue(int *rear,int *front,int queue[],int n){
	if((*rear)==-1 && (*front)==-1){
		printf("Queue underflow");
	}
	else if((*front)==(*rear)){
			printf("Deleted elememts is %d\n",queue[*front]);
			*front=*rear=-1;
		}
	else{
		printf("Deleted elememts is %d\n",queue[*front]);
		*front=((*front)+1)%n;
	}
}
void display(int *rear,int *front,int queue[],int n){
	int i=*front;
	if(*rear==-1 && (*front)==-1){
		printf("Queue underflow");
	}
	else{
		printf("Queue elements are:\n");
		while(i!=(*rear)){
			printf("%d  ",queue[i]);
			i=(i+1)%n;
		}
		printf("%d  ",queue[i]);
	}
}
int main(){
	int front=-1,rear=-1,ch,n,ele;								//front=rear=-1 (empty queue)
	printf("enter maximum size of queue:");
	scanf("%d",&n);
	int queue[n];
	printf("\tQueue Operation Using Array\t\n");
	printf("\t-------------------------------\t\n");
	printf("\t1.Enqueue\n \t2.Dequeue\n \t3.Display\n \t4.Exit\n");
	do{
		printf("\nEnter choice:");
		scanf("%d",&ch);	
		switch(ch){
			case 1:printf("enter elements you want to insert:");
					scanf("%d",&ele);
					enqueue(&rear,n,queue,ele,&front);
					break;
			case 2:dequeue(&rear,&front,queue,n);
					break;
			case 3:display(&rear,&front,queue,n);
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
