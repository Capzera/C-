/*
��һ����������Ϊ V��ͬʱ�� n ����Ʒ��ÿ����Ʒ��һ�������

���ڴ� n ����Ʒ�У���ȡ���ɸ�װ�����ڣ�Ҳ���Բ�ȡ����ʹ���ӵ�ʣ��ռ���С����������Сֵ��
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, v, w;
    cin >> v >> n;
    vector<int> dp(v + 1);
    while (n--) {
        cin >> w;
        for (int j = v; j >= w; j--)
            dp[j] = max(dp[j], dp[j - w] + w);
    }
    cout << v - dp[v] << endl;
    system("pause");
    return 0;
}