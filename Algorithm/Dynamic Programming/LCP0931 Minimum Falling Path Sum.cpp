/*
����������P0931
����һ�� n x n �� ���� ��������?matrix �������ҳ�������ͨ�� matrix ���½�·�� �� ��С�� ��
�½�·�� ���Դӵ�һ���е��κ�Ԫ�ؿ�ʼ������ÿһ����ѡ��һ��Ԫ�ء�
����һ��ѡ���Ԫ�غ͵�ǰ����ѡԪ��������һ�У���λ�����·������ضԽ�������������ҵĵ�һ��Ԫ�أ���
������˵��λ�� (row, col) ����һ��Ԫ��Ӧ���� (row + 1, col - 1)��(row + 1, col) ���� (row + 1, col + 1) ��
ʾ�� 1��
���룺matrix = [[2,1,3],[6,5,4],[7,8,9]]
�����13
���ͣ���ͼ��ʾ��Ϊ����С�������½�·��
ʾ�� 2��
���룺matrix = [[-19,57],[-40,-5]]
�����-59
���ͣ���ͼ��ʾ��Ϊ����С���½�·��
��ʾ��
n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),ans=INT_MAX;
        if (n==1) return matrix[0][0];
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                int temp1=INT_MAX,temp2=INT_MAX;
                if (j>0) temp1=min(matrix[i][j]+matrix[i+1][j-1],matrix[i][j]+matrix[i+1][j]);
                if (j<n-1) temp2=min(matrix[i][j]+matrix[i+1][j],matrix[i][j]+matrix[i+1][j+1]);
                matrix[i][j]=min(temp1,temp2);
                if (!i) ans=min(ans,matrix[i][j]);
            }
        }
        return ans;
    }
};