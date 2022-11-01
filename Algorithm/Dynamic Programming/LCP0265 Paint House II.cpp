/*
����������P0265
������һ�ŷ��ӹ���?n?����ÿ�����ӿ��Ա���ˢ�� k?����ɫ�е�һ�֡�
���ӷ�ˢ�ɲ�ͬ��ɫ�Ļ��ѳɱ�Ҳ�ǲ�ͬ�ġ�����Ҫ��ˢ���еķ��Ӳ���ʹ�����ڵ�����������ɫ������ͬ��
ÿ�����ӷ�ˢ�ɲ�ͬ��ɫ�Ļ�����һ�� n x k �ľ����ʾ��
���磬costs[0][0] ��ʾ�� 0?�����ӷ�ˢ�� 0 ����ɫ�ĳɱ���costs[1][2]?��ʾ�� 1 �����ӷ�ˢ�� 2 ����ɫ�ĳɱ����Դ����ơ�
���� ��ˢ�����з��ӵ���ͳɱ�?��
ʾ�� 1��
����: costs = [[1,5,3],[2,9,4]]
���: 5
����: 
������ 0 ˢ�� 0 ����ɫ������ 1 ˢ�� 2 ����ɫ������: 1 + 4 = 5; 
���߽� ���� 0 ˢ�� 2 ����ɫ������ 1 ˢ�� 0 ����ɫ������: 3 + 2 = 5. 
ʾ��?2:
����: costs = [[1,3],[2,4]]
���: 5
��ʾ��
costs.length == n
costs[i].length == k
1 <= n <= 100
2 <= k <= 20
1 <= costs[i][j] <= 20
*/
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n=costs.size(),ans=INT_MAX,k=costs[0].size(),i,j;
        if (n==1) {
            for (int i=0;i<k;i++) ans=min(ans,costs[0][i]);
        }
        for (i=1;i<n;i++) {
            for (j=0;j<k;j++) {
                int add=costs[i][j];
                costs[i][j]=1000;
                for (int t=0;t<k;t++) {
                    if (j==t) continue;
                    costs[i][j]=min(costs[i-1][t],costs[i][j]);
                }
                costs[i][j]+=add;
                if (i==n-1) ans=min(ans,costs[i][j]);
            }
        }
        return ans;
    }
};