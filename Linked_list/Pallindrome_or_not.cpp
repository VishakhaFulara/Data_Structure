#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

bool isPalindrome(Node *head)
{
    //Your code here
    Node *slow=head,*fast=head,*newhead,*cur,*prev=NULL,*next;
     while(fast && fast->next){             
    	fast=fast->next->next;													
       slow=slow->next;
    }
    if(fast!=NULL){
    	newhead=slow->next;
	}
    else{
    	newhead=slow;
	}
    
    //reversing second list
    cur=newhead;
    while(cur!=NULL){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    newhead=prev;
    
    while(head!=NULL && newhead!=NULL){
        if(head->data!=newhead->data){
            return false;
        }
        head=head->next;
        newhead=newhead->next;
    }
    return true;
    
}

