#include<iostream>
#include<cmath>
using namespace std;

int jump_search(int a[],int x,int n){
	int s,flag,i;
	s=sqrt(n);
	for(i=0;i<n;i+s){
		if(a[i]>x){
			for(int j=(i-s)+1;j<i;j++){
				if(a[j]==x){
					return j;
				}
			}
		}
		else if(a[i]==x){
			return i;
		}
	
	}
	for(i=i-s;i<n;i++){
		if(a[i]==x){
			if(a[i]==x){
				return i;
			}
		}
	}
	return -1;
	
}
int main(){
	int n,x;
	cout<<"enter size:";
	cin>>n;
	int a[n];
	cout<<"enter array sorted elements:";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"enter element to be search:";
	cin>>x;
	int index=jump_search(a,x,n);
	if(index>=0){
		cout<<"element found at index "<<index<<"\n";
	}
	else{
		cout<<"element not found\n";
	}
	return 0;
}
