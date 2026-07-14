// Last updated: 7/14/2026, 3:29:19 PM
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;
        int time = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (time < customers[i][0]) {
                time = customers[i][0];
            }
            time += customers[i][1];
            ans += (time - customers[i][0]);
        }
        return ans / customers.size();
    }
};