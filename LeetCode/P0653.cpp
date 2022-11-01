/*
����������P0653
����һ������������ root ��һ��Ŀ���� k����� BST �д�������Ԫ�������ǵĺ͵��ڸ�����Ŀ�������򷵻� true��
ʾ�� 1��
����: root = [5,3,6,2,4,null,7], k = 9
���: true
ʾ�� 2��
����: root = [5,3,6,2,4,null,7], k = 28
���: false
��ʾ:
�������Ľڵ�����ķ�Χ��??[1, 104].
-104?<= Node.val <= 104
root?Ϊ����������
-105?<= k <= 105
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
    map<int,int> nums;
    void preorder(TreeNode* root)
    {
        if (!root) return;
        nums[root->val]++;
        preorder(root->left);
        preorder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        preorder(root);
        map<int,int> num(nums);
        for(auto& i:num)
        {
            i.second--;
            nums[i.first]--;
            if (nums[k-i.first]) return true;
            i.second++;
            nums[i.first]++;
        }
        return false;
    }
};