class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            // If both nodes are smaller → go left
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            // If both nodes are greater → go right
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            // Otherwise, current node is LCA
            else {
                return root;
            }
        }
        return NULL;
    }
};