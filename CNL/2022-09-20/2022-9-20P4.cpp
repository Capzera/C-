#include <bits/stdc++.h>

using namespace std;
    vector<int> nums;
    int n, L, k, ans = 0;
int main(){
    cin >> L >> n >> k;
    nums.resize(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    nums.push_back(L);
    int l = 0, r = L;
    while (l < r){
        int mid = l + (r - l) / 2;//��Ϊ���β²�Ĵ�
        int cnt = 0;//��¼��ǰ��Ҫ���߼���ʯͷ
        int now = 0;//��¼��ǰʯͷ���
        int i = 0;//��һ��ʯͷ��λ��
        while (i < n + 1){
            if (nums[++i] - nums[now] < mid) cnt++;
            else now = i;
            if (cnt > k) break;
        }
        if (cnt > k) r = mid;
        else {
            ans = mid;
            l = mid + 1;
        }
    }
    cout<<ans;
    system("pause");
    return 0;
}
/*
O(nlogL)
O(1)
*/