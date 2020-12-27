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
//Printing in Inorder traversal
void Inorder(node *root){
	//base condition
	if(root==NULL)
		return;

	Inorder(root->left);

	printf("%d ",root->data);
	
	Inorder(root->right);
	
}
//Printing in Postorder traversal
void Postorder(node *root){
	//base condition
	if(root==NULL)
		return;

	Postorder(root->left);
	
	
	Postorder(root->right);
	
	printf("%d ",root->data);
}
int main()
{
	int n,k;
	node* root=NULL;
	printf("\n\n\t\t.......MENU.........\n\t\t1.insert in BST \n\t\t2.Preorder\n\t\t3.Inorder\n\t\t4.Postorder\n\t\t5.exit\n");
	while(1){
		printf("\nenter your choice:");
		scanf("%d",&n);
		switch(n){
			case 1:printf("\nenter the data :");
					scanf("%d",&k);
					root=insert(root,k);
					break;
			case 2:printf("\nPreorder traversal of a BST is:");
					Preorder(root);
					break;
			case 3:printf("\nInorder traversal of a BST is:");
					Inorder(root);
					break;
			case 4:printf("\nPostorder traversal of a BST is:");
					Postorder(root);
					break;
			case 5:exit(0);
			default:printf("incorrect choice\n");
		}
	}
}
