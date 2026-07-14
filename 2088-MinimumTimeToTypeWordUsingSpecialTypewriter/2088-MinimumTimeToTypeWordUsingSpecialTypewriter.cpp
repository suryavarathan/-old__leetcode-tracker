// Last updated: 7/14/2026, 3:23:19 PM
class Solution {
public:
    int minTimeToType(string word) {
        int cnt = 0;
        char cur = 'a';
        for (char& c : word)
        {
            int d = abs(c - cur);
            cur = c;
            cnt += min(d, 26 - d);
            cnt++;
        }
        return cnt;
    }
};