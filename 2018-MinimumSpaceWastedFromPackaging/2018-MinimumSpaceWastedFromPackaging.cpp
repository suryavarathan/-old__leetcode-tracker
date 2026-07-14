// Last updated: 7/14/2026, 3:24:51 PM
class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        sort(packages.begin(), packages.end());
        
        int n = packages.size(), m = boxes.size(), mod = (1e9 + 7);
        long res = 1e11, packages_sum = accumulate(packages.begin(), packages.end(), (long)0);
        
        for (int i = 0; i < m; ++i) {
			sort(boxes[i].begin(), boxes[i].end());
			if (packages.back() > boxes[i].back()) continue; //max size of package is greater than the max size of current suppliers box, skip this supplier;
            long boxes_sum = 0; //sum of all boxes from current box supplier i;
			int prev = 0; //pointer to the first package that fits current box size; 
            for (int j = 0; j < boxes[i].size(); ++j) {
				//binary search to find the package index which is greater than current box so we know how many boxes (cur - prev) would fit the current box size;
                int cur = upper_bound(packages.begin()+prev, packages.end(), boxes[i][j]) - packages.begin(); 
                if (cur == prev) continue; //we cannot find a package which is smaller than current box; so we move on to the next bigger box;
                boxes_sum += (long)boxes[i][j] * (cur - prev); //(cur - prev) boxes with boxes[i][j] will be used.
                prev = cur;
                if (prev == n || boxes_sum > res) break;
            }
            
            res = min(boxes_sum, res);
        }
        
        return res == 1e11? -1 : (res - packages_sum) % mod;
    }
};