/*
����������P0796
���������ַ���, s?��?goal����������ɴ���ת����֮��s?�ܱ��?goal?����ô����?true?��
s?�� ��ת���� ���ǽ�?s ����ߵ��ַ��ƶ������ұߡ�?
����, ��?s = 'abcde'������תһ��֮��������'bcdea'?��
ʾ�� 1:
����: s = "abcde", goal = "cdeab"
���: true
ʾ�� 2:
����: s = "abcde", goal = "abced"
���: false
��ʾ:
1 <= s.length, goal.length <= 100
s?��?goal?��СдӢ����ĸ���
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s==goal) return true;
        int n=s.size(),m=n;
        while (n--) {
            string tmp=s.substr(1,m-1);
            tmp+=s[0];
            if (tmp==goal) return true;
            s=tmp;
        }
        return false;
    }
};