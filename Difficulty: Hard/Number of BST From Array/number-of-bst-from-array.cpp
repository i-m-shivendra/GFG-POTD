class Solution {
  public:
    // returns index of key in a sorted array
    int BinarySearch(vector<int> &arr, int key){
        int l = 0, r = arr.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(arr[m] == key)return m;
            else if(arr[m]<key)l = m+1;
            else r = m-1;
        }
        return -1;
    }
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        
        // sorted array
        vector<int> brr(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());
        
        // catalan values from 0 to n-1
        // using the relation C(n) = (C(n-1)*(4n - 2))/(n+1)
        vector<long int> catalan(n, 0);
        catalan[0] = catalan[1] = 1;
        for(int i = 2;i<n;i++){
            catalan[i] = (catalan[i-1]*(4*i-2))/(i+1);
        }
        
        
        vector<int> BSTcnts(n);
        for(int i = 0;i<n;i++){
            int idx = BinarySearch(brr, arr[i]);
            
            // number of nodes with lower value
            int num_lower = idx;
            
            // number of nodes with higher value
            int num_higher = n-idx-1;
            
            // n nodes can form catalan[n] unique trees
            // so total possible bst would be 
            int num_bst = catalan[num_lower]*catalan[num_higher];
            
            BSTcnts[i] = num_bst;
        }
        
        return BSTcnts;
    }
};