/*
����������P1305
����?root1 �� root2?�����ö��������������㷵��һ���б����а���?������?�е������������� ���� ����.
ʾ�� 1��
���룺root1 = [2,1,4], root2 = [1,0,3]
�����[0,1,1,2,3,4]
ʾ�� 2��
���룺root1 = [1,null,8], root2 = [8,1]
�����[1,1,8,8]
��ʾ��
ÿ�����Ľڵ�����?[0, 5000] ��Χ��
-105?<= Node.val <= 105
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
    vector<int> v1,v2;
    void po(TreeNode* root,vector<int>& v){
        if (!root) return;
        po(root->left,v);
        v.push_back(root->val);
        po(root->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        po(root1,v1);
        po(root2,v2);
        vector<int> ans;
        int n1=v1.size(),n2=v2.size();
        int i=0,j=0;
        while (i<n1&&j<n2) {
            if (v1[i]<=v2[j]) ans.push_back(v1[i++]);
            else ans.push_back(v2[j++]);
        }
        while (i<n1) ans.push_back(v1[i++]);
        while (j<n2) ans.push_back(v2[j++]);
        return ans;
    }
};