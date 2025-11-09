#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size(), m = b.size();
        vector<int> res;
        if (n == 0 || m == 0 || k == 0) return res;

        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        // Max-heap: {sum, i, j}
        priority_queue<tuple<int,int,int>> pq;
        pq.push({a[0] + b[0], 0, 0});

        // To avoid pushing the same pair again
        set<pair<int,int>> seen;
        seen.insert({0,0});

        while (k-- && !pq.empty()) {
            auto [sum, i, j] = pq.top(); pq.pop();
            res.push_back(sum);

            if (i + 1 < n && seen.count({i+1,j}) == 0) {
                pq.push({a[i+1] + b[j], i+1, j});
                seen.insert({i+1,j});
            }
            if (j + 1 < m && seen.count({i,j+1}) == 0) {
                pq.push({a[i] + b[j+1], i, j+1});
                seen.insert({i,j+1});
            }
        }

        return res;
    }
};
