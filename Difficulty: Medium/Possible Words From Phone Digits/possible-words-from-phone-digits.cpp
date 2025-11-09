class Solution {
  public:
    vector<string> possibleWords(vector<int> &arr) {
        n = arr.size();
        string ans = "";
        dfs(ans, 0, arr);   
        return res;
    }

private:
    vector<string> phn {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    int n;
    vector<string> res;

    void dfs(string &ans, int ind, vector<int> &arr) {
        if (ind == n) {
            res.push_back(ans);
            return;
        }

        int digit = arr[ind];
        if (phn[digit] == "") { 
            dfs(ans, ind + 1, arr);
            return;
        }

        for (char c : phn[digit]) {
            ans.push_back(c);
            dfs(ans, ind + 1, arr);
            ans.pop_back();  
        }
    }
};