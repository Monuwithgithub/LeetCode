class Solution {
public:
    void solve(int start, int n, int k, vector<int>& temp, vector<vector<int>>& result) {
        
        // base case
        if (temp.size() == k) {
            result.push_back(temp);
            return;
        }

        // choose next numbers
        for (int i = start; i <= n; i++) {
            temp.push_back(i);              // choose
            solve(i + 1, n, k, temp, result); // move forward
            temp.pop_back();                // backtrack
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;

        solve(1, n, k, temp, result);
        return result;
    }
};