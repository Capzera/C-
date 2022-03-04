/*
����������P0264
����һ������ n �������ҳ������ص� n �� ���� ��
���� ����ֻ����������?2��3 ��/��?5?����������
ʾ�� 1��
���룺n = 10
�����12
���ͣ�[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] ����ǰ 10 ��������ɵ����С�
ʾ�� 2��
���룺n = 1
�����1
���ͣ�1 ͨ������Ϊ������
��ʾ��
1 <= n <= 1690
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        int i,p2,p3,p5;
        p2=p3=p5=0;
        dp[0]=1;
        for(i=1;i<n;i++)
        {
            int num2=dp[p2]*2,num3=dp[p3]*3,num5=dp[p5]*5;
            dp[i]=(min(min(num2,num3),num5));
            if (dp[i]==num2) p2++;
            if (dp[i]==num3) p3++;
            if (dp[i]==num5) p5++;
        }
        return dp[n-1];
    }
};