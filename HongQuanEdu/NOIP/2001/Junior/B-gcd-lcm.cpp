/*
�������������� x0, y0 ������������������� P, Q �ĸ�����
1.P,Q ����������
2.Ҫ��P, Q��x0Ϊ���Լ������y0Ϊ��С��������
�����������������п��ܵ�P,Q�ĸ�����
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long x, y, ans = 0;
    cin >> x >> y;
    if (x == y) ans--;
    y *= x;
    for (long long i = 1; i <= sqrt(y); i++) {
        if (y % i == 0 && __gcd(i, y / i) == x) ans += 2;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}