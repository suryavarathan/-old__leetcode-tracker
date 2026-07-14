// Last updated: 7/14/2026, 3:21:24 PM
#define ll long long
class Solution {
const ll INF = 1e9+7; 
public:

    void floyd_warshall(vector<vector<ll>> &dist){
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        vector<vector<ll>> dist(26,vector<ll> (26,INF));
        for(ll i=0;i<original.size();i++){
            dist[original[i]-'a'][changed[i]-'a'] = min(dist[original[i]-'a'][changed[i]-'a'],cost[i]*1LL);
        }
        for(int i=0;i<26;i++){
            dist[i][i] = 0;
        }
        floyd_warshall(dist);

        ll ans = 0;
        for(int i=0;i<source.size();i++){
            if(dist[source[i]-'a'][target[i]-'a'] == INF) return -1;
            ans += dist[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};