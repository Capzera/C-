/*
����������������ַ���
��һ���ַ��� s?������ÿһ����ĸ�Ĵ�д��Сд��ʽ ͬʱ?������ s?�У��ͳ�����ַ���?s?�� ���� �ַ�����
�ȷ�˵��"abABB"?�������ַ�������Ϊ?'A' ��?'a'?ͬʱ�����ˣ���?'B' ��?'b'?Ҳͬʱ�����ˡ�
Ȼ����"abA"?���������ַ�����Ϊ?'b'?�����ˣ���?'B'?û�г��֡�
����һ���ַ���?s?�����㷵��?s?���?�������ַ���?������ж���𰸣����㷵��?����?���ֵ�һ����
����������������ַ��������㷵��һ�����ַ�����
ʾ�� 1��
���룺s = "YazaAay"
�����"aAa"
���ͣ�"aAa" ��һ�������ַ�������Ϊ����Ӵ��н���һ����ĸ����Сд��ʽ 'a' �ʹ�д��ʽ 'A' Ҳͬʱ�����ˡ�
"aAa" ������������ַ�����
ʾ�� 2��
���룺s = "Bb"
�����"Bb"
���ͣ�"Bb" �������ַ�������Ϊ 'B' �� 'b' �������ˡ������ַ���Ҳ��ԭ�ַ��������ַ�����
ʾ�� 3��
���룺s = "c"
�����""
���ͣ�û���������ַ�����
ʾ�� 4��
���룺s = "dDzeE"
�����"dD"
���ͣ�"dD" �� "eE" ������������ַ�����
�����ж���������ַ��������� "dD" ����Ϊ�����ֵ����硣
��ʾ��
1 <= s.length <= 100
s?ֻ������д��СдӢ����ĸ��
*/
class Solution {
public:
    bool isnice(unordered_map<char,int> um)
    {
        for(auto m=um.begin();m!=um.end();m++)
        {
            if (m->first<91&&um.find(m->first+32)==um.end()) return false;//��ǰΪ��д��ĸ
            if (m->first>96&&um.find(m->first-32)==um.end()) return false;//��ǰΪСд��ĸ
        }
        return true;
    }
    string longestNiceSubstring(string s) {
        int n=s.size(),i;
        string ans="";
        if (n==1) return ans;//ֻ��1����ĸ�϶�������
        for(int x=n;x>=2;x--)//xΪ���ڴ�С
        {
            unordered_map<char,int> um;
            for (i=0;i<x;i++) um[s[i]]++;//��ʼ������
            if (isnice(um))//��ʼ���ڼ�����
            {
                for(i=0;i<x;i++) ans+=s[i];
                return ans;
            }
            for (i=x;i<n;i++)//��ʼ����
            {
                um[s[i]]++;
                if (um[s[i-x]]>1) um[s[i-x]]--;
                else um.erase(s[i-x]);//���ڸ���
                if (isnice(um))//��ǰ���ڼ�����
                {
                    for(int j=i-x+1;j<=i;j++) ans+=s[j];//��Ϊ��ǰ����
                    return ans;
                } 
            }
        }
        return ans;
    }
};