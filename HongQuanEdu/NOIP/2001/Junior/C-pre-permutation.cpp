/*
����һ�ö�������������������С���������������С���Լ��������ò�ͬ�Ĵ�д��ĸ��ʾ���Ҷ������Ľڵ���� ��8��
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    string mid, post;
    cin >> mid >> post;
    function<void(int, int, int, int)> dfs = [&](int l1, int l2, int r1, int r2) -> void {
        //�������ǰ���һ�������Ϊ���ڵ�
        cout << post[r2];
        //��ѯ�����������������е�λ��
        int m = mid.find(post[r2]);
        //dfs������
        if (m > l1) dfs(l1, m - 1, r1, r1 + m - 1 - l1);
        //dfs������
        if (m < l2) dfs(m + 1, l2, r1 + m - l1, r2 - 1);
    };
    dfs(0, mid.size() - 1, 0, post.size() - 1);
    system("pause");
    return 0;
}