/*
����������P0097
���������ַ���?s1��s2��s3�������æ��֤?s3?�Ƿ�����?s1?��?s2 ���� ��ɵġ�
�����ַ��� s �� t ���� �Ķ�����������£�����ÿ���ַ������ᱻ�ָ������ �ǿ� ���ַ�����
s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
���� �� s1 + t1 + s2 + t2 + s3 + t3 + ... ���� t1 + s1 + t2 + s2 + t3 + s3 + ...
ע�⣺a + b ��ζ���ַ��� a �� b ���ӡ�
ʾ�� 1��
���룺s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
�����true
ʾ�� 2��
���룺s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
�����false
ʾ�� 3��
���룺s1 = "", s2 = "", s3 = ""
�����true
��ʾ��
0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1��s2���� s3 ����СдӢ����ĸ���
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		int l1=s1.size(),l2=s2.size(),l3=s3.size(),i=0,j=0;
        if ((l1+l2)!=l3) return false;
        vector<vector<bool>> dp(l1+1,vector<bool>(l2+1));
        dp[0][0]=1;
        while (i<l1&&s1[i]==s3[i]) dp[++i][0]=1;
        while (j<l2&&s2[j]==s3[j]) dp[0][++j]=1;
        for (i=1;i<=l1;i++){
			for(j=1;j<=l2;j++){
            	dp[i][j]=(dp[i][j-1]&&s2[j-1]==s3[i+j-1])||(dp[i-1][j]&&s1[i-1]==s3[i+j-1]);    
            }
		}
        return dp[l1][l2];
    }
};
/*
dp[i][j]=s1 i���ַ� s2j���ַ��ܷ����s3ǰi+j���ַ�
dp[1][3]=0
dp[1][4]=0
dp[2][3]=1

*/