// Last updated: 7/14/2026, 3:22:39 PM
class Solution {
public:
    int dp[1<<14][16];
    int findMinSessions(int &n, vector<int> &tasks, int &sessionTime, int mask, int remSessionTime) {
        if (mask == 0)  return 1;

        if (dp[mask][remSessionTime] != -1)    return dp[mask][remSessionTime];

        int minSessions = INT_MAX;

        for (int i=0; i<n; i++) {
            if (mask&(1<<i) && tasks[i] <= remSessionTime) {
                minSessions = min(minSessions, findMinSessions(n, tasks, sessionTime, mask^(1<<i), remSessionTime - tasks[i]));
            }
        }

        if (minSessions == INT_MAX) minSessions = 1 + findMinSessions(n, tasks, sessionTime, mask, sessionTime);

        return dp[mask][remSessionTime] = minSessions;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        memset(dp, -1, sizeof(dp));

        int n = tasks.size();

        int mask = (1<<n) - 1;
        
        return findMinSessions(n, tasks, sessionTime, mask, sessionTime);
    }
};