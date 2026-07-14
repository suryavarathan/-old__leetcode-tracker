// Last updated: 7/14/2026, 3:19:49 PM
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int M = 1e9 + 7;

        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            for (int idx = l; idx <= r; idx += k) {
                long long val = (1LL * nums[idx] * v) % M;
                nums[idx] = (int)val;
            }
        }

        int res = 0;
        for (int num : nums) {
            res ^= num;
        }

        return res;
    }
};
