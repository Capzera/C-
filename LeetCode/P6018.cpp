/*
����������P6018 ���۵�283������
����һ����ά�������� descriptions ������ descriptions[i] = [parenti, childi, isLefti] 
��ʾ parenti �� childi �� ������ �е� ���ڵ㣬�������и��ڵ��ֵ ������ͬ �����⣺
��� isLefti == 1 ����ô childi ���� parenti �����ӽڵ㡣
��� isLefti == 0 ����ô childi ���� parenti �����ӽڵ㡣
������� descriptions ������������������������� ���ڵ� ��
���������ᱣ֤���Թ���� ��Ч �Ķ�������
ʾ�� 1��
���룺descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
�����[50,20,80,15,17,19]
���ͣ����ڵ���ֵΪ 50 �Ľڵ㣬��Ϊ��û�и��ڵ㡣
�������������ͼ��ʾ��
ʾ�� 2��
���룺descriptions = [[1,2,1],[2,3,0],[3,4,1]]
�����[1,2,null,null,3,4]
���ͣ����ڵ���ֵΪ 1 �Ľڵ㣬��Ϊ��û�и��ڵ㡣 
�������������ͼ��ʾ�� 
��ʾ��
1 <= descriptions.length <= 104
descriptions[i].length == 3
1 <= parenti, childi <= 105
0 <= isLefti <= 1
descriptions �������Ķ�������һ����Ч������
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {    
        unordered_map<int,TreeNode*> um1;//����ÿ���Ӷ�����
        unordered_map<int,int> um2;//����ÿ�������Ϊ���ӵĴ�����Ϊ0�ε�Ϊ���ո��ڵ�
        for (vector<int>& i:descriptions)
        {
            if (!um1.count(i[0])) um1[i[0]] = new TreeNode(i[0]);
            if (!um1.count(i[1])) um1[i[1]] = new TreeNode(i[1]);//�����µĽ��
            if (i[2]) um1[i[0]]->left=um1[i[1]];//Ϊ���ӵ�ʱ��
            else um1[i[0]]->right=um1[i[1]];
            um2[i[1]]++;
        }
        for (auto [i,node]:um1)
            if (um2[i]==0) return node;
        return nullptr;
    }
};