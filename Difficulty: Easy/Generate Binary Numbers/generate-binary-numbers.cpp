class Solution {
public:
    vector<string> generateBinary(int n) {
        vector<string> ans;
        queue<string> q;
        q.push("1");

        while (n--) {
            string curr = q.front(); 
            q.pop();
            ans.push_back(curr);

            q.push(curr + "0");
            q.push(curr + "1");
        }
        return ans;
    }
};
