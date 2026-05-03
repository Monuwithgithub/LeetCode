class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        // If all characters are matched
        if (index == word.size()) return true;

        // Boundary check + character match
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() 
            || board[i][j] != word[index]) {
            return false;
        }

        // Mark current cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore all 4 directions
        bool found = dfs(board, word, i+1, j, index+1) ||
                     dfs(board, word, i-1, j, index+1) ||
                     dfs(board, word, i, j+1, index+1) ||
                     dfs(board, word, i, j-1, index+1);

        // Backtrack (restore original value)
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};