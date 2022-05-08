/*
����������P0417
��һ�� m �� n �ľ��ε��죬�� ̫ƽ�� �� ������ ���ڡ�?��̫ƽ��?���ڴ�½����߽���ϱ߽磬�� �������� ���ڴ�½���ұ߽���±߽硣
��������ָ��һ�������ɷ��ε�Ԫ����ɵ�����
����һ�� m x n ����������?heights?��?heights[r][c]?��ʾ���� (r, c) �ϵ�Ԫ�� ���ں�ƽ��ĸ߶� ��
������ˮ�϶࣬������ڵ�Ԫ��ĸ߶� С�ڻ���� ��ǰ��Ԫ��ĸ߶ȣ�
��ˮ����ֱ���򱱡��ϡ��������������ڵ�Ԫ��ˮ���ԴӺ��󸽽����κε�Ԫ�����뺣��
������������ result?�� 2D �б� ������?result[i] = [ri, ci]?��ʾ��ˮ�ӵ�Ԫ�� (ri, ci) ���� �ȿ�����̫ƽ��Ҳ����������� ��
ʾ�� 1��
����: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
���: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
ʾ�� 2��
����: heights = [[2,1],[1,2]]
���: [[0,0],[0,1],[1,0],[1,1]]
*/
static const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    vector<vector<int>> heights;

    void dfs(int row, int col, vector<vector<bool>> & ocean) {
        int m = ocean.size();
        int n = ocean[0].size();
        if (ocean[row][col]) {
            return;
        }
        ocean[row][col] = true;
        for (int i = 0; i < 4; i++) {
            int newRow = row + dirs[i][0], newCol = col + dirs[i][1];
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && heights[newRow][newCol] >= heights[row][col]) {
                dfs(newRow, newCol, ocean);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dfs(i, 0, pacific);
        }
        for (int j = 1; j < n; j++) {
            dfs(0, j, pacific);
        }
        for (int i = 0; i < m; i++) {
            dfs(i, n - 1, atlantic);
        }
        for (int j = 0; j < n - 1; j++) {
            dfs(m - 1, j, atlantic);
        }
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    vector<int> cell;
                    cell.emplace_back(i);
                    cell.emplace_back(j);
                    result.emplace_back(cell);
                }
            }
        }
        return result;
    }
};