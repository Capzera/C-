/*
����������P9999
�ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β����
�붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ�
���磬�����ַ���"abcdefg"������2���ú�������������ת��λ�õ��Ľ��"cdefgab"��
ʾ�� 1��
����: s = "abcdefg", k = 2
���:?"cdefgab"
ʾ�� 2��
����: s = "lrloseumgh", k = 6
���:?"umghlrlose"
���ƣ�
1 <= k < s.length <= 10000
*/
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string s1=s.substr(0,n),s2=s.substr(n,s.size()-n);
        return s2+s1;
    }
};