/*
����������P0074
��дһ����Ч���㷨���ж�?m x n?�����У��Ƿ����һ��Ŀ��ֵ���þ�������������ԣ�
ÿ���е����������Ұ��������С�
ÿ�еĵ�һ����������ǰһ�е����һ��������
ʾ�� 1��
���룺matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
�����true
ʾ�� 2��
���룺matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
�����false
��ʾ��
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if (!m) return false;
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            int l=0,r=n;
            if (matrix[i][r-1]<target) continue;
            while (l<r){
                int mid=l+(r-l)/2;
                if (matrix[i][mid]==target) return true;
                if (matrix[i][mid]>target) r=mid;
                else l=mid+1;
            }
        }
        return false;
    }
};