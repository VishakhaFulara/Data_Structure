//level order traveral/breadth first traversal

#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;
node* newnode(int k)
{
	node* temp=( node*)malloc(sizeof( node));
	temp->data=k;
	temp->left=temp->right=NULL;
	return temp;
}

//inserting the node
node* insert(node* root,int k)
{
	if(root==NULL)
	{
		root=newnode(k);
		printf("\nnode created");
	}
	else if(k<=root->data)
		root->left=insert(root->left,k);
	else
		root->right=insert(root->right,k);
	return root;
}
//Printing the bst elements
int display(node *root,int level){
	if(root==NULL){
		return 0;
	}
	else if(level==0){
		printf("%d ",root->data);
		return 1;
	}
	int left=display(root->left,level-1);
	int right=display(root->right,level-1);
	
	return (left||right);
}

void level(node *root){
	int level=0;
	while(display(root,level)){
		level++;
	}
}

int main()
{
	int n,k;
	node* root=NULL;
	printf("\n\n\t\t.......MENU.........\n\t\t1.insert in BST \n\t\t2.Display..\n\t\t3.exit\n");
	while(1){
		printf("\nenter your choice:");
		scanf("%d",&n);
		switch(n){
			case 1:printf("\nenter the data :");
					scanf("%d",&k);
					root=insert(root,k);
					break;
			case 2:printf("\nlevel order traversal of a BST is:");
					level(root);
					break;
			case 3:exit(1);
			default:printf("incorrect choice\n");
		}
	}
}
