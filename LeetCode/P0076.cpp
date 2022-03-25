/*
����������P0076
����һ���ַ��� s ��һ���ַ��� t ������ s �к��� t �����ַ�����С�Ӵ���
��� s �в����ں��� t �����ַ����Ӵ����򷵻ؿ��ַ��� "" ��
ע�⣺
���� t ���ظ��ַ�������Ѱ�ҵ����ַ����и��ַ��������벻���� t �и��ַ�������
��� s �д����������Ӵ������Ǳ�֤����Ψһ�Ĵ𰸡�
ʾ�� 1��
���룺s = "ADOBECODEBANC", t = "ABC"
�����"BANC"
ʾ�� 2��
���룺s = "a", t = "a"
�����"a"
ʾ�� 3:
����: s = "a", t = "aa"
���: ""
����: t �������ַ� 'a' ��Ӧ������ s ���Ӵ��У�
���û�з������������ַ��������ؿ��ַ�����
��ʾ��
1 <= s.length, t.length <= 105
s �� t ��Ӣ����ĸ���
*/
class Solution {
public:
	unordered_map<char,int> um,win;
	bool check (){
		for (auto& p:um){
			if (win[p.first]<p.second) return false;
		}
		return true;
	}
    string minWindow(string s, string t) {

        int l=0,r=0,n=s.size(),minL=INT_MAX,L=-1;
        for (auto& i:t) um[i]++;
        while (r<n) {
			if(um.count(s[r])) win[s[r]]++;
            while(check()&&l<=r){
				if(r-l+1<minL){
					L=l;
                    minL=r-l+1;
				}
                if (um.find(s[l])!=um.end()) win[s[l]]--;
				l++;
            }
            r++;
		}
        return L<0? "":s.substr(L,minL);
    }
};