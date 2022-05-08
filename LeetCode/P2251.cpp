/*
����������P2251
����һ���±�� 0?��ʼ�Ķ�ά��������?flowers?��
    ����?flowers[i] = [starti, endi]?��ʾ��?i?�仨�� ����?��?starti?��?endi?���� ��������
ͬʱ����һ���±�� 0?��ʼ��СΪ n?����������?persons?��persons[i]?�ǵ�?i?������������ʱ�䡣
���㷵��һ����СΪ n?����������?answer?������?answer[i]�ǵ�?i?���˵���ʱ�ڻ����ڻ���?��Ŀ?��
ʾ�� 1��
���룺flowers = [[1,6],[3,7],[9,12],[4,13]], persons = [2,3,7,11]
�����[1,2,2,2]
���ͣ���ͼչʾ��ÿ�仨�Ļ���ʱ�䣬��ÿ���˵ĵ���ʱ�䡣
��ÿ���ˣ����Ƿ������ǵ���ʱ�ڻ����ڻ�����Ŀ��
ʾ�� 2��
���룺flowers = [[1,10],[3,3]], persons = [3,3,2]
�����[2,2,1]
���ͣ���ͼչʾ��ÿ�仨�Ļ���ʱ�䣬��ÿ���˵ĵ���ʱ�䡣
��ÿ���ˣ����Ƿ������ǵ���ʱ�ڻ����ڻ�����Ŀ��
��ʾ��
1 <= flowers.length <= 5 * 104
flowers[i].length == 2
1 <= starti <= endi <= 109
1 <= persons.length <= 5 * 104
1 <= persons[i] <= 109
*/
class Solution {
    typedef pair<int, int> pii;
    const int INF = 1e9;
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<pii> vec;
        for (auto &f : flowers) vec.push_back({f[0], -INF}), vec.push_back({f[1], INF});
        for (int i = 0; i < persons.size(); i++) vec.push_back({persons[i], i});
        sort(vec.begin(), vec.end());
        vector<int> ans(persons.size());
        int now = 0;
        for (pii p : vec) {
            if (p.second<0) now++;
            else if (p.second == INF) now--;
            else ans[p.second] = now;
        }
        return ans;
    }
};