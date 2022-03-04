/*
����������P0102
����������ĸ��ڵ� root ��������ڵ�ֵ�� ������� �� �������أ������ҷ������нڵ㣩��
ʾ�� 1��
���룺root = [3,9,20,null,null,15,7]
�����[[3],[9,20],[15,7]]
ʾ�� 2��
���룺root = [1]
�����[[1]]
ʾ�� 3��
���룺root = []
�����[]
��ʾ��
���нڵ���Ŀ�ڷ�Χ [0, 2000] ��
-1000 <= Node.val <= 1000\
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root==NULL) return ans;
        queue<TreeNode*> Q;
        int i;
        Q.push(root);
        while (!Q.empty())
        {
            int n=Q.size();
            vector<int> tmp;
            for(i=0;i<n;i++)
            {
                TreeNode* node=Q.front();
                tmp.push_back(node->val);
                Q.pop();
                if (node->left!=NULL) Q.push(node->left);
                if (node->right!=NULL) Q.push(node->right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};