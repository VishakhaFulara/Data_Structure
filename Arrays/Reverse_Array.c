#include<stdio.h>
void Reverse_array(int a[],int n){
	int i=0,j,temp;
	for(j=n-1;j>=n/2;j--){
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		i++;
	}
}

int main(){
	int n;
	printf("enter size:");
	scanf("%d",&n);
	int a[n],i;
	printf("enter the elements of an array:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	Reverse_array(a,n);
	
	printf("\nReverse of a array:");
	for(i=0;i<n;i++){
		printf("%d  ",a[i]);
	}
	return 0;
}
