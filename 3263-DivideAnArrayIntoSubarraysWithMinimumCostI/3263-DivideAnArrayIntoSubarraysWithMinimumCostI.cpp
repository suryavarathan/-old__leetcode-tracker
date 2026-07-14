// Last updated: 7/14/2026, 3:21:17 PM
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int s=0;

        if(nums.size()==3){
            for(auto i:nums){
                s+=i;
            }
            return s;
        }
        s=nums[0];
        int f=INT_MAX;
        int l=INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=f){
                l=f;
                f=nums[i];
            }
            else if(nums[i]>f && nums[i]<l){
                l=nums[i];
            }
        }
        return s+f+l;

    }
};