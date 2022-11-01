/*
����������
����һ����������?prices������ prices[i]��ʾ��?i?��Ĺ�Ʊ�۸� ������?fee �����˽��׹�Ʊ���������á�
��������޴ε���ɽ��ף�������ÿ�ʽ��׶���Ҫ�������ѡ�������Ѿ�������һ����Ʊ����������֮ǰ��Ͳ����ټ��������Ʊ�ˡ�
���ػ����������ֵ��
ע�⣺�����һ�ʽ���ָ������в�������Ʊ���������̣�ÿ�ʽ�����ֻ��ҪΪ֧��һ�������ѡ�
ʾ�� 1��
���룺prices = [1, 3, 2, 8, 4, 9], fee = 2
�����8
���ͣ��ܹ��ﵽ���������:  
�ڴ˴�����?prices[0] = 1
�ڴ˴����� prices[3] = 8
�ڴ˴����� prices[4] = 4
�ڴ˴����� prices[5] = 9
������:?((8 - 1) - 2) + ((9 - 4) - 2) = 8
ʾ�� 2��
���룺prices = [1,3,7,5,10,3], fee = 3
�����6
��ʾ��
1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104
*/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size(),i;
        vector<vector<int>> dp(n,vector<int>(2));//[i][0]��ʾ��i�����ֹ�,[i][1]��ʾ��i���ֹ�
        dp[0][1]-=prices[0]+fee;
        for(i=1;i<n;i++)
        {
            dp[i][0]=max(dp[i-1][1]+prices[i],dp[i-1][0]);//dp[i][0]=dp[i-1][1]��i��������dp[i-1][0]�����ֵ
            dp[i][1]=max(dp[i-1][0]-prices[i]-fee,dp[i-1][1]);//dp[i][1]=dp[i-1][1]��i�������dp[i-1][1]�����ֵ
        }
        return dp[n-1][0];
    }
};
//����iֻ��i-1�йأ��Ż��ռ�
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size(),negative=0,positive=0-prices[0]-fee;
        for(int i=1;i<n;i++)
        {
            negative=max(positive+prices[i],negative);
            positive=max(negative-prices[i]-fee,positive);
        }
        return negative;
    }
};