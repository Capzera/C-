/*
��Ŀ����
    ����һ���ַ��� s ��һ������ k�����ַ�����ͷ����ÿ������ 2k ���ַ����ͷ�ת�� 2k �ַ��е�ǰ k ���ַ���
    ���ʣ���ַ����� k ������ʣ���ַ�ȫ����ת�����ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ��������ַ�����ԭ����
ʾ�� 1��
���룺
    s = "abcdefg", k = 2
�����
    "bacdfeg"
ʾ�� 2��
���룺
    s = "abcd", k = 2
�����
    "bacd"
*/
class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.length();
        for (int i= 0;i<n;i+=2*k) {
            reverse(s.begin()+i,s.begin()+min(i+k,n));
        }
        return s;
    }
};