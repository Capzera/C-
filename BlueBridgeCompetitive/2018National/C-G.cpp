#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n, k;
    cin >> n >> k;
    vector<string> grid(n);
    vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    for (int i = 0; i < n; i++) cin >> grid[i];
    vector<vector<vector<int>>> dis(n + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
    set<pair<int, int>> s;//s�����޵е���
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == '%') s.insert({i, j});
    queue<tuple<int, int, int>> q;
    dis[0][0][0] = 0, q.push({0, 0, 0});
    while (q.size()) {
        auto [x, y, last] = q.front(); q.pop();
        if (x == n - 1 && y == n - 1) return dis[x][y][last];
        for (int d = 0; d < 4; d++) {
            int mx = x + dx[d], my = y + dy[d];
            if (mx < 0 || mx == n || my < 0 || my == n || grid[mx][my] == '#') continue;
            if (!last && grid[mx][my] == 'X') continue;
            if (s.count({mx, my})) {//Ŀ�����һ���޵е��߸�
                if (dis[mx][my][k] != -1) continue;
                dis[mx][my][k] = dis[x][y][last] + 1;
                q.push({mx, my, k});
                s.erase({mx, my});
            }
            else {
                int next = last ? last - 1 : 0;
                if (dis[mx][my][next] != -1) continue;
                dis[mx][my][next] = dis[x][y][last] + 1;
                q.push({mx, my, next});
            }
        }
    }
    return -1;
}
int main() {
    cout << solve() << endl;
    system("pause");
    return 0;
}
/*
�Թ�������, �ھŽ�C/C++ ����C�� Problem G
С������һ���Թ���Ϸ������Ϸ����Ҫ�����Լ��Ľ�ɫ�뿪һ���� N \times NN��N ��������ɵ� 2D �Թ���
С������ʼλ�������Ͻǣ�����Ҫ�������½ǵĸ��Ӳ����뿪�Թ���
ÿһ�����������ƶ��������������ڵĸ����У�ǰ����Ŀ����ӿ��Ծ�������
�Թ�����Щ����С�����Ծ����������� '.' ��ʾ��
��Щ������ǽ�ڣ�С�����ܾ����������� '#' ��ʾ��
���⣬��Щ�����������壬������ 'X' ��ʾ������С�������޵�״̬�������ܾ�����
��Щ���������޵е��ߣ������� '%' ��ʾ��
��С����һ�ε���ø���ʱ���Զ�����޵�״̬���޵�״̬����� KK ����
֮������ٴε���ø��Ӳ������޵�״̬�ˡ�
�����޵�״̬ʱ�����Ծ���������ĸ��ӣ����ǲ�����/�ٻ����壬�������Ի���ֹû���޵�״̬�Ľ�ɫ������
�����Թ����������С�����پ������������뿪�Թ�?
*/