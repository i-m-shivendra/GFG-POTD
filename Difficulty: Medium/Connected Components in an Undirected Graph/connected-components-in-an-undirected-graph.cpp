
class Solution {
  private:
     void dfs(int node,vector<vector<int>>& adjList, vector<int>&
     visited, vector<int>& temp){
         visited[node] = 1;
         temp.push_back(node);
         
         for(int i=0;i<adjList[node].size();i++){
             if(!visited[adjList[node][i]]){
                 dfs(adjList[node][i],adjList,visited,temp);
             }
         }
         
     }
     
  public:
    vector<vector<int>> getComponents(int V, 
    vector<vector<int>>& edges) {
        
        //Initiliasation of adjList
        vector<vector<int>> adjList(V);
        
        //Creation of adjList
        for(auto it : edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        
        //Creating a visited array
        vector<int> visited(V,0);
        
        //Creating an answer vector
        vector<vector<int>> ans;
        
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
