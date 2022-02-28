/*
����������P0063
һ��������λ��һ��?m x n?��������Ͻ� ����ʼ������ͼ�б��Ϊ ��Start�� ����
������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ ��Finish������
���ڿ������������ϰ����ô�����Ͻǵ����½ǽ����ж�������ͬ��·����
�����е��ϰ���Ϳ�λ�÷ֱ��� 1 �� 0 ����ʾ��
ʾ�� 1��
���룺obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
�����2
���ͣ�3x3 ��������м���һ���ϰ��
�����Ͻǵ����½�һ���� 2 ����ͬ��·����
1. ���� -> ���� -> ���� -> ����
2. ���� -> ���� -> ���� -> ����
ʾ�� 2��
���룺obstacleGrid = [[0,1],[0,0]]
�����1
��ʾ��
m ==?obstacleGrid.length
n ==?obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] Ϊ 0 �� 1
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size(),i,j;
        vector<vector<int>> dp(m,vector<int>(n));
        for(i=0;i<m;i++) 
        {
            if (!obstacleGrid[i][0]) dp[i][0]=1;
            else break;
        }
        for(j=0;j<n;j++)
        {
            if (!obstacleGrid[0][j]) dp[0][j]=1;
            else break;
        }
        for(i=1;i<m;i++)
        {
            for(j=1;j<n;j++)
            {
                if (obstacleGrid[i][j]) continue;
                if (!obstacleGrid[i-1][j]) dp[i][j]+=dp[i-1][j];
                if (!obstacleGrid[i][j-1]) dp[i][j]+=dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};