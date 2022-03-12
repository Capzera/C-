/*
����������P0078
����һ����������?nums �������е�Ԫ�� ������ͬ �����ظ��������п��ܵ��Ӽ����ݼ�����
�⼯ ���� �����ظ����Ӽ�������԰� ����˳�� ���ؽ⼯��
ʾ�� 1��
���룺nums = [1,2,3]
�����[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
ʾ�� 2��
���룺nums = [0]
�����[[],[0]]
��ʾ��
1 <= nums.length <= 10
-10 <= nums[i] <= 10
nums �е�����Ԫ�� ������ͬ
*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    vector<bool>check;
    int n;
    void dfs(vector<int> nums,int index,vector<int>tmp)
    {
        if (index==n) return;
        for(int i=index;i<n;i++)
        {
            if (check[i]||(tmp.size()&&nums[i]<tmp.back())) continue;//�жϿ��м�ȥ��
            check[i]=1;//�����
            tmp.push_back(nums[i]);//����
            ans.push_back(tmp);//���Ӽ�
            dfs(nums,index+1,tmp);//dfs��һ��
            check[i]=0;//����
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        this->n=nums.size();
        sort(nums.begin(),nums.end());
        check.resize(n);
        ans.push_back(tmp);
        dfs(nums,0,tmp);
        return ans;
    }
};