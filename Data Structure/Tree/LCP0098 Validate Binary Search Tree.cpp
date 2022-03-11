/*
����������P0098
����һ���������ĸ��ڵ� root ���ж����Ƿ���һ����Ч�Ķ�����������
��Ч �����������������£�
�ڵ��������ֻ���� С�� ��ǰ�ڵ������
�ڵ��������ֻ���� ���� ��ǰ�ڵ������
�������������������������Ҳ�Ƕ�����������
ʾ�� 1��
���룺root = [2,1,3]
�����true
ʾ�� 2��
���룺root = [5,1,4,null,null,3,6]
�����false
���ͣ����ڵ��ֵ�� 5 ���������ӽڵ��ֵ�� 4 ��
��ʾ��
���нڵ���Ŀ��Χ��[1, 104] ��
-231 <= Node.val <= 231 - 1
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
    bool judge(TreeNode* root,long long minval,long long maxval)
    {
        if (!root) return 1;
        if (root->val<=minval||root->val>=maxval) return false;
        return judge(root->left,minval,root->val)&&judge(root->right,root->val,maxval);
    }
    bool isValidBST(TreeNode* root) {
        return judge(root,LONG_MIN,LONG_MAX);
    }
};