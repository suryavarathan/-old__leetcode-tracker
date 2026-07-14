// Last updated: 7/14/2026, 3:24:33 PM
class Solution {
public:
    int twoEggDrop(int n) {
        int l = 1, r = n, ans = n;
        while (l <= r) {
            int m = (l + r) / 2;
            long long sum = 1LL * m * (m + 1) / 2;
            if (sum >= n) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};