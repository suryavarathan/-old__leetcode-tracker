// Last updated: 7/14/2026, 3:25:57 PM
class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xor1=0,xor2=0;
        for(auto val:arr1) xor1^=val;
        for(auto num:arr2) xor2^=num;
        return xor1&xor2;
    }
};