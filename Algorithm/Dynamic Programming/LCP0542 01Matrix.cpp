/*
����������P0542 01����
����һ���� 0 �� 1 ��ɵľ��� mat?�������һ����С��ͬ�ľ�������ÿһ�������� mat �ж�Ӧλ��Ԫ�ص������ 0 �ľ��롣
��������Ԫ�ؼ�ľ���Ϊ 1 ��
ʾ�� 1��
���룺mat = [[0,0,0],[0,1,0],[0,0,0]]
�����[[0,0,0],[0,1,0],[0,0,0]]
ʾ�� 2��
���룺mat = [[0,0,0],[0,1,0],[1,1,1]]
�����[[0,0,0],[0,1,0],[1,2,1]]
��ʾ��
m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
mat ��������һ�� 0?
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size(),i,j;
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            {
                if (!mat[i][j])continue;
                mat[i][j]=m+n;
                if (i>0) mat[i][j]=min(mat[i][j],mat[i-1][j]+1);//������
                if (j>0) mat[i][j]=min(mat[i][j],mat[i][j-1]+1);//����
            }
        for(i=m-1;i>=0;i--)//���α���
            for(j=n-1;j>=0;j--)
            {
                if (i<m-1) mat[i][j]=min(mat[i][j],mat[i+1][j]+1);//������
                if (j<n-1) mat[i][j]=min(mat[i][j],mat[i][j+1]+1);//����
            }
        return mat;
    }
};