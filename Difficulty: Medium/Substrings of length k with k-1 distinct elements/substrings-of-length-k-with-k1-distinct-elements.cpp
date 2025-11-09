class Solution {
  public:
    int substrCount(string &s, int k) {
         deque<char> dq;
        int mcount = 0;
        int count[26] = {0};
        int kcnt = 0;
        for(int i = 0;i<k;i++){
           count[s[i]-'a']++;
           if(count[s[i]-'a'] == 1){
               kcnt++;
           }
           dq.push_back(s[i]);
        } 
        if(kcnt == k-1){
           mcount++;
        }
        for(int i = k;i<s.length();i++){
            count[dq.front()-'a']--;
            if(count[dq.front()-'a'] == 0){
                kcnt--;
            }
            dq.pop_front();
            dq.push_back(s[i]);
            count[s[i]-'a']++;
            if(count[s[i]-'a'] == 1){
                kcnt++;
            }
            if(kcnt == k-1){
                mcount++;
            }
        }
        return mcount;
    }
};