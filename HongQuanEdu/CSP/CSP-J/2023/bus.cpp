/*
��Ŀ����
С Z �����ڹ�������ڼ������ΰ�ʿȥһ���������Ѿõľ������Ρ�
���ξ���ĵ�ͼ���� n ���ص㣬����Щ�ص�֮������ m ����·��
���� 1 �ŵص�Ϊ������ڣ�n �ŵص�Ϊ�������ڡ����ǰ�һ�쵱�о�������Ӫҵ��ʱ���Ϊ 0 ʱ�̣�
��� 0 ʱ����ÿ��� k ��λʱ�����һ�����ΰ�ʿ���ﾰ����ڣ�ͬʱ��һ�����ΰ�ʿ�Ӿ�������ʻ�뾰����
���е�·��ֻ�ܵ���ͨ�С�����ÿ����·���οͲ���ͨ������ʱ��Ϊǡ�� 1 ��λʱ�䡣
С Z ϣ���������ΰ�ʿ���ﾰ����ڣ��������Լ�ѡ�������·���ߵ��������ڣ�
�ٳ������ΰ�ʿ�뿪������ζ����������뿪������ʱ�䶼������ k �ķǸ���������
���ڽڼ��տ����ڶ࣬С Z �����ΰ�ʿ�뿪����ǰֻ��һֱ���ž�����·�ƶ������������κεص㣨����������ںͳ��ڣ����ߵ�·��ͣ����
����ǰ��С Z ��Ȼ��֪��������ȡ�����ƿ����ķ���������ÿ����·��������һ��������ʱ�䡱a_i���ο�ֻ�в�����a_iʱ�̲���ͨ��������·��
�����С Z ���һ�����η�����ʹ�����������ΰ�ʿ�뿪������ʱ�価�����硣
*/
#include <bits/stdc++.h>
#define pii pair<int, int>
#define tii tuple<int, int, int>
using namespace std;
vector<vector<pii>> edge;
vector<vector<int>> dis;
int n, m, k, u, v, w;
void Dijskra() {
    priority_queue<tii, vector<tii>, greater<tii> > pq;
    vector<vector<bool>> vis(n + 1, vector<bool>(k + 1));
    dis[1][0] = 0; pq.push({0, 1, 0});
    while (pq.size()) {
        auto [last, sn, x] = pq.top(); pq.pop();
        if (vis[sn][x]) continue;
        vis[sn][x] = 1;
        for (auto [fn, limit] : edge[sn]) {
            int time = dis[sn][x], y = (x + 1) % k;
            if (time < limit) time += (limit - time + k - 1) / k * k;
            if (time + 1 < dis[fn][y]) {
                dis[fn][y] = time + 1;
                pq.push({dis[fn][y], fn, y});
            }
        }
    }
    if (dis[n][0] == INT_MAX) dis[n][0] = -1;
}
int main() {
    cin >> n >> m >> k;
    edge.resize(n + 1);
    dis = vector<vector<int>>(n + 1, vector<int>(k + 1, INT_MAX));
    while (m--) {
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
    }
    Dijskra();
    cout << dis[n][0] << endl;
    system("pause");
    return 0;
}