// Last updated: 7/14/2026, 3:21:53 PM
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int p1=0,p2=0;
        int n=nums1.size();
        int m=nums2.size();
        while(p1<n && p2<m)
        {
            if(nums1[p1]>nums2[p2])
                p2++;
            else if(nums2[p2]>nums1[p1])
                p1++;
            else
                return nums1[p1];
        }
        return -1;
    }
};
