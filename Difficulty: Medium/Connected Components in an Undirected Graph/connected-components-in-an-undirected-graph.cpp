
class Solution {
  private:
    void dfs(int node,vector<vector<int>>& adjList,
    vector<int>& visited,vector<int>& temp){
        visited[node] = true;
        temp.push_back(node);
        
        for(auto it : adjList[node]){
            if(!visited[it]){
                dfs(it,adjList,visited,temp);
            }
        }
    }
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        //Create an adjacency List
        vector<vector<int>> adjList(V);
        
        //Initialisation of adjacency list
        for(auto it : edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        
        //Create an answer vector
        vector<vector<int>> ans;
        
        //Create a visited array
        vector<int> visited(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                vector<int> temp;
                dfs(i,adjList,visited,temp);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
