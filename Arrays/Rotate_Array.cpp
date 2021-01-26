void rotation_of_array(int *a,int n,int d){
	int b[100000],j=0,i;
	for(i=d;i<n;i++){
		b[j]=a[i];
		j++;
	}
	for(i=0;i<d;i++){
		b[j]=a[i];
		j++;
   	}
   	j=0;
   	for(i=0;i<n;i++){
		printf("%d ",b[i]);
	}
	printf("\n");
}
int main(){
	int a[100000],t=0,k,i,n,d;
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		scanf("%d %d",&n,&d);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		rotation_of_array(a,n,d);
    }
	return 0;
}
