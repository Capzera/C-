/*
����������P0784
����һ���ַ���?s?��ͨ�����ַ���?s?�е�ÿ����ĸת���Сд�����ǿ��Ի��һ���µ��ַ�����
���� ���п��ܵõ����ַ������� ���� ����˳�� ���������
ʾ�� 1��
���룺s = "a1b2"
�����["a1b2", "a1B2", "A1b2", "A1B2"]
ʾ�� 2:
����: s = "3z4"
���: ["3z4","3Z4"]
��ʾ:
1 <= s.length <= 12
s?��СдӢ����ĸ����дӢ����ĸ���������
*/
class Solution {
public:
    vector<string> ans;
    vector<string> letterCasePermutation(string s) {
        for(int i=0;i<s.size();i++) if (s[i]>96&&s[i]<123) s[i]-=32;
        dfs(s,0);
        return ans;
    }
    void dfs(string &s,int i){
        while (i<s.size()&&s[i]>47&&s[i]<58) i++;
        if(i>=s.size()){
            ans.push_back(s);
            return;
        }
        s[i]+=32;
        dfs(s,i+1);
        s[i]-=32;
        dfs(s,i+1);
    }
};