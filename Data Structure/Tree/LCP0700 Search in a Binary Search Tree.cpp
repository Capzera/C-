/*
����������P0700
����������������BST���ĸ��ڵ�?root?��һ������ֵ?val��
����Ҫ�� BST ���ҵ��ڵ�ֵ����?val?�Ľڵ㡣 �����Ըýڵ�Ϊ���������� ����ڵ㲻���ڣ��򷵻�?null?��
ʾ�� 1:
���룺root = [4,2,7,1,3], val = 2
�����[2,1,3]
Example 2:
���룺root = [4,2,7,1,3], val = 5
�����[]
��ʾ��
���нڵ�����?[1, 5000]?��Χ��
1 <= Node.val <= 107
root?�Ƕ���������
1 <= val <= 107
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return NULL;
        if (val<root->val) return searchBST(root->left,val);
        if (val>root->val) return searchBST(root->right,val);
        else return root;
    }
};