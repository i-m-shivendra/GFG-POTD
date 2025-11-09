#include <string>
using namespace std;

class Solution {
public:
    bool isSubSeq(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (s1[i] == s2[j]) {
                i++; // match found, move to next char in s1
            }
            j++; // always move in s2
        }

        return i == n; // all chars of s1 matched
    }
};
