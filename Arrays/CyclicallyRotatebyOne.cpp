//to cyclically rotate the array by one

#include <stdio.h>

void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}


void rotate(int arr[], int n)
{
    int temp=arr[n-1];
    for(int i=0;i<n-1;i++){
        arr[n-1-i]=arr[n-2-i];
    }
    arr[0]=temp;
    
}
