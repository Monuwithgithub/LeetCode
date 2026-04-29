class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& temp, vector<bool>& used) {
        // if permutation complete
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            // choose
            temp.push_back(nums[i]);
            used[i] = true;

            // explore
            backtrack(nums, result, temp, used);

            // backtrack
            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> used(nums.size(), false);

        backtrack(nums, result, temp, used);
        return result;
    }
};