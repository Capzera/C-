/*
����������P0005
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ���
ʾ�� 1��
���룺s = "babad"
�����"bab"
���ͣ�"aba" ͬ���Ƿ�������Ĵ𰸡�
ʾ�� 2��
���룺s = "cbbd"
�����"bb"
��ʾ��
1 <= s.length <= 1000
s �������ֺ�Ӣ����ĸ���
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(),i,j,maxlen=1;
        if (n<2) return s;
        string ans="";
        ans+=s[0];
        for(int L=1;L<3;L++)//L���Ƴ�ʼ������
            for(i=0;i<n-L+1;i++)//iΪ���Ĵ��ĳ�ʼ����
            {
                if (L==2&&s[i]!=s[i+1]) continue;//���Ĵ�������2��ʼ�����뱣֤���������
                for (j=0;j<n/2+1;j++)//j���ƻ��Ĵ�����չ����
                {
                    int l=i-j,r=i+j+L-1;
                    if (l<0||r>=n||s[l]!=s[r]) break;//Խ�硢�������˳�
                    if (r-l+1>maxlen)
                    {
                        maxlen=r-l+1;//������󳤶�
                        ans=s.substr(l,r-l+1);//��ȡ��
                    }
                }
            }
        return ans;
    }
};