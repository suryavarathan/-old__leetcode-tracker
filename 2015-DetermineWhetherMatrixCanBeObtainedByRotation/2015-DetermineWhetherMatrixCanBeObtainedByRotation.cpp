// Last updated: 7/14/2026, 3:24:56 PM
class Solution {
    void rotate(vector<vector<int>>& mat){
        vector<vector<int>> temp=mat;
        int n=mat.size();
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.size();j++){
                temp[i][j]=mat[j][n-i-1];
            }
        }
        mat=temp;
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        //after rotation of 90 degree row changes to col and vice versa
        int n=mat.size();
        for(int i=0;i<4;i++){
            if(mat==target) return true;
            rotate(mat);
        }
        return false;
    }
};
