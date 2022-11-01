/*
����������P0046
����һ�������ظ����ֵ����� nums �������� ���п��ܵ�ȫ���� ������� ������˳�� ���ش𰸡�
ʾ�� 1��
���룺nums = [1,2,3]
�����[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
ʾ�� 2��
���룺nums = [0,1]
�����[[0,1],[1,0]]
ʾ�� 3��
���룺nums = [1]
�����[[1]]
��ʾ��
1 <= nums.length <= 6
-10 <= nums[i] <= 10
nums �е��������� ������ͬ
*/
class Solution {
public:
    vector<vector<int>> ans;//�����
    void dfs(int n,vector<int>nums,vector<int> loc,vector<int> index,int i)
    {
        for(int j=0;j<n;j++)
        {
            if (index[j]) continue;
            loc[i]=j;
            index[j]=1;
            if (i==n-1)//���е����Ѿ�������
            {
                vector<int> tmp;
                for(int k=0;k<n;k++) tmp.push_back(nums[loc[k]]);
                ans.push_back(tmp);
            }
            else dfs(n,nums,loc,index,i+1);
            index[j]=0;
        } 
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> loc(n),index(n);//��ǵ�i�����Ƿ�ʹ��
        dfs(n,nums,loc,index,0);
        return ans;
    }
};