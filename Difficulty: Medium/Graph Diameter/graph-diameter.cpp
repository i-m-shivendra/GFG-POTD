class Solution {
  public:
    int diameter(int V, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<int>> graph(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // BFS function returning farthest node and its distance
        auto bfs = [&](int start) {
            vector<int> dist(V, -1);
            queue<int> q;
            q.push(start);
            dist[start] = 0;

            int far = start;
            while (!q.empty()) {
                int node = q.front(); q.pop();
                for (int nei : graph[node]) {
                    if (dist[nei] == -1) {
                        dist[nei] = dist[node] + 1;
                        q.push(nei);
                        if (dist[nei] > dist[far]) {
                            far = nei;
                        }
                    }
                }
            }
            return make_pair(far, dist[far]);
        };

        // Step 1: Find farthest from node 0
        auto p1 = bfs(0);

        // Step 2: BFS from that farthest node
        auto p2 = bfs(p1.first);

        return p2.second;  // diameter
    }
};
