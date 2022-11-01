/*
����������P0559
����һ�� N �������ҵ��������ȡ�
��������ָ�Ӹ��ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�������
N �������밴����������л���ʾ��ÿ���ӽڵ��ɿ�ֵ�ָ�����μ�ʾ������
ʾ�� 1��
���룺root = [1,null,3,2,4,null,5,6]
�����3
ʾ�� 2��
���룺root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
�����5
��ʾ��
������Ȳ��ᳬ��?1000 ��
���Ľڵ���Ŀλ�� [0,?104] ֮�䡣
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
    int maxDepth(Node* root) {
        if (!root) return 0;
		int ans=0;
        for (auto& node:root->children) ans=max(ans,maxDepth(node));
        return ans+1;
    }
};