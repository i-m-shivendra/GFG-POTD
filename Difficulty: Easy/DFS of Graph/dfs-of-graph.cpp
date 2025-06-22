class Solution {
  private:
    void dfs(int node, vector<vector<int>>& adj,
    vector<int>& visited, vector<int>& temp){
        visited[node] = 1;
        temp.push_back(node);
        
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited,temp);
            }
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        
        //Create a visited array
        vector<int> visited(V,0);
        
        //Create ans vector
        vector<int> ans;
        
        //calling dfs function
        dfs(0,adj,visited,ans);
        
        return ans;
    }
};