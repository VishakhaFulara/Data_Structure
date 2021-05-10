//BST implementation
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

//function to search an element in a BST
int search(bstnode* root,int ele){
	if(root==NULL){							 //empty tree
        return 0;
    }
    //exit condition
    else if(root->data==ele){            
    	return 1;
	}
    else if(ele<=root->data){
    	return search(root->left,ele);
    }
    else{
       return search(root->right,ele);
    }
}

int main(){
    bstnode *root=NULL;                         //empty BST
    int data;
    root=insert(root,20);
    root=insert(root,50);
    root=insert(root,3);
    root=insert(root,455);
    root=insert(root,34);
    
    printf("enter the element you want to search:");
    scanf("%d",&data);
	
    if(search(root,data)){
    	printf("\nfound!!!");
	}
	else{
		printf("\nNot found!!!");
	}
    return 0;

}
