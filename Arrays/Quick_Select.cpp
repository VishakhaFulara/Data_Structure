#include<iostream>
using namespace std;

int Partition(int *a,int start,int end){
	int pivot=a[end];
	int pindex=start;									//set partition index as start initially 
	for(int i=start;i<end;i++){
		if(a[i]<pivot){
			swap(a[i],a[pindex]);					//Swap if element is lesser than pivot
			pindex++;
		}
	}
	swap(a[pindex],a[pivot]);
	return pindex;
	
}
int Smallest(int *a,int start,int end,int k){
	if(start<=end){
		int Pindex=Partition(a,start,end);					//calling partition
		if(Pindex+1==k){
			return a[Pindex];
		}
		Smallest(a,start,Pindex-1,k);
	}
}

int main(){
	int n,k;
	cout<<"enter size:";
	cin>>n;
	int a[n];
	cout<<"enter array element:";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"enter kth smallest element:";
	cin>>k;
	cout<<k<<"th smallest element is "<<Smallest(a,0,n-1,k);
	return 0;
}
