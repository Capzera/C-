/*
��Ŀ������
    ����һ������?pairs ������?pairs[i] = [xi, yi]?���������㣺
        pairs?��û���ظ�Ԫ��
        xi < yi
        ��?ways?Ϊ���������������и����ķ�������
            �������������нڵ�ֵ���� pairs?�С�
            һ������?[xi, yi] ������?pairs?��?���ҽ���?xi?��?yi?�����Ȼ���?yi?��?xi?�����ȡ�
    ע�⣺�������������һ���Ƕ�������
    ����������Ϊ��ͬ�ķ�������������һ���ڵ������������в�ͬ�ĸ��ڵ㡣
���㷵�أ�
    ���?ways == 0?������?0?��
    ���?ways == 1?������ 1?��
    ���?ways > 1?������?2?��
    һ�� �и���?ָ����ֻ��һ�����ڵ���������б߶��ǴӸ�����ķ���
    ���ǳƴӸ���һ���ڵ�·���ϵ�����һ���ڵ㣨��ȥ�ڵ㱾�����Ǹýڵ�� ����?�����ڵ�û�����ȡ�
ʾ�� 1��
���룺
    pairs = [[1,2],[2,3]]
�����
    1
    ���ͣ�����ͼ��ʾ������ֻ��һ�����Ϲ涨���и�����
ʾ�� 2��
���룺
    pairs = [[1,2],[2,3],[1,3]]
�����2
���ͣ�
    �ж�����Ϲ涨���и�����������������ͼ��ʾ��
ʾ�� 3��
���룺
    pairs = [[1,2],[2,3],[2,4],[1,5]]
�����0
���ͣ�
    û�з��Ϲ涨���и�����
*/
class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        unordered_map<int, unordered_set<int>> adj;
        for (auto &p : pairs) {
            adj[p[0]].emplace(p[1]);
            adj[p[1]].emplace(p[0]);
        }
        /* ����Ƿ���ڸ��ڵ�*/
        int root = -1;
        for (auto &[node, neighbours] : adj) {
            if (neighbours.size() == adj.size() - 1) {
                root = node;
                break;
            }
        }
        if (root == -1) {
            return 0;
        }

        int res = 1;
        for (auto &[node, neighbours] : adj) {
            if (node == root) {
                continue;
            }
            int currDegree = neighbours.size();
            int parent = -1;
            int parentDegree = INT_MAX;

            /* ���� degree �Ĵ�С�ҵ� node �ĸ��ڵ� parent */
            for (auto &neighbour : neighbours) {
                if (adj[neighbour].size() < parentDegree && adj[neighbour].size() >= currDegree) {
                    parent = neighbour;
                    parentDegree = adj[neighbour].size();
                }
            }
            if (parent == -1) {
                return 0;
            }

            /* ��� neighbours �Ƿ��� adj[parent] ���Ӽ� */
            for (auto &neighbour : neighbours) {
                if (neighbour == parent) {
                    continue;
                }
                if (!adj[parent].count(neighbour)) {
                    return 0;
                }
            }
            if (parentDegree == currDegree) {
                res = 2;
            }
        }
        return res;
    }
};