class Solution {
 public:
    bool stringStack(string &pat, string &tar) {
        int i = pat.size() - 1;
        int j = tar.size() - 1;
        int k=0;
        while(i >= 0 && j >= 0) {
            if(pat[i] == tar[j] && k%2 ==0) {
                j--;
                k=0;
            }
            else k++;
            i--; 
            if(j<0) return true;
        }

        return j < 0; 
    }
};