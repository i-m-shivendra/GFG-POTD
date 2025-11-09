class Solution {
   public:
    vector<pair<int,int>> factorial;
    vector<pair<int,int>> primeFactor(int n){
        int count=0;
        while(n%2==0){
            count++;
            n=n/2;
        }
        if(count>0)factorial.push_back({2,count});
        
        for(int i=3;i*i<=n;i=i+2){
            count=0;
            while(n%i==0){
                count++;
                n=n/i;
            }
            if(count>0)factorial.push_back({i,count});
        }
        if(n>1)factorial.push_back({n,1});
        return factorial;
    }
    int legendre(int n,int base){
        int count=0;
        for(int i=base;i<=n;i=i*base){
            count=count+(n/i);
        }
        return count;
    }
    int maxKPower(int n, int k) {
        // code here
        
        vector<pair<int,int>> fact=primeFactor(k);
        int ans=INT_MAX;
        for(auto it:fact){
            int prime=it.first;
            int power=it.second;
            
            int p=legendre(n,prime);
            int x=p/power;
            ans=min(ans,x);
        }
        return  ans;
        
    }
};