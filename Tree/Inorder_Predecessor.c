//Program to find Inorder Predecessor of a given node

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

// Function to Insert Node in a Binary Search Tree
node* insert(node* root,int k)
{
	if(root==NULL)
	{
		root=newnode(k);
	}
	else if(k<=root->data)
		root->left=insert(root->left,k);
	else
		root->right=insert(root->right,k);
	return root;
}

//Function to find some data in the tree
node *Find(node *root,int data){
	if(root==NULL){
		return root;
	}
	else if(root->data==data){            
    	return root;
	}
	else if(data<root->data){
		return Find(root->left,data);
	}
	else{
		return Find(root->right,data);
	}
}

//Function to find Node with maximum value in a BST
node *Find_min(node *root){
	if(root == NULL) return NULL;
	while(root->right != NULL)
		root = root->right;
	return root;
}

//Function to find Inorder predecessor in a BST
node* get_predecessor(node *root,int data)
{
	//search the node-O(h)
	node *cur=Find(root,data);
	if(cur==NULL){
		return NULL;
	}
	
	//case 1:node has left subtree
	if(cur->left!=NULL){   
		return Find_min(cur->left);           //O(h)
	}
	
	//case 2:No left subtree
	else{
		node *predecessor=NULL;
		node *ancestor=root;
		while(ancestor!=cur){
			if(cur->data>ancestor->data){
				predecessor=ancestor;					 // so far this is the deepest node for which current node is in right
				ancestor=ancestor->right;
			}
			else{
				ancestor=ancestor->left;
			}
		}
		return predecessor;
	}
}
void Inorder(node *root){
	//base condition
	if(root==NULL)
		return;

	Inorder(root->left);

	printf("%d ",root->data);
	
	Inorder(root->right);
	
}
int main()
{
	int n,k,ele;
	node* root=NULL,*predecessor;
	printf("\n\n\t\t.......MENU.........\n\t\t1.insert in BST \n\t\t2.Find Inorder predecessor\n\t\t3.Display\n\t\t4.exit\n");
	while(1){
		printf("\nenter your choice:");
		scanf("%d",&n);
		switch(n){
			case 1:printf("\nenter the data :");
					scanf("%d",&k);
					root=insert(root,k);
					break;
			
			case 2:printf("\nenter the data to be searched:");
					scanf("%d",&ele);
					predecessor=get_predecessor(root,ele);
					if(predecessor==NULL){
						printf("No predecessor Found\n");
					}
					else{
						printf("Inorder predecessor of %d is %d",ele,predecessor->data);
					}
					break;
			case 3:printf("\nInorder traversal of a BST is:");
					Inorder(root);
					break;
			case 4:break;
			default:printf("incorrect choice\n");
					break;
		}
	}
	return 0;
}
