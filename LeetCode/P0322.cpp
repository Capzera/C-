/*
����������P0322
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
1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for (auto& coin:coins){
			for (int j=coin;j<=amount;j++)
                if (dp[j-coin]!=INT_MAX) dp[j]=min(dp[j],dp[j-coin]+1);
		}
        return dp[amount]==INT_MAX? -1:dp[amount];
    }
};