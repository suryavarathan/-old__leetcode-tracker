// Last updated: 7/14/2026, 3:22:18 PM
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        
        // Edge case
        if (rows == 0) return "";
        
        int cols = n / rows;
        
        // Step 1: Fill matrix row-wise
        vector<vector<char>> matrix(rows, vector<char>(cols));
        
        int index = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = encodedText[index++];
            }
        }
        
        // Step 2: Traverse diagonally
        string result = "";
        
        for (int startCol = 0; startCol < cols; startCol++) {
            int i = 0;
            int j = startCol;
            
            while (i < rows && j < cols) {
                result += matrix[i][j];
                i++;
                j++;
            }
        }
        
        // Step 3: Remove trailing spaces
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        
        return result;
    }
};
