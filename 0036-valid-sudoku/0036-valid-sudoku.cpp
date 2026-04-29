class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // sets to track row, column, and box
        unordered_set<string> seen;
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                
                if (board[i][j] != '.') {
                    char num = board[i][j];
                    
                    string row = string(1, num) + " in row " + to_string(i);
                    string col = string(1, num) + " in col " + to_string(j);
                    string box = string(1, num) + " in box " + to_string(i/3) + "-" + to_string(j/3);
                    
                    // if already seen → invalid
                    if (seen.count(row) || seen.count(col) || seen.count(box)) {
                        return false;
                    }
                    
                    seen.insert(row);
                    seen.insert(col);
                    seen.insert(box);
                }
            }
        }
        
        return true;
    }
};