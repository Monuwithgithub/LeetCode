/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int getSize(ListNode* head) {
        int n = 0;
        while (head) {
            n++;
            head = head->next;
        }
        return n;
    }

    TreeNode* build(ListNode*& head, int l, int r) {
        if (l > r) return nullptr;

        int mid = l + (r - l) / 2;

        TreeNode* leftChild = build(head, l, mid - 1);

        TreeNode* root = new TreeNode(head->val);
        root->left = leftChild;

        head = head->next;

        root->right = build(head, mid + 1, r);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n = getSize(head);
        return build(head, 0, n - 1);
    }
};