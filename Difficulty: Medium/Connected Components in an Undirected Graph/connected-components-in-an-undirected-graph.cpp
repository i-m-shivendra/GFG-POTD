//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    
  private:
     void dfs(int node,  vector<vector<int>>& adjList, vector<int>& 
     visited, vector<int>& temp){
         visited[node] = 1;
         temp.push_back(node);
         
         for(int i=0;i<adjList[node].size(); i++){
             if(!visited[adjList[node][i]]){
                 dfs(adjList[node][i], adjList, visited, temp);
             }
         }
     }
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // Initialisation of adjacency list
        vector<vector<int>> adjList(V);
        
        //Creation of adjacency list
        for(auto it : edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        
        //Creating a visited array
        vector<int> visited(V, 0);
        
        //Creating an answer vector
        vector<vector<int>> ans;
        
        //Finding all the connected components
        for(int i=0;i<V;i++){
            if(!visited[i]){
                vector<int> temp;
                dfs(i, adjList, visited, temp);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        vector<vector<int>> res = obj.getComponents(V, edges);

        for (int i = 0; i < res.size(); i++) {
            sort(res[i].begin(), res[i].end());
        }
        sort(res.begin(), res.end());
        for (const auto &component : res) {
            for (int node : component) {
                cout << node << " ";
            }
            cout << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends