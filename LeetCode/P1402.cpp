/*
����������P1402
һ����ʦ�ռ�����?n?���˵�����̶�?satisfaction?�������ʦ����ÿ���˵�ʱ�䶼�� 1 ��λʱ�䡣
һ���˵� ��ϲ��ʱ�䡹ϵ������Ϊ���������Լ�֮ǰÿ���������ѵ�ʱ���������˵�����̶ȣ�Ҳ����?time[i]*satisfaction[i]?��
���㷵���������в� ��ϲ��ʱ�䡹�ܺ͵����ֵΪ���١�
����԰�?����?˳�������˵�˳����Ҳ����ѡ�������ĳЩ������ø�����ܺ͡�
ʾ�� 1��
���룺satisfaction = [-1,-8,0,5,-9]
�����14
���ͣ�ȥ���ڶ��������һ���ˣ�����ϲ��ʱ��ϵ����Ϊ (-1*1 + 0*2 + 5*3 = 14) ��ÿ���˶���Ҫ���� 1 ��λʱ����ɡ�
ʾ�� 2��
���룺satisfaction = [4,3,2]
�����20
���ͣ�����ԭ��˳���෴��ʱ������ (2*1 + 3*2 + 4*3 = 20)
ʾ�� 3��
���룺satisfaction = [-1,-4,-5]
�����0
���ͣ���Ҷ���ϲ����Щ�ˣ����Բ����κβ˿��Ի������ϲ��ʱ��ϵ����
ʾ�� 4��
���룺satisfaction = [-2,5,-1,0,3,-3]
�����35
��ʾ��
n == satisfaction.length
1 <= n <= 500
-10^3 <=?satisfaction[i] <= 10^3
*/
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size(),i,ans=0;
        vector<int> dp(n);
        sort(satisfaction.begin(),satisfaction.end());
        for(i=0;i<n;i++)
        {
            int temp=0;
            for(int j=i;j<n;j++) temp+=(j-i+1)*satisfaction[j];
            if (temp>0&&temp<ans) break;
            else ans=max(ans,temp);
        }
        return ans;
    }
};