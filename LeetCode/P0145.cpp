/*
����������P0145
����һ�ö������ĸ��ڵ� root ��������ڵ�ֵ�� ������� ��
ʾ�� 1��
���룺root = [1,null,2,3]
�����[3,2,1]
ʾ�� 2��
���룺root = []
�����[]
ʾ�� 3��
���룺root = [1]
�����[1]
��ʾ��
���нڵ����Ŀ�ڷ�Χ [0, 100] ��
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
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        if (root!=NULL)
        {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            ans.push_back(root->val);
        }
        return ans;
    }
};