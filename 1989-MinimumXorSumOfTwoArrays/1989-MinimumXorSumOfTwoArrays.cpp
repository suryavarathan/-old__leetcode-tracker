// Last updated: 7/14/2026, 3:25:25 PM
class Solution {
public:
    int dp[1 << 14];

    int f(int mask, int lst, vector<int>& A, vector<int>& B) {
        if(mask == (1 << A.size()) - 1)
            return 0;

        int& ret = dp[mask];

        if(~ret)    
            return ret;

        ret = 1e9;

        for(int i = 0; i < A.size(); ++i) {
            if(mask & (1 << i))
                continue;

            ret = min(ret, (A[lst] ^ B[i]) + f(mask | (1 << i), lst + 1, A, B));
        }

        return ret;
    }

    int minimumXORSum(vector<int>& A, vector<int>& B) {
        memset(dp, -1, sizeof dp);
        return f(0, 0, A, B);
    }
};