//Merge sort for a linked list
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

//Function for merging the linked list
Node* Merge_list(Node* first,Node *second){
    Node *temp=NULL,*head=NULL;
    if(first==NULL)         return second;
    if(second==NULL)        return first;
    
    if(first->data<second->data){
        temp=first;
        first=first->next;
    }
    else{
        temp=second;
        second=second->next;
    }
    
    head=temp;
    
    while(first!=NULL && second!=NULL){
        if(first->data<second->data){
            temp->next=first;
            temp=first;
            first=first->next;
        }
        else{
            temp->next=second;
            temp=second;
            second=second->next;
        }
    }
    temp->next=(first==NULL)?second:first;
    return head;
}

//Recusive function
Node* mergeSort(Node* head) {
    // your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *slow=head,*fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
 
    Node *middle_next=slow->next;
    
    slow->next=NULL;
    
    Node *l1=mergeSort(head);
    Node *l2=mergeSort(middle_next);
    return Merge_list(l1,l2);

}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}  
