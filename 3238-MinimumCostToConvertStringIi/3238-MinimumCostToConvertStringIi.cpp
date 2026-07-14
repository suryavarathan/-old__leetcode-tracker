// Last updated: 7/14/2026, 3:21:23 PM
#define ll long long
class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n = source.size();
        int m = cost.size();
        unordered_map<string, unordered_map<string, ll>> mp;
        unordered_set<string> st;
        unordered_set<int> lens;
        ll INF = (1LL <<  60);
        for (int i = 0; i < m; i++){
            string from = original[i];
            string to = changed[i];
            st.insert(from);
            st.insert(to);
            mp[from][to] = min(mp[from].count(to) ? mp[from][to] : INF, (ll)cost[i]);
            ll x = from.size();
            lens.insert(x);
        }
        for (auto &k : st){
            for (auto &i : st){
                if (mp.count(i) && mp[i].count(k)){
                    for (auto &j : st){
                        if (mp.count(k) && mp[k].count(j)){
                            if (!(mp.count(i) && mp[i].count(j))) mp[i][j] = INF;
                            mp[i][j] = min(mp[i][j], mp[k][j] + mp[i][k]);
                        }
                    }
                }
            }
        }
        vector<ll> dp(n+1, INF);
        dp[0] = 0;
        for (int i = 0; i < n; i++){
            if (dp[i] == INF) continue;
            if (source[i] == target[i]) dp[i+1] = min(dp[i+1], dp[i]);
            for (auto l : lens){
                if(i + l <= n){
                    string from = source.substr(i, l);
                    string to = target.substr(i, l);
                    if (!(mp.count(from) && mp[from].count(to))) continue;
                    dp[i+l] = min(dp[i+l], dp[i] + mp[from][to]);
                }
            }
        }

        return (dp[n] == INF? -1 : dp[n]);
    }
};