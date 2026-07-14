// Last updated: 7/14/2026, 3:22:06 PM
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> arr1;
        vector<int> arr2;
        vector<int> arr3;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                arr1.push_back(nums[i]);
            }
            else if (nums[i] == pivot) {
                arr2.push_back(nums[i]);
            }
            else {
                arr3.push_back(nums[i]);
            }
        }

        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        arr1.insert(arr1.end(), arr3.begin(), arr3.end());

        return arr1;
    }
};