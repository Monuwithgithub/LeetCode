class Solution {
public:
    bool solve(TreeNode* root, long long minVal, long long maxVal) {
        if (!root) return true;

        // Current node must lie in valid range
        if (root->val <= minVal || root->val >= maxVal) return false;

        // Check left and right subtree with updated range
        return solve(root->left, minVal, root->val) &&
               solve(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};