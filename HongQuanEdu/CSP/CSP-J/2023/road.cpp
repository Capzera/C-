#include <bits/stdc++.h>
using namespace std;
/*
��Ŀ����
С��׼�����ų����Ź�·�Լݡ�
��·��һ���� n ��վ�㣬���Ϊ�� 1 �� n������վ�� i ��վ�� i + 1 �ľ���Ϊ v_i���
��·��ÿ��վ�㶼���Լ��ͣ����Ϊ i ��վ��һ���͵ļ۸�Ϊ a_iԪ����ÿ��վ��ֻ�������������͡�
С�����վ�� 1 ������վ�� n��һ��ʼС����վ�� 1 �ҳ��������ǿյġ�
��֪���������㹻�󣬿���װ���������ͣ���ÿ���Ϳ����ó�ǰ�� d �����С����վ�� 1 ����վ�� n������Ҫ������Ǯ���ͣ�
*/
int main() {
    int n, d, mn = INT_MAX;
    cin >> n >> d; n--;
    int v[n], a[n];
    long long oil = 0, ans = 0;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        mn = min(mn, a[i]);
        int liter = (v[i] - oil + d - 1) / d;
        oil += 1ll * liter * d - v[i];
        ans += 1ll * liter * mn;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}