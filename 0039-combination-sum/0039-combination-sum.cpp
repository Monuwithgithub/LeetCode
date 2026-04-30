class Solution {
public:
    void solve(int index, vector<int>& candidates, int target,
               vector<int>& temp, vector<vector<int>>& result) {
        
        // base case
        if (target == 0) {
            result.push_back(temp);
            return;
        }

        // traverse candidates
        for (int i = index; i < candidates.size(); i++) {
            
            // if current element exceeds target → stop
            if (candidates[i] > target) break;

            // choose
            temp.push_back(candidates[i]);

            // stay at same index (reuse allowed)
            solve(i, candidates, target - candidates[i], temp, result);

            // backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;

        sort(candidates.begin(), candidates.end()); // optimization
        solve(0, candidates, target, temp, result);

        return result;
    }
};