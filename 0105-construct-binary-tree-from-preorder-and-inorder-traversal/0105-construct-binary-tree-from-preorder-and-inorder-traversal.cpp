class Solution {
public:
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd,
                              vector<int>& inorder, int inStart, int inEnd,
                              unordered_map<int,int>& mp) {
        if (preStart > preEnd || inStart > inEnd) return NULL;

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int inRoot = mp[rootVal];
        int numsLeft = inRoot - inStart;

        root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft,
                                     inorder, inStart, inRoot - 1, mp);

        root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd,
                                      inorder, inRoot + 1, inEnd, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, 0, preorder.size() - 1,
                               inorder, 0, inorder.size() - 1, mp);
    }
};