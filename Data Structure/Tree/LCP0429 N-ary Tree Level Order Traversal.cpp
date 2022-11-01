/*
����������P0429
����һ�� N ������������ڵ�ֵ�Ĳ�����������������ң�����������
�������л��������ò��������ÿ���ӽڵ㶼�� null ֵ�ָ����μ�ʾ������
ʾ�� 1��
���룺root = [1,null,3,2,4,null,5,6]
�����[[1],[3,2,4],[5,6]]
ʾ�� 2��
���룺root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
�����[[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
��ʾ��
���ĸ߶Ȳ��ᳬ��?1000
���Ľڵ������� [0,?10^4] ֮��
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
    vector<vector<int>> ans;
    vector<int> tmp;
    void dfs(Node* root,int depth)
    {
        if (!root) return;
        if (ans.size()==depth) ans.push_back(tmp);
        ans[depth].push_back(root->val);
        int n=root->children.size();
        for(int i=0;i<n;i++) dfs(root->children[i],depth+1);
    }
    vector<vector<int>> levelOrder(Node* root) {
        dfs(root,0);
        return ans;
    }
};