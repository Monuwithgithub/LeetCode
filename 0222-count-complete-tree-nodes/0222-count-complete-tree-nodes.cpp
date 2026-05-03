class Solution {
public:
    int getLeftHeight(TreeNode* node) {
        int h = 0;
        while (node) {
            h++;
            node = node->left;
        }
        return h;
    }

    int getRightHeight(TreeNode* node) {
        int h = 0;
        while (node) {
            h++;
            node = node->right;
        }
        return h;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int lh = getLeftHeight(root);
        int rh = getRightHeight(root);

        // If heights are equal → perfect binary tree
        if (lh == rh) {
            return (1 << lh) - 1;
        }

        // Otherwise recurse
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};