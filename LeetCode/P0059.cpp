/*
����������P0059
����һ��������?n ������һ������ 1 ��?n2?����Ԫ�أ���Ԫ�ذ�˳ʱ��˳���������е�?n x n �����ξ��� matrix 
ʾ�� 1��
���룺n = 3
�����[[1,2,3],[8,9,4],[7,6,5]]
ʾ�� 2��
���룺n = 1
�����[[1]]
��ʾ��
1 <= n <= 20
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i = 0, j = 0, cnt = 1, direct = 0;
        int U, D, L, R;
        U = L = -1;
        D = R = n;
        vector<vector<int> > matrix(n, vector<int> (n));
        while (cnt <= n * n) {
            matrix[i][j] = cnt++;
            if (direct == 0) {
                j++;
                if (j == R) {
                    j = R - 1;
                    U++;
                    direct = 1;
                }
            }
            if (direct == 1) {
                i++;
                if (i == D) {
                    i = D - 1;
                    R--;
                    direct = 2;
                }
            }
            if (direct == 2) {
                j--;
                if (j == L) {
                    j = L + 1;
                    D--;
                    direct = 3;
                }
            }
            if (direct == 3) {
                i--;
                if (i == U) {
                    i = U + 1;
                    j++;
                    L++;
                    direct = 0;
                }
            }
        }
        return matrix;
    }
};