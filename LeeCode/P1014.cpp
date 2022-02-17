/*
��Ŀ������
����һ������������ values������ values[i]?��ʾ�� i ���۹⾰������֣�������������?i ��?j?֮��� ���� Ϊ?j - i��
һ�Ծ��㣨i < j����ɵĹ۹���ϵĵ÷�Ϊ values[i] + values[j] + i - j ��Ҳ���Ǿ��������֮�� ��ȥ ��������֮��ľ��롣
����һ�Թ۹⾰����ȡ�õ���߷֡�
ʾ�� 1��
���룺values = [8,1,5,2,6]
�����11
���ͣ�i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
ʾ�� 2��
���룺values = [1,2]
�����2

*/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size(),i,ans=values[0],sum,last=0;
        for(i=1;i<n;i++)
        {
            values[last]--;
            ans=max(values[last]+values[i],ans);
            if (values[i]>=values[last]) last=i;
        }
        return ans;
    }
};