class Solution {
public:
    void dfs(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& ans) {
        if (!root) return;

        path.push_back(root->val);
        targetSum -= root->val;

        if (!root->left && !root->right && targetSum == 0) {
            ans.push_back(path);
        } else {
            dfs(root->left, targetSum, path, ans);
            dfs(root->right, targetSum, path, ans);
        }

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, targetSum, path, ans);
        return ans;
    }
};