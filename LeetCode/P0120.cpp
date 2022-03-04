/*
����������P0120
����һ�������� triangle ���ҳ��Զ����µ���С·���͡�
ÿһ��ֻ���ƶ�����һ�������ڵĽ���ϡ�
���ڵĽ�� ������ָ���� �±� �� ��һ�����±� ��ͬ���ߵ��� ��һ�����±� + 1 ��������㡣Ҳ����˵��
�����λ�ڵ�ǰ�е��±� i ����ô��һ�������ƶ�����һ�е��±� i �� i + 1 ��
ʾ�� 1��
���룺triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
�����11
���ͣ��������ͼ��ʾ��
   2
  3 4
 6 5 7
4 1 8 3
�Զ����µ���С·����Ϊ?11������2?+?3?+?5?+?1?= 11����
ʾ�� 2��
���룺triangle = [[-10]]
�����-10
��ʾ��
1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
����:
�����ֻʹ�� O(n)?�Ķ���ռ䣨n Ϊ�����ε�����������������������
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size(),i,j;
        for(i=n-2;i>=0;i--)
        {
            for(j=0;j<=i;j++) triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
        }
        return triangle[0][0];
    }
};