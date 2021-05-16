/*Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.*/


 long long int inversionCount(long long arr[], long long N)
    {
        /* long long int c=0;
        if(N<1)
            return -1;
        for(int i=0;i<N;i++){
             for(int j=i+1;j<N;j++){
                if(arr[i]>arr[j])
                    c++;
            }
        }
        return c;*/
        long long count=0;
        
        count=mergeSort(arr,N,count);
        return count;
    }
