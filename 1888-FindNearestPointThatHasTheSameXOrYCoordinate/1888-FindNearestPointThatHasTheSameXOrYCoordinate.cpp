// Last updated: 7/14/2026, 3:27:39 PM
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int len = points.size();
        int dis = INT_MAX, idx = -1;
        for(int i = 0; i < len; ++i){
            if(x == points[i][0] || y == points[i][1]){
                int val = abs(x-points[i][0]) + abs(y -points[i][1]);
                if(dis > val){
                    idx = i,    dis = val;
                }
            }
        }
        return idx;
    }
};