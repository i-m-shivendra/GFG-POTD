class Solution {
public:
    vector<string> binstr(int n) {
        vector<string> ans;
        queue<string> q;

        q.push("0");
        q.push("1");

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (curr.size() == n) {
                ans.push_back(curr);
            } else {
                q.push(curr + "0");
                q.push(curr + "1");
            }
        }

        return ans;
    }
};
