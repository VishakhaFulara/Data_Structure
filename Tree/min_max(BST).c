//finding min amd max element in a BST

#include<stdio.h>
#include<stdlib.h>

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

//function to find min element-ITERATIVE METHOD
int FindMin(bstnode* root){
	if(root==NULL){
		printf("Error!!!...tree is empty\n");
		return -1;
	}
	else while(root->left!=NULL){
		root=root->left;
	}
	return root->data;
}
/*
//function to find min element-RECUSIVE METHOD
int FindMin(bstnode* root){
	if(root==NULL){
		printf("Error!!!...tree is empty\n");
		return -1;
	}
	//exit condition -for recursion
	else if(root->left==NULL) {
		return root->data;
	}
	FindMin(root->left);	
}

*/
//function to find max element-RECUSIVE METHOD
int FindMax(bstnode* root){
	if(root==NULL){
		printf("Error!!!...tree is empty\n");
		return -1;
	}
	else while(root->right!=NULL){
		root=root->right;
	}
	return root->data;
}
/*
//function to find max element-RECUSIVE METHOD
int FindMax(bstnode* root){
	if(root==NULL){
		printf("Error!!!...tree is empty\n");
		return -1;
	}
	//exit condition -for recursion
	else if(root->right==NULL) {
		return root->data;
	}
	FindMax(root->right);	
}
*/
int main(){
    bstnode *root=NULL;                         //empty BST
    root=insert(root,20);
    root=insert(root,50);
    root=insert(root,3);
    root=insert(root,455);
    root=insert(root,34);
    
	  printf("Minimum element in a BST is %d\n",FindMin(root));
	  printf("Maximum element in a BST is %d",FindMax(root));
    return 0;

}
