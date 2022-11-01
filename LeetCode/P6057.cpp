/*
����������P6057 ���۵�291������
����һ�ö������ĸ��ڵ� root ���ҳ�����������Ҫ��Ľڵ�����Ҫ��ڵ��ֵ������ ���� ��ֵ�� ƽ��ֵ ��
ע�⣺
n ��Ԫ�ص�ƽ��ֵ������ n ��Ԫ�� ��� Ȼ���ٳ��� n ���� �������� �������������
root �� ���� �� root ���������к����ɡ�
ʾ�� 1��
���룺root = [4,8,5,0,1,null,6]
�����5
���ͣ�
��ֵΪ 4 �Ľڵ㣺������ƽ��ֵ (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4 ��
��ֵΪ 5 �Ľڵ㣺������ƽ��ֵ (5 + 6) / 2 = 11 / 2 = 5 ��
��ֵΪ 0 �Ľڵ㣺������ƽ��ֵ 0 / 1 = 0 ��
��ֵΪ 1 �Ľڵ㣺������ƽ��ֵ 1 / 1 = 1 ��
��ֵΪ 6 �Ľڵ㣺������ƽ��ֵ 6 / 1 = 6 ��
ʾ�� 2��
���룺root = [1]
�����1
���ͣ���ֵΪ 1 �Ľڵ㣺������ƽ��ֵ 1 / 1 = 1��
��ʾ��
���нڵ���Ŀ�ڷ�Χ [1, 1000] ��
0 <= Node.val <= 1000
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
    TreeNode* tree=new TreeNode;
    TreeNode* cnt=new TreeNode;
    void preorder(TreeNode* root,TreeNode* tree,TreeNode* cnt) {
        if (!root) return ;
        tree->val=root->val;
        if (root->left) {
            TreeNode* p=new TreeNode();
            TreeNode* q=new TreeNode();
            tree->left=p;
            cnt->left=q;
            preorder(root->left,tree->left,cnt->left);
        }
        if (root->right){
            TreeNode* p=new TreeNode();
            TreeNode* q=new TreeNode();
            tree->right=p;
            cnt->right=q;
            preorder(root->right,tree->right,cnt->right);
        }
    }
    int dep(TreeNode* cnt) {
        if (!cnt) return 0;
        int val1=dep(cnt->left),val2=dep(cnt->right);
        cnt->val=val1+val2+1;
        return cnt->val;
    }
    int cul(TreeNode* tree) {
        if (!tree) return 0;
        int val1=cul(tree->left),val2=cul(tree->right); 
        tree->val+=val1+val2;
        return tree->val;   
    }
    void po(TreeNode* root,TreeNode* tree,TreeNode* cnt){
        if (!tree||!cnt||!root) return;
        if (tree->val/cnt->val==root->val) ans++;
        po(root->left,tree->left,cnt->left);
        po(root->right,tree->right,cnt->right);
    }
    int averageOfSubtree(TreeNode* root) {
        preorder(root,tree,cnt);
        dep(cnt);
        cul(tree);
        po(root,tree,cnt);    
        return ans;
    }
};