/*
����������
387. �ַ����еĵ�һ��Ψһ�ַ�
����һ���ַ��� s ���ҵ� ���ĵ�һ�����ظ����ַ����������������� ����������ڣ��򷵻� -1 ��
ʾ�� 1��
����: s = "leetcode"
���: 0
ʾ�� 2:
����: s = "loveleetcode"
���: 2
ʾ�� 3:
����: s = "aabb"
���: -1
*/
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> um;//�����������unordered_map�Ĵ洢��ʽΪFILO�ķ�ʽ����
        vector<int> ab(27);//����ÿ���ַ����ֵ�λ�ã����Ϊ��һ�γ��֣��򲻻ᱻ�����޸�
        int n=s.size(),i;
        for(i=n-1;i>=0;i--)//����ѭ�������ַ�ѹ���ϣ��
        {
            um[s[i]]++;
            ab[s[i]-96]=i;
        }
        for(auto& m:um) 
        {
            if (m.second==1) return ab[m.first-96];//�����ϣ����Ĵ���Ϊ1�ͷ��ع�ϣ�����Ԫ�ص�λ��
        }
        return -1;//ѭ��������Ȼδ�ҵ���˵��������ĸ���ִ���������1
    }
};