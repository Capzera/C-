/*
����������P0051
n?�ʺ����� �о�������ν� n?���ʺ������ n��n �������ϣ�����ʹ�ʺ�˴�֮�䲻���໥������
����һ������ n ���������в�ͬ��?n?�ʺ����� �Ľ��������
ÿһ�ֽⷨ����һ����ͬ��?n �ʺ����� �����ӷ��÷������÷����� 'Q' �� '.' �ֱ�����˻ʺ�Ϳ�λ��
ʾ�� 1��
���룺n = 4
�����[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
���ͣ�����ͼ��ʾ��4 �ʺ��������������ͬ�Ľⷨ��
ʾ�� 2��
���룺n = 1
�����[["Q"]]
��ʾ��
1 <= n <= 9
*/
class Solution {
public:
    vector<vector<string>> ans;
    void dfs(int n,vector<int> location,vector<bool> column,vector<bool> diagonal1,vector<bool>diagonal2,int i)
    {
        int j,k;
        for(int j=0;j<n;j++)//����1-n
        {
            if (!column[j]&&!diagonal1[i+j]&&!diagonal2[i-j+n])//�ø��������ʺ�
            {
                location[i]=j;//��¼�ûʺ����
                column[j]=diagonal1[i+j]=diagonal2[i-j+n]=1;//�����
                if (i==n-1)//���лʺ�����
                {
                    vector<string>tmp(n);//������ʱ�ռ䱣��ʺ�λ��
                    for(k=0;k<n;k++)//��Ҫ��ӡn��
                    {
                        for(int k1=0;k1<n;k1++)//������
                        {
                            if (k1==location[k]) tmp[k].push_back('Q');
                            else tmp[k].push_back('.');
                        }
                    }
                    ans.push_back(tmp);
                }
                else dfs(n,location,column,diagonal1,diagonal2,i+1);
                column[j]=diagonal1[i+j]=diagonal2[i-j+n]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> location(n);
        vector<bool> column(n),diagonal1(2*n),diagonal2(2*n);
        dfs(n,location,column,diagonal1,diagonal2,0);
        return ans;
    }
};