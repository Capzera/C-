#include <bits/stdc++.h>
using namespace std;
vector<int> solve(int n) {
    //lastͳ��ǰ�������ֵĴ�����ansͳ��ÿ�����Ĵ𰸣�bese���ݴ�����
    //base����Ϊʲô������Ϊ10����Ϊ���ַ�Χ������1e9�����10λ�����������ĳ�1e18��baseҲӦ������Ϊ19
    vector<int> nums, last(10), ans(10), base(10);
    if (!n) return ans;
    while (n) nums.emplace_back(n % 10), n /= 10;
    int m = nums.size();
    vector<vector<int>> f(m + 1, vector<int>(10)), g(m + 1, vector<int>(10));
    //���ݴ����飬������ȡ��Rabin-Karp��������ϣ���㷨
    base[0] = 1;
    for (int i = 1; i < 10; i++) base[i] = base[i - 1] * 10;

    //f[i][j] ��ʾ 10^(i - 1) ... 999(i��9)�ж��ٸ�j����iȡ4ʱ��ʾ1000-9999�ж��ٸ�j
    for (int i = 0; i < 10; i++) f[1][i] = 1;
    for (int i = 2; i <= m; i++)
        for (int j = 0; j < 10; j++)
            //����1000-9999�С�100-999�Ĳ��ֳ�10����"j000"��ͷ�ĸ���
            f[i][j] = f[i - 1][j] * 10 + base[i - 1];

    //g[i][j] ��ʾ��0 ... 999(i��9) �ж��ٸ�j
    for (int i = 1; i < 10; i++) g[1][i] = 1;
    for (int i = 2; i <= m; i++) {
        //��������0����Ϊ��λ������0������0-9999��ֻ����0100-0999����� + ��0~999�������λ��1 - 9��
        g[i][0] = g[i - 1][0] + 9 * f[i - 1][0];
        for (int j = 1; j < 10; j++)
            //���ڲ���0������ȿ��� 100-999�г���j�ĸ�����9����λ��1-9��������������λΪ0���ټ�����λΪjʱ��j000����1000��j
            g[i][j] = g[i - 1][j] + 9 * f[i - 1][j] + base[i - 1];
    }
    //����0-9ÿ�����֣�����λΪF�������ȿ���F000-F999ÿ�������ֵĸ���
    for (int i = 0; i < 10; i++) ans[i] = g[m - 1][i];

    for (int i = m - 1; i >= 0; --i) {//���iλ
        int x = nums[i];
        //������һ���ǳ����õĲ��������i == m - 1Ҳ������λ�Ļ���ֻ�ܴ�1��ʼ��������������߼��ж�Ϊ�٣���0��ʼ����
        for (int j = (i == m - 1); j < x; j++) {//j��ʾ���������Ϊj
            ans[j] += base[i];//��i����λ��дjʱ(j0000...99999)�ĸ���
            for (int k = 0; k < 10; k++) {
                ans[k] += base[i] * last[k];//ǰ�ô�����
                ans[k] += f[i][k];//���ô�����
            }
        }
        last[x]++;
    }
    //ѭ���У����ǿ����������ֻ���ǵ�n - 1������n��������ԣ�ÿ���������ּ���Ҳ��Ϊ��
    //����ǰ����Ŀ�У���Ϊֻ��Ҫ����һ�����֣�����д��if (!i) ans++;
    for (int k = 0; k < 10; k++) ans[k] += last[k];
    return ans;
}
int main() {
    int a, b;
    while (cin >> a >> b, a | b) {
        if (a > b) swap(a, b);
        vector<int> x = solve(b), y = solve(a - 1);
        for (int i = 0; i < 10; i++) cout << x[i] - y[i] << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}