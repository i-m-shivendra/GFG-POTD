class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        // code here
       int n=arr.size(), sm=0;
       for(int i=0; i<n; i++) sm+=arr[i];
       
       
       vector<int>v(n,1); // length
       vector<int>s(n); // sum
       for(int i=0; i<n; i++){
           s[i]=arr[i];
       }
       
       int mxl = 1;
       for(int i=0; i<n; i++){
           for(int j=0; j<i; j++){
               if(arr[j]<arr[i]){
                  
                  if(v[i]<v[j]+1){
                      v[i]=v[j]+1;
                      s[i]=s[j]+arr[i];
                  } else if(v [i]==v[j]+1){
                      
                      s[i] = min(s[i] , s[j]+arr[i]);
                  }
               }
           }
           
           mxl = max(mxl, v[i]);
       }
       
       int mn= INT_MAX; 
       for(int i=0; i<n; i++){
           if(v[i]==mxl){
               mn = min(mn, s[i]);
           }
       }
       
       return sm-mn;
       
    }
};