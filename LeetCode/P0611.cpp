/*
����������P0611
����һ�������Ǹ�����������?nums ���������п�����������������ߵ���Ԫ�������
ʾ�� 1:
����: nums = [2,2,3,4]
���: 3
����:��Ч�������: 
2,3,4 (ʹ�õ�һ�� 2)
2,3,4 (ʹ�õڶ��� 2)
2,2,3
ʾ�� 2:
����: nums = [4,2,3,4]
���: 4
��ʾ:
1 <= nums.length <= 1000
0 <= nums[i] <= 1000
*/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),ans=0;
        for (int i=0;i<n-2;i++) {
            for (int j=i+1;j<n-1;j++) {
                int l=j+1,r=n,mid,loc=j;
                while (l<r) {
                    mid=l+(r-l)/2;
                    if (nums[i]+nums[j]>nums[mid]) {
                        l=mid+1;
                        loc=mid;
                    }
                    else r=mid;
                }
                ans+=loc-j;
            }
        }
        return ans;
    }
};