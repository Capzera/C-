/*
����������
����һ����СΪ m x n �Ķ����ƾ��� grid ��
����?����һЩ���ڵ�1(��������) ���ɵ���ϣ�����ġ����ڡ�Ҫ������1������ˮƽ������ֱ���ĸ����������ڡ�
����Լ���?grid ���ĸ���Ե���� 0������ˮ����Χ�š�
���������ǵ���ֵΪ1�ĵ�Ԫ�����Ŀ��
���㲢����grid�����ĵ�����������û�е��죬�򷵻����Ϊ 0 ��
ʾ�� 1��
���룺grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
�����6
���ͣ��𰸲�Ӧ���� 11 ����Ϊ����ֻ�ܰ���ˮƽ��ֱ���ĸ������ϵ� 1 ��
ʾ�� 2��
���룺grid = [[0,0,0,0,0,0,0,0]]
�����0

*/
class Solution {
public:
    int move[4][2]={{-1,0},{0,-1},{1,0},{0,1}};//��������
    void dfs(vector<vector<bool>>& check,vector<vector<int>> grid,int m,int n,int x,int y,int& ans)
    {
        if (!check[x][y]) 
        {
            check[x][y]=true;
            if (grid[x][y]==1) ans++;
        }
        else return;
        for(int i=0;i<4;i++)
        {
            int dx=x+move[i][0],dy=y+move[i][1];
            if (dx>=0&&dx<m&&dy>=0&&dy<n&&check[dx][dy]==0&&grid[dx][dy]==1) dfs(check,grid,m,n,dx,dy,ans);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),i,j,maxtot=0;
        vector<vector<bool>> check(m,vector<bool>(n));
        for(i=0;i<m;i++)
            for(j=0;j<n;j++) if (!grid[i][j]) check[i][j]=1;
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            {
                int area=0;
                if (grid[i][j]&&check[i][j]==false) 
                {
                    dfs(check,grid,m,n,i,j,area);
                    maxtot=max(maxtot,area);
                }
            }
        return maxtot;
    }
};