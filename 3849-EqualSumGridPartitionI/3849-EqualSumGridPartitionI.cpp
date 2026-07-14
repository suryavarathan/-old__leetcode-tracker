// Last updated: 7/14/2026, 3:20:19 PM
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        
        int m = grid.size(); int n = grid[0].size();

        long long sum = 0;
        for(int i = 0; i < m; i++){

            for(int j = 0; j < n; j++){

                sum += grid[i][j];
            }
        }

        long long sum_upper = 0;
        for(int i = 0; i < m; i++){

            for(int j = 0; j < n; j++){

                sum_upper += grid[i][j];
            }

            if(sum - sum_upper == sum_upper) return true;
        }

        long long sum_left = 0;
        for(int j = 0; j < n; j++){
            for(int i =0; i < m; i++){
                sum_left += grid[i][j];
            }

            if(sum - sum_left == sum_left) return true;
        }

        return false;
    }
};