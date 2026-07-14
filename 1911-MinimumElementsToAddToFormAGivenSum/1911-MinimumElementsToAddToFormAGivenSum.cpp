// Last updated: 7/14/2026, 3:27:04 PM
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        return (abs(accumulate(nums.begin() , nums.end() , 0L) - goal) + limit - 1) / limit;
    }
};