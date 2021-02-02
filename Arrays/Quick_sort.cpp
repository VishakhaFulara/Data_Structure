#include<iostream>
using namespace std;

int Partition(int *a,int start,int end){
	int pivot=a[end];
	int pindex=start;									//set partition index as start initially 
	for(int i=start;i<end;i++){
		if(a[i]<=pivot){
			swap(a[i],a[pindex]);					//Swap if element is lesser than pivot
			pindex++;
		}
	}
	swap(a[pindex],a[end]);
	return pindex;
	
}
void Quick_Sort(int *a,int start,int end){
	if(start<end){
		int Pindex=Partition(a,start,end);					//calling partition
		Quick_Sort(a,start,Pindex-1);
		Quick_Sort(a,Pindex+1,end);
	}
}

int main(){
	int n;
	cout<<"enter size:";
	cin>>n;
	int a[n];
	cout<<"enter array element:";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	Quick_Sort(a,0,n-1);
	cout<<"After Quick sort:";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
