/*
����������P2049
����һ�ø��ڵ�Ϊ 0 ��?������?�����ܹ��� n?���ڵ㣬�ڵ���Ϊ?0?��?n - 1?��
ͬʱ����һ���±��?0?��ʼ����������?parents?��ʾ�����������?parents[i]?�ǽڵ� i?�ĸ��ڵ㡣���ڽڵ� 0?�Ǹ�������?parents[0] == -1?��
һ�������� ��С?Ϊ��������ڽڵ����Ŀ��ÿ���ڵ㶼��һ����֮������?����?��
���ĳ���ڵ�����ķ����ǣ�������ڵ�����������ı�ȫ�� ɾ��?��ʣ�ಿ�������ɸ� �ǿ�?����������ڵ�� ����?Ϊ������Щ���� ��С�ĳ˻�?��
���㷵���� ��ߵ÷�?�ڵ�� ��Ŀ?��
ʾ��?1:
���룺parents = [-1,2,0,2,0]
�����3
���ͣ�
- �ڵ� 0 �ķ���Ϊ��3 * 1 = 3
- �ڵ� 1 �ķ���Ϊ��4 = 4
- �ڵ� 2 �ķ���Ϊ��1 * 1 * 2 = 2
- �ڵ� 3 �ķ���Ϊ��4 = 4
- �ڵ� 4 �ķ���Ϊ��4 = 4
��ߵ÷�Ϊ 4 ���������ڵ�÷�Ϊ 4 ���ֱ��ǽڵ� 1��3 �� 4 ����
ʾ�� 2��
���룺parents = [-1,2,0]
�����2
���ͣ�
- �ڵ� 0 �ķ���Ϊ��2 = 2
- �ڵ� 1 �ķ���Ϊ��2 = 2
- �ڵ� 2 �ķ���Ϊ��1 * 1 = 1
��߷���Ϊ 2 ���������ڵ����Ϊ 2 ���ֱ�Ϊ�ڵ� 0 �� 1 ����
��ʾ��
n == parents.length
2 <= n <= 105
parents[0] == -1
����?i != 0?����?0 <= parents[i] <= n - 1
parents?��ʾһ�ö�������
*/
class Solution {
public:
    long long maxscore=0;
    int n,ans=0;
    vector<vector<int>> tree;
    int dfs(int node)
    {
        long long score=1;
        int len=n-1,maxval=-1;
        for(int i:tree[node])//������ǰ�����ӽ��
        {
            int val=dfs(i);//���浱ǰ�����ӽڵ���Ŀ
            score*=val;//��ó˻�
            len-=val;//�ܳ��ȼ����ӽڵ����Ŀ
        }
        if (node) score*=len;//���Ǹ�����ʱ�򣬻���Ҫ�˸��׽��Ľ����
        if (score==maxscore) ans++;//�����𰸴���
        else if (score>maxscore)
        {
            ans=1;
            maxscore=score;
        }
        return n-len;//�����ӽڵ�ĸ���������len�Ǹýڵ�ĸ��ڵ�-1���ܽ��-lenΪ�ӽ�����
    }
    int countHighestScoreNodes(vector<int>& parents) {
        this->n=parents.size();
        this->tree=vector<vector<int>>(n);
        for(int i=0;i<n;i++)
        {
            int p=parents[i];//tree[i].size()==0��ʱ�򣬸ý��ΪҶ�ӽ��.
            if (p!=-1) tree[p].push_back(i);
        }
        dfs(0);
        return ans;
    }
};