#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int specialNodes(int n, vector<vector<int>> &edges, int x, int y, int z)
    {
        // Build adjacency list for the tree
        vector<vector<int>> adj(n);
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // BFS to find distances from a source node to all other nodes
        auto bfs = [&](int start) -> vector<int>
        {
            vector<int> dist(n, -1);
            queue<int> q;
            q.push(start);
            dist[start] = 0;

            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int v : adj[u])
                {
                    if (dist[v] == -1)
                    {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
            return dist;
        };

        // Get distances from x, y, and z to all nodes
        vector<int> distX = bfs(x);
        vector<int> distY = bfs(y);
        vector<int> distZ = bfs(z);

        int count = 0;
        // Check each node if it forms a Pythagorean triplet
        for (int i = 0; i < n; i++)
        {
            vector<long long> dists = {distX[i], distY[i], distZ[i]};
            sort(dists.begin(), dists.end());

            // Check if a² + b² = c² where a <= b <= c
            if (dists[0] * dists[0] + dists[1] * dists[1] == dists[2] * dists[2])
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    Solution sol;

    // Example 1: n = 4, edges = [[0,1],[0,2],[0,3]], x = 1, y = 2, z = 3
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {0, 3}};
    int result1 = sol.specialNodes(4, edges1, 1, 2, 3);
    cout << "Example 1: " << result1 << " (Expected: 3)\n";

    // Example 2: n = 4, edges = [[0,1],[1,2],[2,3]], x = 0, y = 3, z = 2
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 3}};
    int result2 = sol.specialNodes(4, edges2, 0, 3, 2);
    cout << "Example 2: " << result2 << " (Expected: 0)\n";

    // Example 3: n = 4, edges = [[0,1],[1,2],[1,3]], x = 1, y = 3, z = 0
    vector<vector<int>> edges3 = {{0, 1}, {1, 2}, {1, 3}};
    int result3 = sol.specialNodes(4, edges3, 1, 3, 0);
    cout << "Example 3: " << result3 << " (Expected: 1)\n";

    return 0;
}
