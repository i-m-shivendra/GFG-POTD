class Solution {
  public:
    int shortCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int ans = INT_MAX;

        // BFS from every node
        for (int start = 0; start < V; start++) {
            vector<int> dist(V, -1), parent(V, -1);
            queue<int> q;

            q.push(start);
            dist[start] = 0;

            while (!q.empty()) {
                int u = q.front(); 
                q.pop();

                for (int v : graph[u]) {
                    if (dist[v] == -1) { 
                        // normal BFS step
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    } else if (parent[u] != v) {  
                        // Found a cycle
                        int cycleLength = dist[u] + dist[v] + 1;
                        ans = min(ans, cycleLength);
                    }
                }
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};

