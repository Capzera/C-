/*
����������P0518
����һ���������� coins ��ʾ��ͬ����Ӳ�ң�����һ������ amount ��ʾ�ܽ�
������㲢���ؿ��Դճ��ܽ���Ӳ�������������κ�Ӳ����϶��޷��ճ��ܽ����� 0 ��
����ÿһ������Ӳ�������޸���?
��Ŀ���ݱ�֤������� 32 λ������������
ʾ�� 1��
���룺amount = 5, coins = [1, 2, 5]
�����4
���ͣ������ַ�ʽ���Դճ��ܽ�
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
ʾ�� 2��
���룺amount = 3, coins = [2]
�����0
���ͣ�ֻ����� 2 ��Ӳ�Ҳ��ܴճ��ܽ�� 3 ��
ʾ�� 3��
���룺amount = 10, coins = [10] 
�����1
��ʾ��
1 <= coins.length <= 300
1 <= coins[i] <= 5000
coins �е�����ֵ ������ͬ
0 <= amount <= 5000
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<int> dp(amount+1);
        dp[0]=1;
        for(int j=0;j<n;j++)
        {
            for(int i=coins[j];i<=amount;i++)
            {
				dp[i]+=dp[i-coins[j]];
            }
        }
        return dp[amount];
    }
};