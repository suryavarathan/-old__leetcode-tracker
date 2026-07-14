// Last updated: 7/14/2026, 3:28:59 PM
// OJ: https://leetcode.com/problems/calculate-money-in-leetcode-bank/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int totalMoney(int n) {
        int s = 1, ans = 0;
        while (n > 0) {
            for (int i = 0; i < 7 && n-- > 0; ++i) ans += s + i;
            s++;
        }
        return ans;
    }
};