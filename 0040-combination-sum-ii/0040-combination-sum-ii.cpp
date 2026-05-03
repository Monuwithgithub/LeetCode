class Solution {
public:
    void solve(int index, int target, vector<int>& candidates, 
               vector<int>& path, vector<vector<int>>& result) {

        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            // If element is greater than target → stop
            if (candidates[i] > target) break;

            path.push_back(candidates[i]);

            // Move to next index (cannot reuse same element)
            solve(i + 1, target - candidates[i], candidates, path, result);

            path.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;

        // Sort to handle duplicates
        sort(candidates.begin(), candidates.end());

        solve(0, target, candidates, path, result);

        return result;
    }
};