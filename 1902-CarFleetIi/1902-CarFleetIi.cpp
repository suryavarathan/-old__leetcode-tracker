// Last updated: 7/14/2026, 3:27:17 PM
class Solution {
public:
vector<double> getCollisionTimes(vector<vector<int>>& car) {
    int n = car.size();
    stack<int> stk;
    vector<double> res(n, -1);

    for(int i = n - 1; i >= 0; --i){
        while(!stk.empty() && car[i][1] <= car[stk.top()][1]) stk.pop();

        while(!stk.empty()){
            double time = (car[stk.top()][0] - car[i][0]) / (double)(car[i][1] - car[stk.top()][1]); 

            if(res[stk.top()] >= time || res[stk.top()] == -1){
                res[i] = time;
                break;
            }

            stk.pop();
        }


        stk.push(i);
    }

    return res;

    
}
};