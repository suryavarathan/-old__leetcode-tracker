// Last updated: 7/14/2026, 3:23:27 PM
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum = 0;
        int maxi = INT_MIN;
        
        for (int n : milestones) {
            sum += n;
            maxi = max(maxi, n);
        }
        
        return min(sum, 2 * (sum - maxi) + 1);
    }
};