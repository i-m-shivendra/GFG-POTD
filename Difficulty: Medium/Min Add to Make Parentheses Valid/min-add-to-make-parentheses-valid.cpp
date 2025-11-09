class Solution {
public:
    int minParentheses(string& s) {
        int openNeeded = 0, closeNeeded = 0;

        for (char c : s) {
            if (c == '(') {
                openNeeded++;
            } else {  // ')'
                if (openNeeded > 0) {
                    openNeeded--;  // match a '('
                } else {
                    closeNeeded++;  // need one '(' before this ')'
                }
            }
        }
        return openNeeded + closeNeeded;
    }
};
