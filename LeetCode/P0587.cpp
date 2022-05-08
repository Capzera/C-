/*
����������P0587
��һ����ά�Ļ�԰�У���һЩ�� (x, y) �����ʾ������
���ڰ�װ����ʮ�ְ������������������̵�����Χ�����е�����
ֻ�е����е����������Ӱ�Χʱ����԰����Χ��դ��������Ҫ�ҵ�����λ��դ���߽��ϵ��������ꡣ
ʾ�� 1:
����: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
���: [[1,1],[2,0],[4,2],[3,3],[2,4]]
����:
ʾ�� 2:
����: [[1,2],[2,2],[4,2]]
���: [[1,2],[2,2],[4,2]]
����:
��ʹ������һ��ֱ���ϣ���Ҳ��Ҫ�������Ӱ�Χ���ǡ�
ע��:
���е���Ӧ����Χ��һ���㲻�ܼ�����������Χ�����߰����ֳ�һ�����ϡ�
����������� 0 �� 100 ֮�䡣
��԰������һ������
�����������궼�ǲ�ͬ�ġ�
����ĵ�û��˳�����˳��Ҳû��Ҫ��
*/
class Solution {
public:
    int cross(vector<int> & p, vector<int> & q, vector<int> & r) {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if (n < 4) {
            return trees;
        }
        int leftMost = 0;
        for (int i = 0; i < n; i++) {
            if (trees[i][0] < trees[leftMost][0]) {
                leftMost = i;
            }
        }

        vector<vector<int>> res;
        vector<bool> visit(n, false);
        int p = leftMost;
        do {
            int q = (p + 1) % n;
            for (int r = 0; r < n; r++) {
                /* ��� r �� pq ���Ҳ࣬�� q = r */ 
                if (cross(trees[p], trees[q], trees[r]) < 0) {
                    q = r;
                }
            }
            /* �Ƿ���ڵ� i, ʹ�� p ��q ��i ��ͬһ��ֱ���� */
            for (int i = 0; i < n; i++) {
                if (visit[i] || i == p || i == q) {
                    continue;
                }
                if (cross(trees[p], trees[q], trees[i]) == 0) {
                    res.emplace_back(trees[i]);
                    visit[i] = true;
                }
            }
            if  (!visit[q]) {
                res.emplace_back(trees[q]);
                visit[q] = true;
            }
            p = q;
        } while (p != leftMost);
        return res;
    }
};