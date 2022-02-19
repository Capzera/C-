/*
�������������������Ʊʱ�����䶳��
����һ����������prices�����е�prices[i]?��ʾ��?i?��Ĺ�Ʊ�۸� ��?
���һ���㷨����������������������Լ�������£�����Ծ����ܵ���ɸ���Ľ��ף��������һ֧��Ʊ��:
������Ʊ�����޷��ڵڶ��������Ʊ (���䶳��Ϊ 1 ��)��
ע�⣺�㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����
ʾ�� 1:
����: prices = [1,2,3,0,2]
���: 3 
����: ��Ӧ�Ľ���״̬Ϊ: [����, ����, �䶳��, ����, ����]
ʾ�� 2:
����: prices = [1]
���: 0
��ʾ��
1 <= prices.length <= 5000
0 <= prices[i] <= 1000
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),i;
        if (n==1) return 0;//���У����ֻ��1���ɣ�����Ϊ0
        vector<vector<int>> dp(n,vector<int>(2));
        dp[0][1]-=prices[0];//��0���ֹɣ�����prices[0]
        dp[1][0]=max(prices[1]-prices[0],0);
        dp[1][1]=max(0-prices[1],0-prices[0]);//��1���ֹ�
        for(i=2;i<n;i++)
        {
            dp[i][0]=max(dp[i-1][1]+prices[i],dp[i-1][0]);//��i�������Ƿ�����,�������䶳��
            dp[i][1]=max(dp[i-2][0]-prices[i],dp[i-1][1]);//�����䶳���ж�
        }
        return dp[n-1][0];
    }
};
//�Ż��ռ�
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),negative=0,positive=0-prices[0],prenegative=0,tmp;
        if (n==1) return 0;//���У����ֻ��1���ɣ�����Ϊ0
        if (n==2) return max(0,prices[1]-prices[0]);//������2����Ʊ�����
        for(int i=1;i<n;i++)
        {
            tmp=negative;
            negative=max(positive+prices[i],negative);//��i�������Ƿ�����,�������䶳��
            positive=max(prenegative-prices[i],positive);//�����䶳���ж�
            if (i>1)prenegative=tmp;
        }
        return negative;
    }
};