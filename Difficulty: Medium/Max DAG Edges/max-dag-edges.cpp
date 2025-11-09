class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        
        long long maxPossible = (1LL * V * (V - 1)) / 2;
        long long current = edges.size();  // number of edges
        
        return maxPossible - current;
    }
};
