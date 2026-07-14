// Last updated: 7/14/2026, 3:23:56 PM
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        unordered_map<int, long long> diff;
        for(int i = 0, n = segments.size(); i < n; ++i){
            diff[segments[i][0]] += segments[i][2];
            diff[segments[i][1]] -= segments[i][2];
        }
        vector<int> keys;
        keys.reserve(diff.size());
        for (const auto& [k, _] : diff) keys.push_back(k);
        sort(keys.begin(), keys.end());
        vector<vector<long long>> res;
        long long curr = 0;
        for (int i = 0, n = keys.size() - 1; i < n; ++i) {
            curr += diff[keys[i]];
            if (curr > 0) res.push_back({keys[i], keys[i + 1], curr});
        }
        return res;
    }
};