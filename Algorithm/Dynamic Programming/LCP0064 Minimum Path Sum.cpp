/*
����������P0064
����һ�������Ǹ������� m?x?n?����?grid �����ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��
˵����ÿ��ֻ�����»��������ƶ�һ����
ʾ�� 1��
���룺grid = [[1,3,1],[1,5,1],[4,2,1]]
�����7
���ͣ���Ϊ·�� 1��3��1��1��1 ���ܺ���С��
ʾ�� 2��
���룺grid = [[1,2,3],[4,5,6]]
�����12
��ʾ��
m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp=grid;
        int m=grid.size(),n=grid[0].size();
        for(int i=1;i<n;i++) dp[0][i]+=dp[0][i-1];//�����һ��
        for(int i=1;i<m;i++) dp[i][0]+=dp[i-1][0];//�����һ��
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++) 
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+dp[i][j];//״̬ת�Ʒ���
        return dp[m-1][n-1];
    }
};