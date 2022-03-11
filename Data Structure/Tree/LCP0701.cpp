/*
����������P0701
����������������BST���ĸ��ڵ�?root?��Ҫ�������е�ֵ?value?����ֵ��������������� 
���ز��������������ĸ��ڵ㡣 �������� ��֤ ����ֵ��ԭʼ�����������е�����ڵ�ֵ����ͬ��
ע�⣬���ܴ��ڶ�����Ч�Ĳ��뷽ʽ��ֻҪ���ڲ�����Ա���Ϊ�������������ɡ� ����Է��� ������Ч�Ľ�� ��
ʾ�� 1��
���룺root = [4,2,7,1,3], val = 5
�����[4,2,7,1,3,5]
���ͣ���һ��������ĿҪ�����ͨ�������ǣ�
ʾ�� 2��
���룺root = [40,20,60,10,30,50,70], val = 25
�����[40,20,60,10,30,50,70,null,null,25]
ʾ�� 3��
���룺root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
�����[4,2,7,1,3,5]
��ʾ��
���еĽڵ�������?[0,?104]�ķ�Χ�ڡ�
-108?<= Node.val <= 108
����ֵ?Node.val?��?��һ�޶�?�ġ�
-108?<= val <= 108
��֤?val?��ԭʼBST�в����ڡ�
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val<root->val) root->left=insertIntoBST(root->left,val);
        else root->right=insertIntoBST(root->right,val);
        return root;
    }
};