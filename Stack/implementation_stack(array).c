//Wap to implement stack using array
#include<stdio.h>
int push(int top,int size,int stack[],int ele)
	{
		int i;
		if(top==size-1){
			printf("stack is full");
		}
		else{
			top++;
			stack[top]=ele;
		}
	return top;
    } 
int pop(int top,int stack[],int ele){
	if(top==-1){
		printf("stack is empty");
	}
	else{
		printf("Elements to be poped is %d\n",stack[top]);
		top--;
	}
	return top;
}
void display(int top,int stack[]){
	int i;
	printf("stack elements are:\n");
	if(top!=-1){
		for(i=top;i>=0;i--)
			printf("%d\n",stack[i]);
		printf("enter next choice..\n");
	}
	else
		printf("stack empty");
}
int main(){
	int stack[100],top=-1,i,size,ch,ele;
	printf("enter maximum size of stack:");
	scanf("%d",&size);
	printf("\tStack Operation Using Array\t\n");
	printf("\t-------------------------------\t\n");
	printf("\t1.Push\n \t2.Pop\n \t3.Display\n \t4.Exit\n");
	do{
		printf("Enter choice:");
		scanf("%d",&ch);	
		switch(ch){
			case 1:printf("enter elements you want to push:");
					scanf("%d",&ele);
					top=push(top,size,stack,ele);
					break;
			case 2:top=pop(top,stack,ele);
					break;
			case 3:display(top,stack);
					break;
			case 4:printf("...EXIT POINT...");
					break;
			default:printf("....invalid choice....");
					break;	
		}
	}
	while(ch!=4);
	return 0;
}
