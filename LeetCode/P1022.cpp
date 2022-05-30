/*
����������P1022
����һ�ö�����������ÿ������ֵ����?0?��?1?��ÿһ���Ӹ���Ҷ��·��������һ���������Чλ��ʼ�Ķ���������
���磬���·��Ϊ?0 -> 1 -> 1 -> 0 -> 1����ô����ʾ��������?01101��Ҳ����?13?��
�����ϵ�ÿһƬҶ�ӣ����Ƕ�Ҫ�ҳ��Ӹ�����Ҷ�ӵ�·������ʾ�����֡�
������Щ����֮�͡���Ŀ���ݱ�֤����һ�� 32 λ ������
ʾ�� 1��
���룺root = [1,0,1,0,1,0,1]
�����22
���ͣ�(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
ʾ�� 2��
���룺root = [0]
�����0
��ʾ��
���еĽڵ�����?[1, 1000]?��Χ��
Node.val?��Ϊ 0 �� 1?
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
    int ans=0;
    void preorder(TreeNode* root,int cur){
        if (!root) return;
        if (!root->left&&!root->right) {
            ans+=cur*2+root->val;
            return;
        }
        preorder(root->left,cur*2+root->val);
        preorder(root->right,cur*2+root->val);
    }
    int sumRootToLeaf(TreeNode* root) {
        preorder(root,0);
        return ans;
    }
};