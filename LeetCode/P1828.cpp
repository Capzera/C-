/*
����������P1828
����һ������?points?������?points[i] = [xi, yi]?����ʾ��?i?�����ڶ�άƽ���ϵ����ꡣ�������ܻ��� ��ͬ?�����ꡣ
ͬʱ����һ������?queries?������?queries[j] = [xj, yj, rj]?����ʾһ��Բ����?(xj, yj)?�Ұ뾶Ϊ?rj?��Բ��
����ÿһ����ѯ?queries[j]?�������ڵ� j?��Բ ��?�����Ŀ�����һ������Բ�� �߽���?������ͬ����Ϊ����Բ?��?��
���㷵��һ������?answer?������?answer[j]�ǵ�?j?����ѯ�Ĵ𰸡�
ʾ�� 1��
���룺points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]
�����[3,2,2]
���ͣ����еĵ��Բ����ͼ��ʾ��
queries[0] ����ɫ��Բ��queries[1] �Ǻ�ɫ��Բ��queries[2] ����ɫ��Բ��
ʾ�� 2��
���룺points = [[1,1],[2,2],[3,3],[4,4],[5,5]], queries = [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]
�����[2,3,2,4]
���ͣ����еĵ��Բ����ͼ��ʾ��
queries[0] ����ɫ��Բ��queries[1] �Ǻ�ɫ��Բ��queries[2] ����ɫ��Բ��queries[3] ����ɫ��Բ��
��ʾ��
1 <= points.length <= 500
points[i].length == 2
0 <= x??????i, y??????i <= 500
1 <= queries.length <= 500
queries[j].length == 3
0 <= xj, yj <= 500
1 <= rj <= 500
���е����궼��������
*/
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n=points.size(),m=queries.size(),i,j;
        vector<int> ans(m);
        for(i=0;i<m;i++)
        {
            int cot=0;
            for (j=0;j<n;j++)
            {
                double dir=(queries[i][0]-points[j][0])*(queries[i][0]-points[j][0])+(queries[i][1]-points[j][1])*(queries[i][1]-points[j][1]);
                if (dir<=double(queries[i][2]*queries[i][2])) cot++;
            }
            ans[i]=cot;
        }
        return ans;
    }
};