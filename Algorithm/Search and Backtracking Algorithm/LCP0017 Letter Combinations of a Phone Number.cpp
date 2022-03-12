/*
����������P0017
����һ������������?2-9?���ַ����������������ܱ�ʾ����ĸ��ϡ��𰸿��԰� ����˳�� ���ء�
�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��
ʾ�� 1��
���룺digits = "23"
�����["ad","ae","af","bd","be","bf","cd","ce","cf"]
ʾ�� 2��
���룺digits = ""
�����[]
ʾ�� 3��
���룺digits = "2"
�����["a","b","c"]
��ʾ��
0 <= digits.length <= 4
digits[i] �Ƿ�Χ ['2', '9'] ��һ�����֡�
*/
class Solution {
public:
    string digit;
    vector<string> db={
        {"abc"},
        {"def"},
        {"ghi"},
        {"jkl"},
        {"mno"},
        {"pqrs"},
        {"tuv"},
        {"wxyz"}
    };
    vector<string> ans;
    int n;
    void dfs(int i,string tmp)
    {
        if (i==n)
        {
            if (tmp.size())ans.push_back(tmp);
            return;
        }
        int num=digit[i]-50;
        for(int j=0;j<db[num].size();j++)
        {
            dfs(i+1,tmp+db[num][j]);
        }
    }
    vector<string> letterCombinations(string digits) {
        this->n=digits.size();
        this->digit=digits;
        dfs(0,"");
        return ans;
    }
};