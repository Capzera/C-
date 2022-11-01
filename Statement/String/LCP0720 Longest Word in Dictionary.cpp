/*
����������P0720
����һ���ַ�������?words ��ɵ�һ��Ӣ��ʵ䡣����?words �����һ�����ʣ��õ�������?words?�ʵ����������������һ����ĸ��ɡ�
�������ж�����еĴ𰸣��򷵻ش����ֵ�����С�ĵ��ʡ����޴𰸣��򷵻ؿ��ַ�����
ʾ�� 1��
���룺words = ["w","wo","wor","worl", "world"]
�����"world"
���ͣ� ����"world"����"w", "wo", "wor", �� "worl"�����һ����ĸ��ɡ�
ʾ�� 2��
���룺words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
�����"apple"
���ͣ�"apply" �� "apple" �����ɴʵ��еĵ�����ɡ����� "apple" ���ֵ���С�� "apply" 
��ʾ��
1 <= words.length <= 1000
1 <= words[i].length <= 30
����������ַ���?words[i]?��ֻ����Сд��ĸ��
*/
class Solution {
public:
    string longestWord(vector<string> &words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() != b.size() ? a.size() < b.size() : a > b;
        });
        string longest;
        unordered_set<string> candidates = {""};
        for (const auto &word: words) {
            if (candidates.count(word.substr(0, word.size() - 1))) {
                candidates.emplace(word);
                longest = word;
            }
        }
        return longest;
    }
};