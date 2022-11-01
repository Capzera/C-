/*
����������P0589
����һ�� n?�����ĸ��ڵ� ?root?������ ��ڵ�ֵ�� ǰ����� ��
n ���� �������а���������������л���ʾ��ÿ���ӽڵ��ɿ�ֵ null �ָ�����μ�ʾ������
ʾ�� 1��
���룺root = [1,null,3,2,4,null,5,6]
�����[1,3,5,6,2,4]
ʾ�� 2��
���룺root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
�����[1,2,3,6,7,11,14,4,8,12,5,9,13,10]
��ʾ��
�ڵ������ڷ�Χ?[0, 104]��
0 <= Node.val <= 104
n �����ĸ߶�С�ڻ���� 1000
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> ans;
    void _po(Node* root)
    {
        if (!root) return;
        ans.push_back(root->val);
        int n=root->children.size();
        for(int i=0;i<n;i++) _po(root->children[i]);
    }
    vector<int> preorder(Node* root) {
        _po(root);
        return ans;
    }
};