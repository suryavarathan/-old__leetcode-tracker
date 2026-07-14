// Last updated: 7/14/2026, 3:20:14 PM
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans;
        for(int i = 0; i <= grid.size() - k; i++)
        {
            vector<int> col;
            for(int j = 0; j <= grid[0].size() - k; j++)
            {
                vector<int> temp;
                for(int l = i; l < i + k; l++)
                    for(int m = j; m < j + k; m++)
                        temp.push_back(grid[l][m]);

                if(temp.size() < 2)
                {
                    col.push_back(0);
                    continue;
                }

                sort(temp.begin(), temp.end());

                int cur = INT_MAX;
                for(int o = 1; o < temp.size(); o++)
                {
                    if(temp[o] != temp[o-1])
                        cur = min(cur, temp[o] - temp[o-1]);
                }
                if(cur == INT_MAX)
                    cur = 0;

                col.push_back(cur);
            }
            ans.push_back(col);
        }
        return ans;
    }
};