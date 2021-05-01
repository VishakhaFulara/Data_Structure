class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here{
	    int i=0,j=0,k=j+1;
	    while(i<n){
	        if(arr1[i]>arr2[j]){
	            swap(arr1[i],arr2[j]);
	            
	            if(arr2[j]<arr2[k] && j<m){
	                j=0;
	             //  k=j+1;
	                i++;
	                continue;
	            }
	            else{
	                sort(arr2,arr2+m);
	              /*  swap(arr2[j],arr2[k]);
	                j++;k++;
	               while(arr2[j]>arr2[k] && j<m-1 ){
	                    swap(arr2[j],arr2[k]);
	                    j++;k++;
	                }*/
	            }
	        }
	        i++;
	        j=0;
	      //  k=j+1;
	        
	    }
	}
};
