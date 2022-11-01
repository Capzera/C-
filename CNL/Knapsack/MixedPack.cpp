#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,W;
    cin >> W >> n;
    vector<int> dp(W + 1);
    for (int i = 0; i < n; i++) {
        int w, v, s;
        cin >> w >> v >> s;
        if (s){//���s > 0��0 k����
            for (int j = W; j >= w; j--){
                for (int k = 1; k <= s && k * w <= j; k++)
                    dp[j] = max(dp[j], dp[j - k * w] + k * v);
            }
        }
        else{//���s == 0 ��ȫ����
            for (int j = w; j <= W; j++) {
                dp[j] = max(dp[j], dp[j - w] + v);
            }
        }
    }
    cout << "MAX = " << dp[W];
    system("pause");
    return 0;
}