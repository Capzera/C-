/*
����������P0119
����һ���Ǹ����� rowIndex�����ء�������ǡ��ĵ� rowIndex?�С�
�ڡ�������ǡ��У�ÿ�����������Ϸ������Ϸ������ĺ͡�
ʾ�� 1:
����: rowIndex = 3
���: [1,3,3,1]
ʾ�� 2:
����: rowIndex = 0
���: [1]
ʾ�� 3:
����: rowIndex = 1
���: [1,1]
��ʾ:
0 <= rowIndex <= 33
*/
//��̬�滮��ʱ�临�Ӷ�O(rowIndex^2)���ռ临�Ӷ�O(1)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp(rowIndex+1);
        dp[0]=1;
        for(int i=1;i<=rowIndex;i++)
        {
            dp[i]=1;
            for(int j=i-1;j>0;j--) dp[j]+=dp[j-1];
        }
        return dp;
    }
};
//��ѧ������ʱ�临�Ӷ�O(rowIndex)���ռ临�Ӷ�O(1)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp(rowIndex+1);
        dp[0]=1;
        if (!rowIndex) return dp;
        dp[rowIndex]=1;
        for(int i=1;i<=rowIndex/2;i++) dp[i]=dp[rowIndex-i]=1LL*dp[i-1]*(rowIndex-i+1)/i;
        return dp;
    }
};