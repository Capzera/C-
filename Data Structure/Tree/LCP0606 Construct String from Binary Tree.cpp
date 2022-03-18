/*
����������P0606
����Ҫ����ǰ������ķ�ʽ����һ��������ת����һ�������ź�������ɵ��ַ�����
�սڵ�����һ�Կ����� "()" ��ʾ����������Ҫʡ�����в�Ӱ���ַ�����ԭʼ������֮���һ��һӳ���ϵ�Ŀ����Ŷԡ�
ʾ�� 1:
����: ������: [1,2,3,4]
       1
     /   \
    2     3
   /    
  4     
���: "1(2(4))(3)"
����: ԭ�����ǡ�1(2(4)())(3())����
����ʡ�����в���Ҫ�Ŀ����Ŷ�֮��
�����ǡ�1(2(4))(3)����
ʾ�� 2:
����: ������: [1,2,3,null,4]
       1
     /   \
    2     3
     \  
      4 
���: "1(2()(4))(3)"
����: �͵�һ��ʾ�����ƣ�
�������ǲ���ʡ�Ե�һ�����������ж���������֮���һ��һӳ���ϵ��
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
    string ans="";
    void preorder(TreeNode* root) {
        if (!root) {
            return;
        }
        ans+=to_string(root->val);
        if (root->left) {
            ans+='(';
            preorder(root->left);
            ans+=')';
        }
        if (root->right) {
            if(!root->left) ans+="()";
            ans+='(';
            preorder(root->right);
            ans+=')';           
        }
    }
    string tree2str(TreeNode* root) {
        preorder(root);
        return ans;
    }
};