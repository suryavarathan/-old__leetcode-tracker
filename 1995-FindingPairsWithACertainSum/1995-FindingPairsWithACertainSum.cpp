// Last updated: 7/14/2026, 3:25:18 PM
class FindSumPairs {
private:
    vector <int> v1, v2;
    unordered_map <int, int> map;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1 = nums1;
        v2 = nums2;
        for (int num : v2) {
            map[num]++;
        }
    }
    
    void add(int index, int val) {
        v2[index] += val;
        map[v2[index] - val]--;
        map[v2[index]]++;
    }
    
    int count(int tot) {
        int count = 0;
        for (int num : v1) {
            if (map.find(tot - num) != map.end()) {
                count += map[tot - num];
            }
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */