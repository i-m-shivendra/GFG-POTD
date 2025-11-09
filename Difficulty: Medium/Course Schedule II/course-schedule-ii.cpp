class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        vector<int> adj[n];
        
        // Build adjacency list
        for(auto &p : prerequisites) {
            int course = p[0];
            int pre = p[1];
            adj[pre].push_back(course);
        }
        
        vector<int> indegree(n, 0);
        
        // Calculate indegree
        for(int i = 0; i < n; i++){
            for(int x : adj[i]){
                indegree[x]++;
            }
        }
        
        queue<int> q;
        
        // Push all nodes with indegree = 0
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> order;
        
        while(!q.empty()){
            int node = q.front(); 
            q.pop();
            order.push_back(node);
            
            for(int x : adj[node]){
                indegree[x]--;
                if(indegree[x] == 0) q.push(x);
            }
        }
        
        // If order size isn't n, cycle exists
        if(order.size() != n) return {};
        
        return order;
    }
};
