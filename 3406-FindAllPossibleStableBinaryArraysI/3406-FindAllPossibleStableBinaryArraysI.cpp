// Last updated: 7/14/2026, 3:21:03 PM
class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<int>> dp0(zero + 1, vector<int>(one + 1, 0));
        vector<vector<int>> dp1(zero + 1, vector<int>(one + 1, 0));

        // only 0s
        for (int i = 1; i <= min(zero, limit); i++) {
            dp0[i][0] = 1;
        }

        // only 1s
        for (int j = 1; j <= min(one, limit); j++) {
            dp1[0][j] = 1;
        }

        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {
                if (i == 0 && j == 0) continue;

                if (i > 0 && j > 0) {
                    long long ways0 = 0;
                    for (int k = 1; k <= limit && i - k >= 0; k++) {
                        ways0 = (ways0 + dp1[i - k][j]) % MOD;
                    }
                    dp0[i][j] = ways0;

                    long long ways1 = 0;
                    for (int k = 1; k <= limit && j - k >= 0; k++) {
                        ways1 = (ways1 + dp0[i][j - k]) % MOD;
                    }
                    dp1[i][j] = ways1;
                }
            }
        }

        return (dp0[zero][one] + dp1[zero][one]) % MOD;
    }
};