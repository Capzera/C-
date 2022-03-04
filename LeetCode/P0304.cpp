/*
����������P0304
����һ����ά���� matrix���������͵Ķ������
�������Ӿ��η�Χ��Ԫ�ص��ܺͣ����Ӿ���� ���Ͻ� Ϊ (row1,?col1) �����½� Ϊ (row2,?col2) ��
ʵ�� NumMatrix �ࣺ
NumMatrix(int[][] matrix)?������������ matrix ���г�ʼ��
int sumRegion(int row1, int col1, int row2, int col2)?
���� ���Ͻ� (row1,?col1)?�����½�?(row2,?col2) ���������Ӿ����Ԫ�� �ܺ� ��
ʾ�� 1��
����: 
["NumMatrix","sumRegion","sumRegion","sumRegion"]
[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]
���: 
[null, 8, 11, 12]
����:
NumMatrix numMatrix = new NumMatrix([[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (��ɫ���ο��Ԫ���ܺ�)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (��ɫ���ο��Ԫ���ܺ�)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (��ɫ���ο��Ԫ���ܺ�)
��ʾ��
m == matrix.length
n == matrix[i].length
1 <= m,?n <=?200
-105?<= matrix[i][j] <= 105
0 <= row1 <= row2 < m
0 <= col1 <= col2 < n
������ 104 ��?sumRegion ����
*/
class NumMatrix {
public:
    vector<vector<int>> sums;
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if (m>0)
        {
            int n=matrix[0].size();
            sums.resize(m+1,vector<int>(n+1));
            for (int i=0;i<m;i++) 
            {
                for (int j=0;j<n;j++) 
                    sums[i+1][j+1]=sums[i][j+1]+sums[i+1][j]-sums[i][j]+matrix[i][j];
            }
        }
    }
    int sumRegion(int row1,int col1,int row2,int col2) {
        return sums[row2+1][col2+1]-sums[row1][col2+1]-sums[row2+1][col1]+sums[row1][col1];
    }
};
