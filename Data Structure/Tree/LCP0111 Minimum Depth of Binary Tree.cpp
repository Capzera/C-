/*
����������P0111
����һ�����������ҳ�����С��ȡ�
��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������
˵����Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
ʾ�� 1��
���룺root = [3,9,20,null,null,15,7]
�����2
ʾ�� 2��
���룺root = [2,null,3,null,4,null,5,null,6]
�����5
��ʾ��
���нڵ����ķ�Χ�� [0, 105] ��
-1000 <= Node.val <= 1000
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left&&!root->right) return 1;
        int l=minDepth(root->left),r=minDepth(root->right);
        if (!root->left||!root->right) return l+r+1;
        return min(l,r)+1;
    }
};