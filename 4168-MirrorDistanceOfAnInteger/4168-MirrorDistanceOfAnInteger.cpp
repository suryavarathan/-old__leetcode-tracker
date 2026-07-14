// Last updated: 7/14/2026, 3:19:14 PM
class Solution {
public:
    int mirrorDistance(int n) {
        int reverse = 0 ;
        int temp = n ;
        while (temp > 0){
            reverse = (reverse * 10) + (temp % 10);
            temp /= 10 ;
        }
        return abs(n - reverse) ;
    }
};