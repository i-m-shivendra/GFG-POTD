class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n=adj.size();
        vector<int> dis(n, 1e9);
        dis[src]=0;
        queue<int> q;
        q.push(src);
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            for(int it : adj[front])
            {
                if(dis[front]+1<dis[it])
                {
                    dis[it]=1+dis[front];
                    q.push(it);
                }
                
            }
        }
        
        for(int i=0;i<n;i++){
            if(dis[i] == 1e9){
                dis[i] = -1;
            }
        }
        
        return dis;
    }
};