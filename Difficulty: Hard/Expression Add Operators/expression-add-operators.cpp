class Solution {
public:
    vector<string> ans;

    void backtrack(string& s, int pos, long long value, long long last,
                   string currExpr, int target) {

        if (pos == s.size()) {
            if (value == target) {
                ans.push_back(currExpr);
            }
            return;
        }

        long long num = 0;

        for (int i = pos; i < s.size(); i++) {

            // avoid numbers with leading zeros
            if (i > pos && s[pos] == '0') break;

            num = num * 10 + (s[i] - '0');

            string numStr = s.substr(pos, i - pos + 1);

            // first number (no operator before it)
            if (pos == 0) {
                backtrack(s, i + 1, num, num, numStr, target);
            } 
            else {
                // +
                backtrack(s, i + 1, value + num, num, currExpr + "+" + numStr, target);

                // -
                backtrack(s, i + 1, value - num, -num, currExpr + "-" + numStr, target);

                // *
                backtrack(s, i + 1,
                          value - last + last * num,
                          last * num,
                          currExpr + "*" + numStr,
                          target);
            }
        }
    }

    vector<string> findExpr(string &s, int target) {
        ans.clear();
        backtrack(s, 0, 0, 0, "", target);
        return ans;
    }
};
