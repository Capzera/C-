#include <bits/stdc++.h>
using namespace std;
    int ans = INT_MAX, zerocnt, n, k;
    vector<int> package, bucket;
    void dfs(int index, int maxv){
        if (index == n){
            ans = min(ans, maxv);
            return;
        }
        for (int i = 0; i < k; i++){
            if (bucket[i] + package[index] > ans) continue;//�����ǰͰ��Ԫ���Ѿ����ڱ�����Ĵ𰸣���֦1
            if (n - index < zerocnt) return;
            if (!bucket[i]) zerocnt--;
            bucket[i]  += package[index];
            dfs(index + 1, max(maxv, bucket[i]));
            bucket[i] -= package[index];
            if (!bucket[i]) zerocnt++;
        }
    }
int main() {
    cin >> n >> k;
    package.resize(n);
    bucket.resize(k);
    for (int i = 0; i < n; i++) cin>>package[i];
    bucket[0] = package[0];//��0��Ԫ��Ĭ�Ϸ���0��Ͱ����Ϊk��Ͱ��Ͱ֮��û�����𣬼�֦2
    zerocnt = k - 1;
    dfs(1, package[0]);
    cout<<ans<<endl;
    system("pause");
    return 0;
}
/*
���ֵ��С
��Сֵ���
���ִ�+dfs
*/