/*
����������P2100
���һȺǿ��׼��������С�����һ���±�� 0?��ʼ����������?security?������?security[i]?�ǵ� i?��ִ�ھ�����������
���Ӵ� 0?��ʼ��š�ͬʱ����һ������?time?��
����� i?�����������������������ǳ���Ϊһ���ʺϴ�����е����ӣ�
�� i?��ǰ�ͺ󶼷ֱ������� time?�졣
�� i?��ǰ���� time?�쾯����Ŀ���Ƿǵ����ġ�
�� i?������� time?�쾯����Ŀ���Ƿǵݼ��ġ�
����ʽ�ģ��� i ����һ�����ʴ�����е����ӵ��ҽ�����
security[i - time] >= security[i - time + 1] >= ... >= security[i] <= ... <= security[i + time - 1] <= security[i + time].
���㷵��һ�����飬���� ���� �ʺϴ�����е����ӣ��±�� 0?��ʼ�������ص����ӿ��� ����?˳�����С�
ʾ�� 1��
���룺security = [5,3,3,3,5,6,2], time = 2
�����[2,3]
���ͣ�
�� 2 �죬������ security[0] >= security[1] >= security[2] <= security[3] <= security[4] ��
�� 3 �죬������ security[1] >= security[2] >= security[3] <= security[4] <= security[5] ��
û���������ӷ�������������������� 2 �� 3 ���ʺϴ�����е����ӡ�
ʾ�� 2��
���룺security = [1,1,1,1,1], time = 0
�����[0,1,2,3,4]
���ͣ�
��Ϊ time ���� 0 ������ÿһ�춼���ʺϴ�����е����ӣ����Է���ÿһ�졣
ʾ�� 3��
���룺security = [1,2,3,4,5,6], time = 2
�����[]
���ͣ�
û���κ�һ���ǰ 2 �쾯����Ŀ�Ƿǵ����ġ�
����û���ʺϴ�����е����ӣ����ؿ����顣
ʾ�� 4��
���룺security = [1], time = 5
�����[]
���ͣ�
û������ǰ��ͺ����� 5 ��ʱ�䡣
����û���ʺϴ�����е����ӣ����ؿ����顣
��ʾ��
1 <= security.length <= 105
0 <= security[i], time <= 105
*/
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        vector<int> ans,up(n),down(n);
        for (int i=1;i<n;i++)
        {
            if (security[i]>security[i-1]) up[i]=up[i-1]+1;//up������������������
            else if(security[i]<security[i-1]) down[i]=down[i-1]+1;//down���������½�������
            else
            {
                up[i]=up[i-1]+1;
                down[i]=down[i-1]+1;
            }
        }
        for(int i=time;i<n-time;i++) if (down[i]-down[i-time]==time&&up[time+i]-up[i]==time) ans.push_back(i);//i��������
        return ans;
    }
};