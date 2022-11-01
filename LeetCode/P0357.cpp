/*
����������P0357
����һ������ n ��ͳ�Ʋ����ظ�λ���ֶ���ͬ������ x �ĸ��������� 0 <= x < 10n?��
ʾ�� 1��
���룺n = 2
�����91
���ͣ���ӦΪ��ȥ 11��22��33��44��55��66��77��88��99 �⣬�� 0 �� x < 100 ��Χ�ڵ��������֡� 
ʾ�� 2��
���룺n = 0
�����1
��ʾ��
0 <= n <= 8
*/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (!n) return 1;
        if (n==1) return 10;
        int ans=10,cur=9;
        for (int i=2,last=9;i<=n;i++) {
           cur=last*(10-i+1);
           ans+=cur;
           last=cur;
        }
        return ans;
    }
};