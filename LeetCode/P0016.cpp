/*
����������P0016
����һ������Ϊ n ����������?nums?�� һ��Ŀ��ֵ?target������� nums ��ѡ������������ʹ���ǵĺ���?target?��ӽ���
�������������ĺ͡�
�ٶ�ÿ������ֻ����ǡ��һ���⡣
ʾ�� 1��
���룺nums = [-1,2,1,-4], target = 1
�����2
���ͣ��� target ��ӽ��ĺ��� 2 (-1 + 2 + 1 = 2) ��
ʾ�� 2��
���룺nums = [0,0,0], target = 1
�����0
��ʾ��
3 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-104 <= target <= 104
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),ans=INT_MAX,distance=ans,sum;
        if (n==3) return nums[0]+nums[1]+nums[2];
        for(int pA=0;pA<n-2;pA++)
        {
            int pB=pA+1,pC=n-1;
            while (pB<pC)
            {
                sum=nums[pA]+nums[pB]+nums[pC];
                if (sum==target) return sum;
                if (sum<target) pB++;
                else pC--;
                if (abs(sum-target)<distance) 
                {
                    distance=(abs(sum-target));
                    ans=sum;
                }
            }
        }
        return ans;
    }
};