class Solution {
   public:
    bool ispower5(string &s,int l, int r){
        int n=s.length();
        if(s[l]=='0') return false;
        long long num = 0;
        for(int i=l ; i<=r; i++){
            num = num*2 + s[i]-'0';
            if(num>1e10) return false;
        }
        
        while(num>1 && num%5==0) num/=5;
        return num==1;
    }
    
  
    int cuts(string s) {
        // code here
        int n=s.length();
        int inf=1e9;
        vector<int>v(n+1,inf);
        v[0]=0;
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                if(ispower5(s,j,i-1) ){
                    v[i] = min(v[i], v[j]+1);
                }
            }
        }
        
        return v[n]>=inf?-1:v[n];
    }
};