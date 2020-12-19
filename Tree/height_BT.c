//Height of a Binary tree/ Maximum depth of a binary tree
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

//function to find height
int Find_height(bstnode* root){
	int h;
	
	//exit condition
	if(root==NULL)
		return -1;
	
	int left_height=Find_height(root->left);
	int right_height=Find_height(root->right);
	
	if(left_height>right_height){
		h=left_height+1;
	}
	else{
		h=right_height+1;
	}
	return h;
}


int main(){
    bstnode *root=NULL;                         //empty BST
    int data;
    root=insert(root,20);
    root=insert(root,50);
    root=insert(root,3);
    root=insert(root,455);
    root=insert(root,34);
    root=insert(root,2);
    root=insert(root,15);
    root=insert(root,11);
    root=insert(root,18);
    
    int h=Find_height(root);
    if(h>=0){
    	printf("Height of a binary tree is %d",h);
	}
	else{
		printf("\nEmpty binary tree!!!");
	}

    
    return 0;

}
