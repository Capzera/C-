/*
����������P1065
����?�ַ��� text ��?�ַ����б� words, 
�������е������� [i, j] ʹ���������Է�Χ�ڵ����ַ��� text[i]...text[j]������?i?��?j�������ַ����б� words��
ʾ�� 1:
����: text = "thestoryofleetcodeandme", words = ["story","fleet","leetcode"]
���: [[3,7],[9,13],[10,17]]
ʾ�� 2:
����: text = "ababa", words = ["aba","ab"]
���: [[0,1],[0,2],[2,3],[2,4]]
����: 
ע�⣬���ص���Կ����н��棬���磬"aba" ���� [0,2] ��Ҳ�� [2,4] ��
��ʾ:
�����ַ�����ֻ����Сд��ĸ��
��֤ words �е��ַ������ظ���
1 <= text.length <= 100
1 <= words.length <= 20
1 <= words[i].length <= 50
���򷵻������� [i,j]���������������Եĵ�һ�������������򣬵���һ����������ͬʱ���յڶ������������򣩡�
*/
class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
		vector<vector<int>> ans;
        unordered_map<string,int> um;
        int maxlen=-1,minlen=INT_MAX,n=text.size();
        for (auto i=0;i<words.size();i++) {
			um[words[i]]++;
            int n=words[i].length();
            maxlen=max(maxlen,n);
            minlen=min(minlen,n);
		}
        for (int i=0;i<n;i++) {
			for (int j=minlen;j<=maxlen;j++) {
                if (i+j>n) break;
				if (um.count(text.substr(i,j))) ans.push_back({i,i+j-1});
			}
		}
        return ans;
    }
};