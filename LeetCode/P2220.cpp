/*
����������P2220 ���۵�75��˫����
һ�� λ��ת?����Ϊ������?x?�������е�һ��λ���� ��ת?����������?0?���?1?�����߽�?1?���?0?��
�ȷ�˵��x = 7?�������Ʊ�ʾΪ?111?�����ǿ���ѡ������һ��λ������û����ʾ��ǰ�� 0 �������з�ת��
�ȷ�˵���ǿ��Է�ת���ұ�һλ�õ�?110?�����߷�ת�ұ���ڶ�λ�õ�?101?��
���߷�ת�ұ������λ����һλ��ǰ�� 0 ���õ�?10111?�ȵȡ�
������������?start ��?goal?�����㷵�ؽ�?start?ת���?goal?��?����λ��ת?������
ʾ�� 1��
���룺start = 10, goal = 7
�����3
���ͣ�10 �� 7 �Ķ����Ʊ�ʾ�ֱ�Ϊ 1010 �� 0111 �����ǿ���ͨ�� 3 ���� 10 ת��� 7 ��
- ��ת�ұ����һλ�õ���1010 -> 1011 ��
- ��ת�ұ������λ��1011 -> 1111 ��
- ��ת�ұ������λ��1111 -> 0111 ��
�����޷��� 3 ���ڽ� 10 ת��� 7 ���������Ƿ��� 3 ��
ʾ�� 2��
���룺start = 3, goal = 4
�����3
���ͣ�3 �� 4 �Ķ����Ʊ�ʾ�ֱ�Ϊ 011 �� 100 �����ǿ���ͨ�� 3 ���� 3 ת��� 4 ��
- ��ת�ұ����һλ��011 -> 010 ��
- ��ת�ұ���ڶ�λ��010 -> 000 ��
- ��ת�ұ������λ��000 -> 100 ��
�����޷��� 3 ���ڽ� 3 ��� 4 ���������Ƿ��� 3 ��
��ʾ��
0 <= start, goal <= 109
*/
class Solution {
public:
    int minBitFlips(int start, int goal) {
        string s1="",s2="";
        int ans=0;
        while (start) {
            s1+=to_string(start%2);
            start/=2;
        }
        while (goal) {
            s2+=to_string(goal%2);
            goal/=2;
        }
        int len1=s1.size(),len2=s2.size();
        if (len1<len2){
            swap(s1,s2);
            swap(len1,len2);
        }
        if (len2<len1){
            for (int i=0;i<len1-len2;i++) s2+='0';
        }
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        for (int i=0;i<len1;i++) {
            if (s1[i]!=s2[i]) ans++;
        }
        return ans;
    }
};