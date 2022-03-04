/*
问题描述：P0343
给定一个正整数?n?，将其拆分为 k 个 正整数 的和（?k >= 2?），并使这些整数的乘积最大化。
返回 你可以获得的最大乘积?。
示例 1:
输入: n = 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
示例?2:
输入: n = 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 ×?3 ×?4 = 36。
提示:
2 <= n <= 58
*/
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        for (int i=2;i<=n;i++)
        {
            int curMax=0;
            for (int j=1;j<i;j++)
            {
                curMax=max(curMax,j*max(i-j,dp[i-j]));
            }
            dp[i]=curMax;
        }
        return dp[n];
    }
};