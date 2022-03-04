/*
��Ŀ������
��һ���Զ�ά���������ʾ��ͼ����ÿһ��������ʾ��ͼ��������ֵ��С����ֵ�� 0 �� 65535 ֮�䡣
����һ������?(sr, sc)?��ʾͼ����Ⱦ��ʼ������ֵ���� ���У���һ���µ���ɫֵ?newColor������������ɫ���ͼ��
Ϊ�������ɫ�������ӳ�ʼ���꿪ʼ����¼��ʼ��������������ĸ�����������ֵ���ʼ������ͬ���������ص㣬
�����ټ�¼���ĸ������Ϸ������������ص������Ƕ�Ӧ�ĸ�����������ֵ���ʼ������ͬ���������ص㣬������
�ظ��ù��̡��������м�¼�����ص����ɫֵ��Ϊ�µ���ɫֵ��
��󷵻ؾ�����ɫ��Ⱦ���ͼ��
ʾ�� 1:
����: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
���: [[2,2,2],[2,2,0],[2,0,1]]
����: 
��ͼ������м䣬(����(sr,sc)=(1,1)),
��·�������з������������ص����ɫ�������ĳ�2��
ע�⣬���½ǵ�����û�и���Ϊ2��
��Ϊ�����������������ĸ����������ʼ�����������ص㡣
*/
class Solution {
public:
    int move[4][2]={{-1,0},{0,-1},{0,1},{1,0}};//�����ƶ�
    void dfs(vector<vector<bool>>& check,vector<vector<int>>& image,int x,int y,int newColor,int m,int n,int target)
    {
        if (check[x][y]==0) 
        {
            image[x][y]=newColor;//Ⱦɫ
            check[x][y]=1;//�жϸø��Ƿ��߹�����ֹ��ѭ��
        }
        else return;
        for(int i=0;i<4;i++) 
        {
            int dx=x+move[i][0],dy=y+move[i][1];
            if (dx>=0&&dx<m&&dy>=0&&dy<n&&image[dx][dy]==target)//�жϸø��Ƿ����
            {
                dfs(check,image,x+move[i][0],y+move[i][1],newColor,m,n,target);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int target=image[sr][sc],m=image.size(),n=image[0].size();
        vector<vector<bool>> check(m,vector<bool>(n));
        if (target==newColor) return image;
        dfs(check,image,sr,sc,newColor,m,n,target);
        return image;
    }
};