#include <bits/stdc++.h>
using namespace std;
int main() {
    const int N = 100000000;
    clock_t st, ed;
    st = clock();
    vector<int> n1;
    for (int i = 0; i < N; i++) {
        n1.emplace_back(N);
    }
    ed = clock();
    cout << "ʹ��emplace_back�ķ�ʽʱ��Ϊ��" <<(double) ed - st << " ms" << endl;
    st = clock();
    vector<int> n2;
    for (int i = 0; i < N; i++) {
        n2.push_back(N);
    }
    ed = clock();
    cout << "ʹ��push_back�ķ�ʽʱ��Ϊ��" << (double) ed - st << " ms" << endl;
    system("pause");
    return 0;
}