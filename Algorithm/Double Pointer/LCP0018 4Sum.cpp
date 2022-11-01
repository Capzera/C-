/*
����������P0018
����һ���� n ��������ɵ�����?nums ����һ��Ŀ��ֵ target ��
�����ҳ���������������ȫ�������Ҳ��ظ�����Ԫ��?[nums[a], nums[b], nums[c], nums[d]]?
����������Ԫ��Ԫ��һһ��Ӧ������Ϊ������Ԫ���ظ�����
0 <= a, b, c, d?< n
a��b��c �� d ������ͬ
nums[a] + nums[b] + nums[c] + nums[d] == target
����԰� ����˳�� ���ش� ��
ʾ�� 1��
���룺nums = [1,0,-1,0,-2,2], target = 0
�����[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
ʾ�� 2��
���룺nums = [2,2,2,2,2], target = 8
�����[[2,2,2,2]]
��ʾ��
1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> tmp(4);
        if (n<4) return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            if (i&&nums[i]==nums[i-1]) continue;//��ֹ�ظ���i�������
            if ((long)nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;//��֦�������i���ʹ���target
            if ((long)nums[i]+nums[n-1]+nums[n-2]+nums[n-3]<target) continue;//��֦�������i��С��С��target
            for(int j=i+1;j<n-2;j++)
            {
                if (j>i+1&&nums[j]==nums[j-1]) continue;
                if ((long)nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;//��֦�������j���ʹ���target
                if ((long)nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;//��֦�������j��С��С��target
                int x=j+1,y=n-1;//������ָ���ֵ
                while (x<y)
                {
                    int tot=nums[i]+nums[j]+nums[x]+nums[y];//���浱ǰ������֮��
                    if (tot==target)//�ҵ���
                    {
                        ans.push_back({nums[i],nums[j],nums[x],nums[y]});
                        while (x<y&&nums[x]==nums[x+1]) x++;//��ֹ����ָ���ظ����ظ���
                        x++;
                        while (x<y&&nums[y]==nums[y-1]) y--;//��ֹ����ָ���ظ����ظ���
                        y--;
                    }
                    else if (tot>target) y--;//�ͽϴ�������ָ��
                    else x++;//�ͽ�С��������ָ��
                }
            }
        }
        return ans;
    }
};