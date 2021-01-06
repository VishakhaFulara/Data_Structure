//Program for deletion in AVL tree
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node{
	int data;
	struct node *left,*right;
	int ht;
}node;
node *new_node(int x){
	node *temp=(node*)malloc(sizeof(node));
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

//Function to find height of a node
int height(node *root){
	int rh,lh;
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL)
		lh=0;
	else
		lh=1+root->left->ht;
	if(root->right==NULL)
		rh=0;
	else
		rh=1+root->right->ht;
	if(lh>rh){
		return lh;
	}
	return rh;
}

node *left_rotation(node *x){
	node *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht=height(x);
	y->ht=height(y);
	
	return(y);
}

node *right_rotation(node *x){
	node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return y;
}

node *LL(node *root){
	return right_rotation(root);
}

node *RR(node *root){
	return left_rotation(root);
}

node *LR(node *root){
	root->left=left_rotation(root->left);
	root=right_rotation(root);
	return root;
}
node *RL(node *root){
	root->right=right_rotation(root->right);
	root=left_rotation(root);
	return root;
}

//Function to find Balance factor for a node
int BF(node *root){
	int rh,lh;
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL)
		lh=0;
	else
		lh=1+root->left->ht;
	if(root->right==NULL)
		rh=0;
	else
		rh=1+root->right->ht;
		
	return lh-rh;
	
}
node *insert(node *root,int x){
	if(root==NULL){
		root=new_node(x);
	}
	//insert in left subtree
	else if(x<root->data){
		root->left=insert(root->left,x);
		if(BF(root)==2){
			if(x<root->left->data){
				root=LL(root);                  //left-left rotation
			}
			else{
				root=LR(root);					//left-right rotation
			}
		}
	}
	
	//insert in right subtree
	else{
		root->right=insert(root->right,x);
		if(BF(root)==-2){
			if(x>root->right->data){
				root=RR(root);                  //right-right rotation
			}
			else{
				root=RL(root);					//right-right rotation
			}
		}
	}
	root->ht=height(root);
	return root;
}

node *Find_min(node *root){
	node *current=root;
	while(current->left!=NULL){
		current=current->left;
	}
	return current;
}

//////////////////////////////////Function to delete a node/////////////////////////////////////////////
node *Delete(node *root,int k){
	if(root==NULL) {
		return root;
	}
	if(k<root->data){
		root->left=Delete(root->left,k);
		
		if(BF(root)==-2){								//Rebalancing
			if(BF(root->right)<=0){
				root=RR(root);
			}
			else{
				root=RL(root);
			}
		}
	}
	else if(k>root->data){
		root->right=Delete(root->right,k);
		
		if(BF(root)==2){							//Rebalancing
			if(BF(root->left)>=0){
				root=LL(root);
			}
			else{
				root=LR(root);
			}
		}
	}
	else{
		//data to be deleted is found
		if(root->right!=NULL){
			//delete its inorder succesor
			node *temp=Find_min(root->right);
			root->data=temp->data;                    			//copy the data 
			root->right=Delete(root->right,temp->data)	;		//delte the temp data

			if(BF(root)==2){									//Rebalancing
				if(BF(root->left)>=0){
				root=LL(root);
				}
				else{
				root=LR(root);
				}
			}
		}
		else{
			return (root->left);
		}
	}
	root->ht=height(root);
	return root;
}

//function to display the data of AVL tree
void display(node *T){
	if(T!=NULL)
	{
		display(T->left);
		printf("%d(Bf=%d) ",T->data,BF(T));
		display(T->right);
	}

}

int main(){
	node *root=NULL;                //empty AVL tree
	int ch,x;
	do{
		system("cls");
		printf("\n\t\t....MENU.....\n");
		printf("\t\t1.Insert\n");
		printf("\t\t2.Delete\n");
		printf("\t\t3.Display\n");
		printf("\t\t4.EXIT\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:printf("\nenter the data:");
					scanf("%d",&x);
					root=insert(root,x);
					break;
			
			case 2:{
				printf("\nenter the data to be deleted:");
				scanf("%d",&x);
				root=Delete(root,x);
				break;
			}
			case 3:{
				printf("\nInorder Sequence of AVl tree:");
				display(root);
				getch();
				break;
			}
			case 4:break;
			default:printf("\nINVALID CHOICE.....");
					break;
		}
	}
	while(ch!=4);
	return 0;
}
