/*
����������P0883
��?n x n?������?grid?�У����Ƿ�����һЩ�� x��y��z ��������?1 x 1 x 1?�����塣
ÿ��ֵ?v = grid[i][j]?��ʾ v?������������ڵ�Ԫ��?(i, j)?�ϡ�
���ڣ����ǲ鿴��Щ�������� xy?��yz?�� zx?ƽ���ϵ�ͶӰ��
ͶӰ?����Ӱ�ӣ��� ��ά ����ӳ�䵽һ�� ��ά ƽ���ϡ��Ӷ�����ǰ��Ͳ��濴������ʱ�����ǻῴ����Ӱ�ӡ���
���� ��������ͶӰ������� ��
ʾ�� 1��
���룺[[1,2],[3,4]]
�����17
���ͣ������и����������������ƽ���ϵ�����ͶӰ(����Ӱ���֡�)��
ʾ��?2:
���룺grid = [[2]]
�����5
ʾ�� 3��
���룺[[1,0],[0,2]]
�����8
��ʾ��
n == grid.length == grid[i].length
1 <= n <= 50
0 <= grid[i][j] <= 50
*/
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
		int n=grid.size();
        vector<int> cmax(n);
        int ans=0;
        for (int i=0;i<n;i++){
			int rmax=0;
			for (int j=0;j<n;j++){
				if (!grid[i][j]) continue;
                ans++;
                rmax=max(rmax,grid[i][j]);
                cmax[j]=max(cmax[j],grid[i][j]);
			}
            ans+=rmax;
		}
        for (int i:cmax) ans+=i;
        return ans;
    }
};