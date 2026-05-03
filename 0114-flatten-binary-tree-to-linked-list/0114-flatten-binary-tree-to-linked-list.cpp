class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;

        while (cur) {
            if (cur->left) {
                TreeNode* prev = cur->left;

                // find rightmost node of left subtree
                while (prev->right) {
                    prev = prev->right;
                }

                // connect it to right subtree
                prev->right = cur->right;

                // move left subtree to right
                cur->right = cur->left;
                cur->left = nullptr;
            }

            cur = cur->right;
        }
    }
};