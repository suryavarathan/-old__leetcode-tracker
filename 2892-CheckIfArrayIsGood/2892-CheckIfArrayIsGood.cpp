// Last updated: 7/14/2026, 3:21:39 PM
class Solution {
public:
    bool isGood(vector<int>& nums) 
    {
        int n = nums.size();
        if(n==1) return false;
        vector<int> temp(201,0);
        for(int i=0;i<n;i++)
        {
            temp[nums[i]]++;
        }
        for(int i=1;i<n;i++)
        {
            if(i==n-1) 
            {
                if(temp[i]!=2) return false;
            }
            else
            {
                if(temp[i]!=1) return false;
            }
        }
        return true;
    }
};
