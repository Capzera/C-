/*
���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ����ĸ��λ�ʡ�
ע�⣺��?s �� t?��ÿ���ַ����ֵĴ�������ͬ�����?s �� t?��Ϊ��ĸ��λ�ʡ�
ʾ��?1:
����: s = "anagram", t = "nagaram"
���: true
ʾ�� 2:
����: s = "rat", t = "car"
���: false
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m1,m2;
        if (s.size()!=t.size()) return false;
        int i,n=s.size();
        for(i=0;i<n;i++)
        {
            m1[s[i]]++;//��¼s�ַ�����ĸ�Ĺ�ϣ��
            m2[t[i]]++;//��¼t�ַ�����ĸ�Ĺ�ϣ��
        }
        for(i=97;i<=122;i++)
        {
            if (m1[i]!=m2[i]) return false;//��ϣ��ͬ
        }
        return true;
    }
};