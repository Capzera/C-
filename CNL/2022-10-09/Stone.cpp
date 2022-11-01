#include <bits/stdc++.h>

using namespace std;

int main() {
    int L, D, N, ans;
    cin >> L >> D >> N;
    vector<int> nums(1);
    nums[0] = 0;
    for (int i = 0; i < N; i ++) {
        int put;
        cin>>put;
        nums.push_back(put);
    }
    nums.push_back(L);
    int l = 0, r = L;
    while (l < r) {
        int mid = l + (r - l) / 2, cnt = 0, last = 1;//����С���Ǹ��𰸾���mid
        for (int i = 2; i <= n + 1; i++) {
            if (nums[i] - nums[last] < mid) cnt++;
            else last = i;
            if (cnt > D) break;
        }
        if (cnt > D) r = mid;
        else {
            ans = mid;
            l = mid + 1;
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
/*
    ���ߴ��� D��ʯͷ �µ�̫���ˣ�Ҳ����mid̫���� R = mid;
    ����С�ڵ��� D��ʯͷ �µ�̫խ�� ��mid̫С�ˣ�ans = mid;L = mid + 1;
*/