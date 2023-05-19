#include <bits/stdc++.h>
using namespace std;
long long solve() {
    int n, x;
    cin >> x >> n;
    vector<vector<int>> nums(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        cin >> nums[i][0] >> nums[i][1] >> nums[i][2];
    auto cmp = [](vector<int>& a, vector<int>& b) -> bool {
        return a[0] > b[0];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq;
    sort(nums.begin(), nums.end(), [&](auto& a, auto& b) { return a[1] > b[1]; });
    long long ans = 0;
    for (int t = x, i = 0; t >= 1; --t) {
        while (i < n && nums[i][1] >= t) pq.push(nums[i++]);
        if (pq.empty()) return -1;
        auto select = pq.top(); pq.pop();
        ans += select[0], select[2]--;
        if (select[2]) pq.push(select);
    }
    return ans;
}

int main() {
    cout << solve() << endl;
    system("pause");
    return 0;
}
/*
С����ϲ�����ɿ�������ÿ�춼Ҫ��һ���ɿ�����
һ��С������������һЩ�ɿ��������еĻ������кܶ����ɿ�����
ÿ���ɿ������Լ��ļ۸�������ʣ��ı�����������С��ֻ��û�������ڵ��ɿ�����
����С�����ٻ�����Ǯ�������Լ��� x ����ɿ�����
��������
����ĵ�һ�а����������� x, n���ֱ��ʾ��Ҫ���ɿ������������ɿ�������������
������ n �����������ϵ��ɿ��������е� i �а����������� ai, bi, ci��
��ʾ�� i ���ɿ����ĵ���Ϊ ai�������ڻ�ʣ bi�죨�����ڿ�ʼ�� bi����Գԣ�������Ϊ ci��
�������
���һ��������ʾС������С���ѡ������������С���� x ��Ĺ��򷽰������ ?1��
�����������
ʾ��
����
10 3
1 6 5
2 7 3
3 10 10
���
18
����˵��
һ����ѵķ����ǵ� 1 ���� 5 �飬�� 2 ���� 2 �飬�� 3 ���� 3 �顣ǰ 5 ��Ե� 1 �֣��� 6��7 ��Ե� 2 �֣��� 8 �� 10 ��Ե� 3 �֡�
*/
