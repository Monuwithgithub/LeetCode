class Solution {
    public boolean hasPathSum(TreeNode root, int targetSum) {
        
        // Base case: empty tree
        if (root == null) {
            return false;
        }
        
        // If leaf node, check sum
        if (root.left == null && root.right == null) {
            return targetSum == root.val;
        }
        
        // Recursive call for left and right subtree
        int remainingSum = targetSum - root.val;
        
        return hasPathSum(root.left, remainingSum) 
            || hasPathSum(root.right, remainingSum);
    }
}