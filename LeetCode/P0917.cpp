/*
����������P0917
����һ���ַ��� s ��������������ת�ַ�����
���з�Ӣ����ĸ������ԭ��λ�á�
����Ӣ����ĸ��Сд���д��λ�÷�ת��
���ط�ת��� s ��
?
ʾ�� 1��
���룺s = "ab-cd"
�����"dc-ba"
ʾ�� 2��
���룺s = "a-bC-dEf-ghIj"
�����"j-Ih-gfE-dCba"
ʾ�� 3��
���룺s = "Test1ng-Leet=code-Q!"
�����"Qedo1ct-eeLg=ntse-T!"
?
��ʾ
1 <= s.length <= 100
s ���� ASCII ֵ�ڷ�Χ [33, 122] ���ַ����
s ���� '\"' �� '\\'
*/
class Solution {
public:
    bool isal(char c)
    {
        return (c>64&&c<91 || c>96&&c<123);
    }
    string reverseOnlyLetters(string s) {
        int i=0,j=s.size()-1;
        while (i<j)
        {
            if(isal(s[i])&&isal(s[j])) swap(s[i],s[j]);
            else if (isal(s[i])) i--;
            else if (isal(s[j])) j++;
            i++;j--;
        }
        return s;
    }
};