 long long maxSubarraySum(int arr[], int n){
        long long sum=0, maxsum=LONG_MIN;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            maxsum=max(sum, maxsum);
            if(sum<0){
                sum=0;
            }
        
        }
        if(maxsum<0){
            return 0;
        }
        return maxsum;
        // Your code here
        
    }
