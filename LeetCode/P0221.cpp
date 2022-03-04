/*
����������P0221
��һ���� '0' �� '1' ��ɵĶ�ά�����ڣ��ҵ�ֻ���� '1' ����������Σ��������������
ʾ�� 1��
���룺matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
�����4
ʾ�� 2��
���룺matrix = [["0","1"],["1","0"]]
�����1
ʾ�� 3��
���룺matrix = [["0"]]
�����0
��ʾ��
m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] Ϊ '0' �� '1'
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),ans=-1;
        vector<vector<int>> dp(m,vector<int>(n));
        if (!m||!n) return 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if (matrix[i][j]=='1')
                {
                    if (!i||!j) dp[i][j]=1;
                    else dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};