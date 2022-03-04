/*
����������
���������ַ���?s1?��?s2 ��дһ���������ж� s2 �Ƿ���� s1?�����С�����ǣ����� true �����򣬷��� false ��
���仰˵��s1 ������֮һ�� s2 �� �Ӵ� ��
ʾ�� 1��
���룺s1 = "ab" s2 = "eidbaooo"
�����true
���ͣ�s2 ���� s1 ������֮һ ("ba").
ʾ�� 2��
���룺s1= "ab" s2 = "eidboaoo"
�����false
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> um;
        int n1=s1.size(),n=s2.size(),i;
        if (n1>n) return false;//����,s1��s2����һ����ƥ��
        for(i=0;i<n1;i++) um[s1[i]]++;//����s1��ϣ��
        i=0;//��ʼ��ָ��
        unordered_map<char,int> compare;//������������
        for(i=0;i<n1;i++) compare[s2[i]]++;//��s2��ǰn1���ַ�ѹ�봰��
        for(i=n1;i<n;i++)//��ʼ����
        {
            if (compare==um) return true;//���������Ԫ�ص��ڹ�ϣ��ƥ��ɹ�
            compare[s2[i]]++;//��������ѹ��һ��Ԫ��
            if (compare[s2[i-n1]]>1) compare[s2[i-n1]]--;//�����Ҫ�ͷŵ�Ԫ�ظ�������1������-1
            else compare.erase(s2[i-n1]);//���ͷ�Ԫ�ؽ���һ��������Ӵ��ڲ���
        }
        return compare==um;
    }
};