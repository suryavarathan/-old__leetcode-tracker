// Last updated: 7/14/2026, 3:21:43 PM
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        // Step 1: Store indices instead of full data (memory optimized)
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);   // order = [0,1,2,...,n-1]

        // Step 2: Sort indices based on positions
        // So we process robots from left → right
        sort(order.begin(), order.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        // Stack will store indices of robots moving RIGHT ('R')
        // Why? Because only R vs L collisions matter
        stack<int> st;

        // Step 3: Process robots in sorted order
        for (int idx : order) {

            // Case 1: Robot moving RIGHT → just push into stack
            if (directions[idx] == 'R') {
                st.push(idx);
            } 
            else {
                // Case 2: Robot moving LEFT → may collide with previous R robots
                while (!st.empty() && healths[idx] > 0) {
                    int j = st.top();  // top robot moving RIGHT

                    // If right robot has less health → it dies
                    if (healths[j] < healths[idx]) {
                        st.pop();             // remove right robot
                        healths[idx]--;       // left robot loses 1 health
                        healths[j] = 0;       // mark right robot dead
                    }
                    // If right robot has more health → left robot dies
                    else if (healths[j] > healths[idx]) {
                        healths[j]--;         // right robot loses 1 health
                        healths[idx] = 0;     // left robot dies
                    }
                    // Equal health → both die
                    else {
                        st.pop();
                        healths[j] = 0;
                        healths[idx] = 0;
                    }
                }
            }
        }

        // Step 4: Collect surviving robots in original order
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                res.push_back(healths[i]);  // only survivors
            }
        }

        return res;
    }
};