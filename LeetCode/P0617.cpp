/*
�����������ϲ�������
�������ö������� rooroot1 �� rooroot2 ��

����һ�£����㽫����һ�ø��ǵ���һ��֮��ʱ���������ϵ�һЩ�ڵ㽫���ص�������һЩ���ᣩ��
����Ҫ�����������ϲ���һ���¶��������ϲ��Ĺ����ǣ���������ڵ��ص�����ô���������ڵ��ֵ�����Ϊ�ϲ���ڵ����ֵ��
���򣬲�Ϊ null �Ľڵ㽫ֱ����Ϊ�¶������Ľڵ㡣
���غϲ���Ķ�������
ע��: �ϲ����̱�����������ĸ��ڵ㿪ʼ��
ʾ�� 1��
���룺rooroot1 = [1,3,2,5], rooroot2 = [2,1,3,null,4,null,7]
�����[3,4,5,5,4,null,7]
ʾ�� 2��
���룺rooroot1 = [1], rooroot2 = [1,2]
�����[2,2]
��ʾ��
�������еĽڵ���Ŀ�ڷ�Χ [0, 2000] ��
-104 <= Node.val <= 104
*/
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1&&!root2) return 0;
        TreeNode *root=new TreeNode(0);
        if(root1) root->val+=root1->val;
        if(root2) root->val+=root2->val;
        root->left=mergeTrees(root1?root1->left:0,root2?root2->left:0);
        root->right=mergeTrees(root1?root1->right:0,root2?root2->right:0);
        return root;
    }
};