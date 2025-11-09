class Solution {
public:
    int getLPSLength(string &s) {
        int n = s.size();
        vector<int> lps(n, 0); // LPS array
        int length = 0; // length of the previous longest prefix-suffix
        int i = 1;

        while (i < n) {
            if (s[i] == s[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1]; // fallback
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // The last value of LPS array gives the longest prefix which is also suffix
        return lps[n - 1];
    }
};
