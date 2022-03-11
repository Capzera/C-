/*
����������P0226
����һ�ö������ĸ��ڵ� root ����ת��ö�����������������ڵ㡣
ʾ�� 1��
���룺root = [4,2,7,1,3,6,9]
�����[4,7,2,9,6,3,1]
ʾ�� 2��
���룺root = [2,1,3]
�����[2,3,1]
ʾ�� 3��
���룺root = []
�����[]
��ʾ��
���нڵ���Ŀ��Χ�� [0, 100] ��
-100 <= Node.val <= 100
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* left=invertTree(root->left);
        TreeNode* right=invertTree(root->right);
        root->left=right;
        root->right=left;
        return root;
    }
};