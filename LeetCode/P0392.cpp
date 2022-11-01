/*
����������P0392
�����ַ��� s �� t ���ж� s �Ƿ�Ϊ t �������С�
�ַ�����һ����������ԭʼ�ַ���ɾ��һЩ��Ҳ���Բ�ɾ�����ַ������ı�ʣ���ַ����λ���γɵ����ַ�����
�����磬"ace"��"abcde"��һ�������У���"aec"���ǣ���
���ף�
����д�������� S������ S1, S2, ... , Sk ���� k >= 10�ڣ�����Ҫ���μ�������Ƿ�Ϊ T �������С�����������£���������ı���룿
��л��
�ر��л @pbrother?��Ӵ����Ⲣ�Ҵ������в���������
ʾ�� 1��
���룺s = "abc", t = "ahbgdc"
�����true
ʾ�� 2��
���룺s = "axc", t = "ahbgdc"
�����false
��ʾ��
0 <= s.length <= 100
0 <= t.length <= 10^4
�����ַ�����ֻ��Сд�ַ���ɡ�
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.size(),n=t.size(),i;
        if (m>n) return 0;
        vector<vector<int>> dp(n+1,vector<int>(26));
        for(int i=0;i<26;i++) dp[n][i]=n;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<26;j++)
            {
                if (t[i]==j+'a') dp[i][j]=i;//t��i��ʼ����j�ַ�Ϊi
                else dp[i][j]=dp[i+1][j];
            }
        }
        int add=0;
        for (int i=0;i<m;i++) {
            if (dp[add][s[i]-'a']==n) return false;//�����ǰ��ѯ���ַ���t�в�ƥ��
            add=dp[add][s[i]-'a']+1;
        }
        return true;
    }
};