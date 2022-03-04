/*
����������P1314
����һ��?m x n?�ľ���?mat?��һ������ k �����㷵��һ������?answer?��
����ÿ��?answer[i][j]?��������������������Ԫ��?mat[r][c] �ĺͣ�?
i - k <= r <= i + k,
j - k <= c <= j + k ��
(r, c)?�ھ����ڡ�
ʾ�� 1��
���룺mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
�����[[12,21,16],[27,45,33],[24,39,28]]
ʾ�� 2��
���룺mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
�����[[45,45,45],[45,45,45],[45,45,45]]
��ʾ��
m ==?mat.length
n ==?mat[i].length
1 <= m, n, k <= 100
1 <= mat[i][j] <= 100
*/
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size();;
        vector<vector<int>> sum(m+1,vector<int>(n+1)),ans(m,vector<int>(n));
        if (m>0)
        {
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    sum[i+1][j+1]=sum[i][j+1]+sum[i+1][j]-sum[i][j]+mat[i][j];//����ǰ׺��
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<mat[0].size();j++) 
            {
                int r1=i-k>0? i-k:0,r2=i+k<m? i+k:m-1,c1=j-k>0? j-k:0,c2=j+k<n? j+k:n-1;
                ans[i][j]=sum[r2+1][c2+1]-sum[r2+1][c1]-sum[r1][c2+1]+sum[r1][c1];//���������ʽ
            }
        }
        return ans;
    }
};