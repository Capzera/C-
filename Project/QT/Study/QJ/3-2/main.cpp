#include <bits/stdc++.h>
using namespace std;
int main() {
    srand(time(nullptr));
    int a = 14;
    while (a == 14) {
        a = rand() % 39;
    }
    cout << "������ " << a << " ������" <<endl;
    return 0;
}
