// User function Template for C++
class Solution {
  private:
    void topoSort(int node,vector<vector<pair<int,int>>> adjList,
      vector<int>&visited, stack<int>& st) {
      visited[node] = 1;
      for (auto it: adjList[node]) {
        int v = it.first;
        if (!visited[v]){
          topoSort(v,adjList,visited,st);
        }
      }
      st.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adjList(V);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adjList[u].push_back({v,wt});
        }
        
        vector<int> visited(V,0);
        
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                topoSort(i,adjList,visited,st);
            }
        }
        
        vector<int> dist(V);
        for(int i=0;i<V;i++){
            dist[i] = 1e9;
        }
        
        dist[0] = 0;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            
            for(auto it : adjList[top]){
                int v = it.first;
                int wt = it.second;
                
                if (dist[top] + wt < dist[v]) {
                    dist[v] = wt + dist[top];
                }
            }
        }
        
        for(int i=0;i<V;i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};
