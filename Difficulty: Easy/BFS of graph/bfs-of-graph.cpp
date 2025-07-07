class Solution {
  private:
    void bfsImpl(int node, vector<vector<int>> &adj,
    vector<int>& visited, vector<int>& ans){
        visited[node] = 1;
        
        queue<int> q;
        q.push(node);
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            ans.push_back(front);
            
            for(auto it : adj[front]){
                if(!visited[it]){
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
    }
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int V = adj.size();
        
        //Create a visited array
        vector<int> visited(V,0);
        
        //Create an answer vector
        vector<int> ans;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bfsImpl(i,adj,visited,ans);
            }
        }
        return ans;
    }
};