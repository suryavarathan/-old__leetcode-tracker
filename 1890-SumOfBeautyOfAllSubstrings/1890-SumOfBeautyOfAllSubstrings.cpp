// Last updated: 7/14/2026, 3:27:35 PM
class Solution {
public:
    int maxCount(vector<int> &freq){
        int maxCount = 0;
        for (int count : freq) {
            maxCount = std::max(maxCount, count);
        }
        return maxCount;
        
    }
    int minCount(vector<int> &freq){
        int minCount = INT_MAX;
        for (int count : freq) {
            if (count != 0) {
                minCount = std::min(minCount, count);
            }
        }
        return minCount;
    }
    int beautySum(string s) {
        int sum=0;
        int n=s.size();
        for(int i=0; i<n; i++){
            vector <int> freq(26, 0);
            for(int j=i; j<n; j++){
                freq[s[j]- 'a']++;
                int beauty = maxCount(freq) - minCount(freq);
                sum += beauty;
            }
        }
        return sum;
    }
};