// Last updated: 7/14/2026, 3:20:42 PM
class Solution {
public:

    int digSum(int n)
    {
        int sum=0;
        while(n)
        {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(ans>digSum(nums[i])) ans= digSum(nums[i]);
        }
        return ans;
    }
};