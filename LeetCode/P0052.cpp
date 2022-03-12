/*
����������P0052
n?�ʺ����� �о�������ν� n?���ʺ������ n �� n �������ϣ�����ʹ�ʺ�˴�֮�䲻���໥������
����һ������ n ������ n �ʺ����� ��ͬ�Ľ��������������
ʾ�� 1��
���룺n = 4
�����2
���ͣ�����ͼ��ʾ��4 �ʺ��������������ͬ�Ľⷨ��
ʾ�� 2��
���룺n = 1
�����1
��ʾ��
1 <= n <= 9
*/
class Solution {
public:
    vector<bool> col,dia1,dia2;
    int ans=0,n;
    void dfs(int i)
    {
        if (i==n)
        {
            ans++;
            return;
        }
        for(int j=0;j<n;j++)
        {
            if (col[j]||dia1[i+j]||dia2[i-j+n]) continue;
            col[j]=dia1[i+j]=dia2[i-j+n]=1;
            dfs(i+1);
            col[j]=dia1[i+j]=dia2[i-j+n]=0;            
        }
    }
    int totalNQueens(int n) {
        this->n=n;
        col.resize(n);
        dia1.resize(2*n);
        dia2.resize(2*n);
        dfs(0);
        return ans;
    }