/*
����������P0332
����һ���������� coins ����ʾ��ͬ����Ӳ�ң��Լ�һ������ amount ����ʾ�ܽ�
���㲢���ؿ��Դճ��ܽ������� ���ٵ�Ӳ�Ҹ��� �����û���κ�һ��Ӳ�����������ܽ�����?-1 ��
�������Ϊÿ��Ӳ�ҵ����������޵ġ�
ʾ��?1��
���룺coins = [1, 2, 5], amount = 11
�����3 
���ͣ�11 = 5 + 5 + 1
ʾ�� 2��
���룺coins = [2], amount = 3
�����-1
ʾ�� 3��
���룺coins = [1], amount = 0
�����0
��ʾ��
* 1 <= coins.length <= 12
* 1 <= coins[i] <= 231 - 1
* 0 <= amount <= 104
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (!amount) return 0;
        int n=coins.size();
        vector<int> dp(amount+1);
        sort(coins.begin(),coins.end());
        dp[0]=1;
        for(int i=1;i<=amount;i++)
        {
            dp[i]=INT_MAX;
            for (int j=0;j<n;j++)
            {
                if (coins[j]>i) break;
                if (!dp[i-coins[j]]) continue;
                if (i==coins[j]) dp[i]=1;
                else dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
            if (dp[i]==INT_MAX) dp[i]=0;
        }
        return dp[amount]? dp[amount]:-1;
    }
};