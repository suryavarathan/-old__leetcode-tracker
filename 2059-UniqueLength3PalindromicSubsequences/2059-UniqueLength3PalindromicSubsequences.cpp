// Last updated: 7/14/2026, 3:23:51 PM
class Solution {
public:
    int countPalindromicSubsequence(string& s) {
        static constexpr int len = 26;
        std::uint32_t n = s.size();
        using bitset = std::bitset<len>;
        std::vector<bitset> sfx(n);
        sfx.back().set(s.back() - 'a');
        for (int i = n - 2; i >= 0; --i) {
            sfx[i].set(s[i] - 'a');
            sfx[i] |= sfx[i + 1];
        }
        bitset pfx;
        pfx.set(s.front() - 'a');
        std::vector<bitset> hs(len);
        for (int i = 1, sz = n - 1; i < sz; ++i) {
            int idx = s[i] - 'a';
            bitset bits = sfx[i + 1] & pfx;
            hs[idx] |= bits;
            pfx.set(idx);
        }
        int ans = 0;
        for (bitset bit : hs)
            ans += bit.count();
        return ans;
    }
};