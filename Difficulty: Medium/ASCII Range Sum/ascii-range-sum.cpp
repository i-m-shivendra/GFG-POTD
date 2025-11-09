#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> asciirange(string& s) {
        unordered_map<int,vector<int>> m;
        vector<int> prefix;
        int sum=0;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(m.find(ch)==m.end())m[ch]={i,-1};
            else m[ch][1]=i;
            sum+=ch;
            prefix.push_back(sum);
        }
        vector<int> ans;
        for(auto it:m){
            char c=it.first;
            int firstidx=it.second[0];
            int lastidx=it.second[1];
            if(lastidx!=-1 && lastidx>firstidx+1)
               ans.push_back(prefix[lastidx-1]-prefix[firstidx]);
        }
        return ans;
    }
};
