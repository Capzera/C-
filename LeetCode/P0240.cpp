/*
����������P0004
��һ�� n * m �Ķ�ά�����У�ÿһ�ж����մ����ҵ�����˳������
ÿһ�ж����մ��ϵ��µ�����˳�����������һ����Ч�ĺ���������������һ����ά�����һ���������ж��������Ƿ��и�������
ʾ��:
���о��� matrix ���£�
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
���� target?=?5������?true��
����?target?=?20������?false��
���ƣ�
0 <= n <= 1000
0 <= m <= 1000
*/
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if (!m) return false;
        int n=matrix[0].size();
        if (!n) return false;
        for(int i=0;i<m;i++){
            int l=0,r=n;
            while (l<r){
                int mid=l+(r-l)/2;
                if (matrix[i][mid]==target) return true;
                if (matrix[i][mid]<target) l=mid+1;
                else r=mid;
            }
        }
        return false;
    }
};