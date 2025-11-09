#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestString(vector<string> &words) {
        set<string> built;  // strings that can be built
        sort(words.begin(), words.end()); // lexicographical order

        string ans = "";
        for (string &word : words) {
            if (word.size() == 1 || built.count(word.substr(0, word.size() - 1))) {
                built.insert(word);
                if (word.size() > ans.size()) ans = word;
            }
        }

        return ans;
    }
};
