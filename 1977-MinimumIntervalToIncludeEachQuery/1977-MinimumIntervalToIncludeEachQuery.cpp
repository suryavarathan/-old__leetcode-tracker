// Last updated: 7/14/2026, 3:25:39 PM
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        const int n = intervals.size(), m = queries.size();
        vector<int> idx(m), res(m , -1);
        iota(idx.begin() , idx.end() , 0);
        sort(intervals.begin() , intervals.end());
        sort(idx.begin() , idx.end() , [&queries](const int&a , const int& b){
            return queries[a] < queries[b];
        });
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>> pq;
        for(int i = 0, j = 0; j < m; ++j){
            int id = idx[j], pos = queries[id];
            while(i < n && intervals[i][0] <= pos){
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                ++i;
            }
            while(!pq.empty() && pq.top().second < pos) pq.pop();
            if(!pq.empty()) res[id] = pq.top().first;
        }
        return res;
    }
};