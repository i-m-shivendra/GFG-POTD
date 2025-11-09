class Solution {
  public:

    int largestHist(vector<int> &h) {
        stack<int> st;
        int n = h.size(), maxA = 0;

        for (int i = 0; i <= n; i++) {
            int curr = (i == n ? 0 : h[i]);

            while (!st.empty() && curr < h[st.top()]) {
                int top = st.top();
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxA = max(maxA, h[top] * width);
            }
            st.push(i);
        }
        return maxA;
    }

    int maxArea(vector<vector<int>> &mat) {
        if (mat.empty()) return 0;

        int n = mat.size(), m = mat[0].size();
        vector<int> height(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {

            // Update histogram
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1)
                    height[j]++;
                else
                    height[j] = 0;
            }

            // Compute largest rectangle for this histogram
            ans = max(ans, largestHist(height));
        }

        return ans;
    }
};
