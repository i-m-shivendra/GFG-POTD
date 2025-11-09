class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        int n1 = arr1.size(), n2 = arr2.size();
        vector<vector<int>> result;

        if (n1 == 0 || n2 == 0 || k == 0) return result;

        // Min-heap: (sum, i, j)
        priority_queue<
            tuple<int,int,int>, 
            vector<tuple<int,int,int>>, 
            greater<tuple<int,int,int>>
        > pq;

        // Push first pair for j = 0
        for (int i = 0; i < min(k, n1); i++) {
            pq.push({arr1[i] + arr2[0], i, 0});
        }

        while (!pq.empty() && k--) {
            auto [sum, i, j] = pq.top();
            pq.pop();

            result.push_back({arr1[i], arr2[j]});

            // Push next pair in the same row (i,j+1)
            if (j + 1 < n2) {
                pq.push({arr1[i] + arr2[j+1], i, j+1});
            }
        }

        return result;
    }
};
