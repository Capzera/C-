/*
����������P0077
������������ n �� k�����ط�Χ [1, n] �����п��ܵ� k ��������ϡ�
����԰� �κ�˳�� ���ش𰸡�
ʾ�� 1��
���룺n = 4, k = 2
�����
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
ʾ�� 2��
���룺n = 1, k = 1
�����[[1]]
��ʾ��
1 <= n <= 20
1 <= k <= n
*/
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int n,int i,int k,vector<int>loc,vector<int>index,int last)
    {
        for(int j=i;j<n;j++)
        {
            if (index[j]||j<last) continue;//�����j�����Ѿ���ʹ�ã�����
            loc[i]=j;
            index[j]=1;
            if (i==k-1)//k�����Ѿ���������
            {
                vector<int> tmp(k);
                for(int x=0;x<k;x++) tmp[x]=loc[x]+1;
                ans.push_back(tmp);
            }
            else dfs(n,i+1,k,loc,index,j);
            index[j]=0;
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> loc(k),index(n);
        dfs(n,0,k,loc,index,0);
        return ans;
    }
};