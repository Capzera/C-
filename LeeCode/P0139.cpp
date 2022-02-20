/*
����������P0139
����һ���ַ��� s ��һ���ַ����б� wordDict ��Ϊ�ֵ䡣�����ж��Ƿ���������ֵ��г��ֵĵ���ƴ�ӳ� s ��
ע�⣺��Ҫ���ֵ��г��ֵĵ���ȫ����ʹ�ã������ֵ��еĵ��ʿ����ظ�ʹ�á�
ʾ�� 1��
����: s = "leetcode", wordDict = ["leet", "code"]
���: true
����: ���� true ��Ϊ "leetcode" ������ "leet" �� "code" ƴ�ӳɡ�
ʾ�� 2��
����: s = "applepenapple", wordDict = ["apple", "pen"]
���: true
����: ���� true ��Ϊ "applepenapple" ������ "apple" "pen" "apple" ƴ�ӳɡ�
?    ע�⣬������ظ�ʹ���ֵ��еĵ��ʡ�
ʾ�� 3��
����: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
���: false
��ʾ��
1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s �� wordDict[i] ����СдӢ����ĸ���
wordDict �е������ַ��� ������ͬ
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> um;
        int i,j,n=s.size();
        vector<bool> dp(n+1);
        dp[0]=1;
        for(i=0;i<wordDict.size();i++)um[wordDict[i]]++;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<i;j++)
            {
                if (dp[j]&&um.find(s.substr(j,i-j))!=um.end())
                {
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n];
    }
};