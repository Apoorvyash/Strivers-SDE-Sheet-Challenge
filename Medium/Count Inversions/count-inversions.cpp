//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
void merge(vector<long long>&arr, long long begin, long long middle, long long end, long long int&count){
    vector<long long>ans;
    long long i = begin;
    long long j = middle+1;
    while(i<=middle && j<=end){
        if(arr[i]>arr[j]){
            ans.push_back(arr[j]);
            count = count+ middle- i+ 1;
            j++;
        }
        else if(arr[i]<arr[j]){
            ans.push_back(arr[i]);
            i++;
        }
        else{
            ans.push_back(arr[i]);
            i++;
        }
    }
    while(i<=middle){
        ans.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        ans.push_back(arr[j]);
        j++;
    }
    long long m =0;
    for(long long k=begin; k<=end; k++){
        arr[k] = ans[m];
        m++;
    }

}

void mergesort(vector<long long>&a, long long start, long long stop, long long int&c){
    if(start>=stop){
        return;
    }
    long long mid = (start+ stop)/2;
    mergesort(a, start, mid, c);
    mergesort(a, mid+1, stop, c);
    return merge(a,start, mid, stop, c);
}


class Solution{

  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int count = 0;
        vector<long long>ans;
        for(long long i=0; i<N; i++ ){
            ans.push_back(arr[i]);
        }
        mergesort(ans, 0, N-1, count);
        return count;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends