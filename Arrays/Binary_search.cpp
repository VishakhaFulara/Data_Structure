//Binary search-Iterative method
#include<iostream>
using namespace std;

int Binary_search(int x,int a[],int n){
    int mid,start=0,end=n-1;                 //start & end is having the index of an array
    while(start<=end){
        mid=start+(end-start)/2;               //(start+end) may overflow
        if(x==a[mid])                          //found x ,return (exit)
            return mid;
        if(x<a[mid])                           //x lies before mid
            end=mid-1;
        else      
            start=mid+1;                       //x lies after mid
    }
    return -1;
}

int main(){
    int n,x;
    cout<<"\nenter the size of an array:";
    cin>>n;
    int a[n];
    cout<<"\nenter array elements:";
    for(int i=0;i<n;i++){
        cin>>a[i];
    } 
    cout<<"\nenter the search element:";
    cin>>x;
    int index=Binary_search(x,a,n);
    if(index>=0){
        cout<<"\nsearch element "<<x<<" is found at index:"<<index<<'\n';
    }
    else{
        cout<<"\nsearch element "<<x<<" is not found"<<'\n';
    }
    return 0;

}

/*
//Binary search-Recursive method
#include<iostream>
using namespace std;

int Binary_search(int x,int a[],int start,int end){

    //exit condition when search element is not found
    if(start>end)   
        return -1;
    int mid=(start+end)/2;

    //exit condition when search element is found
    if(x==a[mid])      
        return mid;
    if(x<a[mid])        
        return Binary_search(x,a,start,mid-1);
    else      
        return Binary_search(x,a,mid+1,end);
}

int main(){
    int n,x;
    cout<<"\nenter the size of an array:";
    cin>>n;
    int a[n],start=0,end=n-1;                        //start & end is having the index of an array
    cout<<"\nenter array elements:";
    for(int i=0;i<n;i++){
        cin>>a[i];
    } 
    cout<<"\nenter the search element:";
    cin>>x;
    int index=Binary_search(x,a,start,end);
    if(index>=0){
        cout<<"\nsearch element "<<x<<" is found at index:"<<index<<'\n';
    }
    else{
        cout<<"\nsearch element "<<x<<" is not found"<<'\n';
    }
    return 0;

}*/
