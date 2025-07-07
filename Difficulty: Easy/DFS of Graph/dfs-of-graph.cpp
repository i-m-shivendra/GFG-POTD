class Solution {
  private:
    void dfsImpl(int node, vector<vector<int>>& adj,
    vector<int>& visited, vector<int>& ans){
        visited[node] = 1;
        ans.push_back(node);
        
        for(auto it : adj[node]){
            if(!visited[it]){
                dfsImpl(it,adj,visited,ans);
            }
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        
        //Create a visited array
        vector<int> visited(V,0);
        
        //Create a answer vector
        vector<int> ans;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfsImpl(i,adj,visited,ans);
            }
        }
        return ans;
    }
};