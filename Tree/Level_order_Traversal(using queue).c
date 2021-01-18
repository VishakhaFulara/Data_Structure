//Level order treversal
#include<stdio.h>
#include<stdlib.h>

typedef struct bstnode{
	int data;
	struct bstnode *left;
	struct bstnode *right;
}bstnode;

bstnode *new_node(int ele){
	bstnode *temp_node=(bstnode *)malloc(sizeof(bstnode));
	temp_node->data=ele;
	temp_node->left=NULL;
	temp_node->right=NULL;
	return temp_node;
}

bstnode* insert(bstnode *root,int ele){
	if(root==NULL){
		root=new_node(ele);
	}
	else if(ele<=root->data){
		root->left=insert(root->left,ele);
	}
	else{
		root->right=insert(root->right,ele);
	}
	return root;
}

void enqueue(bstnode *node,int *rear,bstnode **queue){
	queue[*rear]=node;
	(*rear)++;
}

bstnode *dequeue(int *front,bstnode **queue){
	(*front)++;
	return queue[*front-1];
}


void display_level_order(bstnode *root){
	bstnode **queue=(bstnode **)malloc(sizeof(bstnode*)*100);
	int rear=0,front=0;
	bstnode *temp=root;
	
	while(temp!=NULL){
		printf("%d\t",temp->data);
		
		//insert left chid 
		if(temp->left!=NULL){
			enqueue(temp->left,&rear,queue);
		}
		//insert right child 
		if(temp->right!=NULL){
			enqueue(temp->right,&rear,queue);
		}
		
		temp=dequeue(&front,queue);
	}
}


int main(){
	int ch,ele;
	bstnode *root=NULL;                             //empty bst
	printf("\n\n\t\t......MENU.......\n");
	printf("\t\t1.insert\n");
	printf("\t\t2.Display\n");
	printf("\t\t3.Exit\n");
	do{
		printf("enter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:{
					printf("\nenter element:");
					scanf("%d",&ele);
					root=insert(root,ele);
					break;
				}
			case 2:{
					display_level_order(root);
					break;
				}
			case 3:break;
			default:printf("INVALID CHOICE...........");
					break;
		}
	}
	while(ch!=3);
	return 0;
}
