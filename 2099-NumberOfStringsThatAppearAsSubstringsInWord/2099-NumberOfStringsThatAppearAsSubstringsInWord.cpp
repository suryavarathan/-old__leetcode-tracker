// Last updated: 7/14/2026, 3:23:05 PM
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (const string& s : patterns)
            if (word.find(s) != string::npos) count++;
        return count;
    }
};