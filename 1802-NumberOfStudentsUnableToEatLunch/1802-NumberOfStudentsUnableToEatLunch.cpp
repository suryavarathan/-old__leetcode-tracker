// Last updated: 7/14/2026, 3:29:21 PM
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int top = 0;

        // Step 1: Give sandwiches to immediate matches, send others to the queue
        for(auto x : students){
            if(x == sandwiches[top]){
                top++;
            }
            else{
                q.push(x);
            }
        }

        int canteat = 0;

        // Step 2: Simulate the circular queue movement
        while(canteat < q.size() && top < sandwiches.size()){
            if(q.front() == sandwiches[top]){
                q.pop();
                top++;
                canteat = 0; // Reset counter since someone successfully ate
            }
            else{
                q.push(q.front()); // Move student to the back of the line
                q.pop();
                canteat++; // Increment continuous rejection counter
            }
        }
        
        // The remaining students in the queue are unable to eat
        return q.size();
    }
};