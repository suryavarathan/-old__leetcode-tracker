// Last updated: 7/14/2026, 3:23:16 PM
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : roads) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>pq;
        vector<long long> result(n, LLONG_MAX);
        vector<long long> pathCount(n, 0);

        pq.push({0, 0});
        result[0] = 0;
        pathCount[0] = 1;

        while (!pq.empty()) {
            long long currTime = pq.top().first;
            long long node = pq.top().second;
            pq.pop();

            for (int j = 0; j < adj[node].size(); j++) {
                long long neigh = adj[node][j].first;
                long long time = adj[node][j].second;

                if (currTime + time < result[neigh]) {
                    result[neigh] = currTime + time;
                    pq.push({result[neigh], neigh});
                    pathCount[neigh] = pathCount[node];
                } else if (currTime + time == result[neigh]) {
                    pathCount[neigh] =
                        (pathCount[neigh] + pathCount[node]) % (1000000007);
                }
            }
        }

        return pathCount[n - 1];
    }
};