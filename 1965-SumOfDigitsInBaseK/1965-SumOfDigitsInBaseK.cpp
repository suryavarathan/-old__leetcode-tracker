// Last updated: 7/14/2026, 3:25:55 PM
class Solution {
public:
    int sumBase(int n, int k) {
        int sum = 0;

        while (n) {
            sum += n % k;
            n /= k;
        }

        return sum;
    }
};
