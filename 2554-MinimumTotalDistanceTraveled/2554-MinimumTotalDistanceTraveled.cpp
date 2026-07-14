// Last updated: 7/14/2026, 3:21:58 PM
class Solution {
private:
    long long solve(int i, int j, const vector<int>& robot, const vector<int>& slots, vector<vector<long long>>& memo) {
        if (i == robot.size()) return 0;
        
        if (j == slots.size()) return 1e15; 

        if (memo[i][j] != -1) return memo[i][j];

        long long skip = solve(i, j + 1, robot, slots, memo);

        long long distance = abs(robot[i] - slots[j]);
        long long use = distance + solve(i + 1, j + 1, robot, slots, memo);
        return memo[i][j] = min(skip, use);
    }

public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> slots;
        for (const auto& f : factory) {
            int pos = f[0];
            int limit = f[1];
            for (int k = 0; k < limit; ++k) { 
                slots.push_back(pos);
            }
        }

        int n = robot.size();
        int m = slots.size();

        vector<vector<long long>> memo(n, vector<long long>(m, -1));
        return solve(0, 0, robot, slots, memo);
    }
};
