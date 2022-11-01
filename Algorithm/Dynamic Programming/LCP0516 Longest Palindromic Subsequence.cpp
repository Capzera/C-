/*
����������P0516
����һ���ַ��� s ���ҳ�������Ļ��������У������ظ����еĳ��ȡ�
�����ж���Ϊ�����ı�ʣ���ַ�˳�������£�ɾ��ĳЩ�ַ����߲�ɾ���κ��ַ��γɵ�һ�����С�
ʾ�� 1��
���룺s = "bbbab"
�����4
���ͣ�һ�����ܵ������������Ϊ "bbbb" ��
ʾ�� 2��
���룺s = "cbbd"
�����2
���ͣ�һ�����ܵ������������Ϊ "bb" ��
��ʾ��
1 <= s.length <= 1000
s ����СдӢ����ĸ���
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=n-1;i>=0;i--)
        {
            dp[i][i]=1;
            for(int j=i+1;j<n;j++)
            {
                if (s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+2;
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};