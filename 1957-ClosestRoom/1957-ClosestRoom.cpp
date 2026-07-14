// Last updated: 7/14/2026, 3:26:04 PM
class Solution {
    int N;
    unordered_map<int, set<int>> tree;
public:
    void update(int n, int v) {
        n = N - n + 1;
        for (;n <= N; n += n & (-n)) tree[n].insert(v); 
    }
    
    int query(int n, int v) {
        n = N - n + 1;
        int res = -1, min_diff = INT_MAX, diff;
        for (; n > 0; n -= n & (-n)) {
            if (tree[n].size() == 0) continue;
            auto itr = tree[n].lower_bound(v);
            if (itr != tree[n].end()) {
                diff = *itr - v;
                if (diff < min_diff) res = *itr, min_diff = diff;
                else if (diff == min_diff) res = min(res, *itr);
            }
            if (itr != tree[n].begin()) {
                --itr;
                diff = v - *itr;
                if (diff < min_diff) res = *itr, min_diff = diff;
                else if (diff == min_diff) res = min(res, *itr);
            }
        }
        return res;
    }
    
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        N = 1e7;
        for (auto &&r : rooms) update(r[1], r[0]);
        
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            res[i] = query(queries[i][1], queries[i][0]);
        }
        return res;
    }
};