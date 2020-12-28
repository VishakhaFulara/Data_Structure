//Pre,in,post order traveral/depth first traversal

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

node *Find_min(node *root){
	node *current=root;
	while(current->left!=NULL){
		current=current->left;
	}
	return current;
}
node *delete(node *root,int k){
	if(root==NULL) 		return root;
	if(k<root->data){
		root->left=delete(root->left,k);
	}
	else if(k>root->data){
		root->right=delete(root->right,k);
	}
	else{
		//case 1:no child
		if(root->left==NULL && root->right==NULL){
			free(root);
			root=NULL;
		}
		
		//case 2:1 child
		else if(root->left==NULL){
			node *temp=root;
			root=root->right;
			free(temp);
		}
		else if(root->right==NULL){
			node *temp=root;
			root=root->left;
			free(temp);
		}
		
		//case 3:2 child
		else{
			node *temp=Find_min(root->right);
			root->data=temp->data;                    			//copy the data 
			root->right=delete(root->right,temp->data)	;		//delte the temp data
		}
	}
	return root;
}
//Printing in Preorder traversal
void Preorder(node *root){
	//base condition
	if(root==NULL)
		return;
		
	// first print data of node 
	else{
		printf("%d ",root->data);
	}

    // then recur on left subtree 
	Preorder(root->left);
	
	// now recur on right subtree 
	Preorder(root->right);
	
}

int main()
{
	int n,k;
	node* root=NULL;
	printf("\n\n\t\t.......MENU.........\n\t\t1.insert in BST \n\t\t2.Delete a node\n\t\t3.Display\n\t\t4.exit\n");
	while(1){
		printf("\nenter your choice:");
		scanf("%d",&n);
		switch(n){
			case 1:printf("\nenter the data :");
					scanf("%d",&k);
					root=insert(root,k);
					break;
			case 2:printf("\nenter the data to be deleted:");
					scanf("%d",&k);
					root=delete(root,k);
					break;
			case 3:printf("\nPreorder traversal of a BST is:");
					Preorder(root);
					break;
			case 4:exit(0);
			default:printf("incorrect choice\n");
		}
	}
}
