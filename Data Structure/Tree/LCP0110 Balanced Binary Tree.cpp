/*
����������P0110
����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������  
�����У�һ�ø߶�ƽ�����������Ϊ��
һ��������ÿ���ڵ�?���������������ĸ߶Ȳ�ľ���ֵ������ 1 ��
ʾ�� 1��
���룺root = [3,9,20,null,null,15,7]
�����true
ʾ�� 2��
���룺root = [1,2,2,3,3,null,null,4,4]
�����false
ʾ�� 3��
���룺root = []
�����true
��ʾ��
���еĽڵ����ڷ�Χ [0, 5000] ��
-104 <= Node.val <= 104
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
    int height(TreeNode* root)
    {
        if(!root)return 0;
        int lh=height(root->left),rh=height(root->right);
        if(lh<0||rh<0||abs(lh-rh)>1) return -1;
        else return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        return height(root)>=0;
    }
};