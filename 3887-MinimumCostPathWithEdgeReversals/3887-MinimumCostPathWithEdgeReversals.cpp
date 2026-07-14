// Last updated: 7/14/2026, 3:20:12 PM
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto e: edges){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,2*wt});
        }
        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                int adjnode=it.first;
                int edw=it.second;
                if(d+edw<dist[adjnode]){
                    dist[adjnode]=d+edw;
                    pq.push({d+edw,adjnode});
                }
            }
        }
        if(dist[n-1]==INT_MAX) return -1;
        return dist[n-1];
    }
};