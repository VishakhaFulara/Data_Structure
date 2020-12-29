//Wap to implement Queue using array.
#include<stdio.h>
int enqueue(int rear,int size,int queue[],int ele,int front){
	if(rear==size-1){
		printf("Queue Overflow");
	}
	else{
		if(front==-1){
			front=0;
		}
		rear++;
		queue[rear]=ele;
	}
	return rear;
}
int dequeue(int rear,int front,int queue[]){
	if(rear==-1||front>rear){
		printf("Queue underflow");
	}
	else{
		if(front==-1){
			front=0;
		}
		printf("Deleted elememts is %d\n",queue[front]);
		front++;
	}
	return front;
}
void display(int rear,int front,int queue[]){
	int i;
	if(rear==-1||front>rear){
		printf("Queue underflow");
	}
	else{
		printf("Queue elements are:\n");
		if(front==-1){
			front=0;
		}
		for(i=front;i<=rear;i++)
			printf("%d  ",queue[i]);
	}
}
int main(){
	int front=-1,rear=-1,ch,n,ele;
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
					rear=enqueue(rear,n,queue,ele,front);
					break;
			case 2:front=dequeue(rear,front,queue);
					break;
			case 3:display(rear,front,queue);
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


