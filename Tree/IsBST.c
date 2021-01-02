//Program to check whather a Binary tree is a Binary search tree or not.

#include<stdio.h>
#include<stdlib.h>
#include<limits.h> 
typedef struct bstnode{
    int data;
    struct bstnode *left;
    struct bstnode *right;
}bstnode;

bstnode* new_node(int ele)
{
    bstnode *temp=(bstnode *)malloc(sizeof(bstnode));
    temp->data=ele;
    temp->left=temp->right=NULL;
    return temp;
}

//function to insert an element
bstnode* insert(bstnode* root,int ele)
{
    if(root==NULL){							 //empty tree
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
int isbst_utility(bstnode *root,int min_val,int max_val){
	if(root==NULL){
		return 1;
	}
	if(root->data>min_val 
		&& root->data<max_val 
		&& isbst_utility(root->left,min_val,root->data) 
		&& isbst_utility(root->right,root->data,max_val)){
			return 1;
	}
	else{
		return 0;
	}
}
int isbst(bstnode *root){
	return isbst_utility(root,INT_MIN,INT_MAX);
}
int main(){
    bstnode *root=NULL;                         //empty BST
    int data;
    root=insert(root,20);
    root=insert(root,50);
    root=insert(root,3);
    root=insert(root,455);
    root=insert(root,34);
    
	if(isbst(root)){
		printf("Binary tree is a BST\n");
	}
	else{
		printf("Binary tree is not a BST\n");
	}
    return 0;
}
