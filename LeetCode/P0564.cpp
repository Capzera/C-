/*
����������P0564
����һ����ʾ�������ַ���?n ��������������Ļ��������������������������ֹһ�������ؽ�С���Ǹ���
������ġ�����Ϊ����������ľ���ֵ��С��
ʾ�� 1:
����: n = "123"
���: "121"
ʾ�� 2:
����: n = "1"
���: "0"
����: 0 �� 2������Ļ��ģ������Ƿ�����С�ģ�Ҳ���� 0��
��ʾ:
1 <= n.length <= 18
n?ֻ���������
n?����ǰ�� 0
n?������?[1, 1018?- 1] ��Χ�ڵ�����
*/
class Solution {
public:
    vector<long> getCandidates(const string& n) {
        int len = n.length();
        vector<long> candidates = {
            (long)pow(10, len - 1) - 1,
            (long)pow(10, len) + 1,
        };
        long selfPrefix = stol(n.substr(0, (len + 1) / 2));
        for (int i : {selfPrefix - 1, selfPrefix, selfPrefix + 1}) {
            string prefix = to_string(i);
            string candidate = prefix + string(prefix.rbegin() + (len & 1), prefix.rend());
            candidates.push_back(stol(candidate));
        }
        return candidates;
    }

    string nearestPalindromic(string n) {
        long selfNumber = stol(n), ans = -1;
        const vector<long>& candidates = getCandidates(n);
        for (auto& candidate : candidates) {
            if (candidate != selfNumber) {
                if (ans == -1 ||
                    abs(candidate - selfNumber) < abs(ans - selfNumber) ||
                    abs(candidate - selfNumber) == abs(ans - selfNumber) && candidate < ans) {
                    ans = candidate;
                }
            }
        }
        return to_string(ans);
    }
};