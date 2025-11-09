#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
 public:
    string smallestWindow(string &s, string &p) 
    {
        // code here
        unordered_map<char,int>mp;
        unordered_map<char,int>hash;
        int n = p.length();
        for(int i=0;i<n;i++)
        {
            mp[p[i]]++;
        }
        int count = 0;
        int minLength = INT_MAX;
        int minIndex = 0;
        int start = 0;
        for(int i=0;i<s.length();i++)
        {
            hash[s[i]]++;
            if(mp[s[i]]!=0 && hash[s[i]]<=mp[s[i]])
            {
                count++;
            }
            if(count==n)
            {
                while(hash[s[start]]>mp[s[start]])
                {
                    hash[s[start]]--;
                    start++;
                }
                int length = i-start+1;
                if(length<minLength)
                {
                    minLength = length;
                    minIndex = start;
                }
            }
        }
        if(minLength!=INT_MAX){
            return s.substr(minIndex,minLength);
        }
        return "";
    }
};
