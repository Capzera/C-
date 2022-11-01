/*
����������P0994
�ڸ�����?m x n?����?grid?�У�ÿ����Ԫ���������������ֵ֮һ��
ֵ?0?����յ�Ԫ��
ֵ?1?�����������ӣ�
ֵ?2?�����õ����ӡ�
ÿ���ӣ����õ�����?��Χ?4 ������������ ���������Ӷ��ḯ�á�
���� ֱ����Ԫ����û����������Ϊֹ�����뾭������С����������������ܣ�����?-1?��
ʾ�� 1��
���룺grid = [[2,1,1],[1,1,0],[0,1,1]]
�����4
ʾ�� 2��
���룺grid = [[2,1,1],[0,1,1],[1,0,1]]
�����-1
���ͣ����½ǵ����ӣ��� 2 �У� �� 0 �У���Զ���ḯ�ã���Ϊ����ֻ�ᷢ���� 4 �������ϡ�
ʾ�� 3��
���룺grid = [[0,2]]
�����0
���ͣ���Ϊ 0 ����ʱ�Ѿ�û�����������ˣ����Դ𰸾��� 0 ��
��ʾ��
m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] ��Ϊ?0��1?��?2
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int min=0,fresh=0;
        queue<pair<int, int>> q;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j] == 1) fresh++;//ͳ��������
                else if(grid[i][j] == 2) q.push({i, j});
        }
        vector<pair<int, int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };//�ĸ������ƶ�
        while(!q.empty()) {
            int n=q.size();
            bool rotten=false;
            for(int i=0;i<n;i++) {
                auto x=q.front();
                q.pop();
                for(auto cur:dirs) {
                    int i=x.first+cur.first;
                    int j=x.second+cur.second;
                    if(i>=0&&i<grid.size()&&j>=0&&j<grid[0].size()&&grid[i][j]==1) {
                        grid[i][j]=2;//�µ�������
                        q.push({i, j});//���
                        fresh--;//����������
                        rotten=true;
                    }
                }
            }
            if(rotten) min++;//ʱ������
        } 
        return fresh? -1:min;
    }
};