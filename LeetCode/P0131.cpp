/*
����������P0131
����һ���ַ��� s�����㽫 s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����� ���Ĵ� ������ s ���п��ܵķָ����
���Ĵ� �����Ŷ��ͷ��Ŷ���һ�����ַ�����
ʾ�� 1��
���룺s = "aab"
�����[["a","a","b"],["aa","b"]]
ʾ�� 2��
���룺s = "a"
�����[["a"]]
��ʾ��
1 <= s.length <= 16
s ����СдӢ����ĸ���
*/
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> tmp;
    string s;
    int n;
    static bool check(string s){
		int n=s.length();
        if (n==0) return true;
        string tmp=s.substr(n/2+n%2,n);
    	reverse(tmp.begin(),tmp.end());
        return s.substr(0,n/2)==tmp;
    
	}
    void dfs(int i,vector<string> tmp){
		if (i==n){
			ans.push_back(tmp);
            return;
		}
        for (int j=1;j<=n-i;j++){
			if(check(s.substr(i,j))==0) continue;
            tmp.push_back(s.substr(i,j));
            dfs(i+j,tmp);
            tmp.pop_back();
		}
	}
    vector<vector<string>> partition(string s) {
		this->n=s.length();
        this->s=s;
        dfs(0,tmp);
        return ans;
    }
};