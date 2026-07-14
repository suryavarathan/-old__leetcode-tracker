// Last updated: 7/14/2026, 3:25:32 PM
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        constexpr int MOD = 1e9 + 7;
        int n = nums.size();
        vector<long> prefix(n + 1 , 0), st;
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + nums[i];
        long res = 0;
        for (int i = 0; i <= n; ++i) {
            int curr = (i < n) ? nums[i] : 0;
            while (!st.empty() && nums[st.back()] > curr) {
                int j = st.back(); st.pop_back();
                long left = st.empty() ? 0 : prefix[st.back() + 1];
                res = max(res, nums[j] * (prefix[i] - left));
            }
            st.push_back(i);
        }
        return res % MOD;
    }
};