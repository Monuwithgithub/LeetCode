#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void solve(int open, int close, int n, string &current, vector<string> &result) {
        // Base case
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add '('
        if (open < n) {
            current.push_back('(');
            solve(open + 1, close, n, current, result);
            current.pop_back(); // backtrack
        }

        // Add ')'
        if (close < open) {
            current.push_back(')');
            solve(open, close + 1, n, current, result);
            current.pop_back(); // backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current = "";
        solve(0, 0, n, current, result);
        return result;
    }
};