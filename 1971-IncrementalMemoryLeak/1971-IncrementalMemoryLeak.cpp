// Last updated: 7/14/2026, 3:25:46 PM
// OJ: https://leetcode.com/problems/incremental-memory-leak/
// Author: github.com/lzl124631x
// Time: O(sqrt(A + B))
// Space: O(1)
class Solution {
public:
    vector<int> memLeak(int A, int B) {
        int i = 1;
        while (A >= i || B >= i) {
            if (A >= B) {
                A -= i;
            } else {
                B -= i;
            }
            ++i;
        }
        return {i, A, B};
    }
};