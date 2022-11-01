/*
����������P0713
����һ���������� nums ��һ������ k �����㷵��������������Ԫ�صĳ˻��ϸ�С�� k ���������������Ŀ��
ʾ�� 1��
���룺nums = [10,5,2,6], k = 100
�����8
���ͣ�8 ���˻�С�� 100 ��������ֱ�Ϊ��[10]��[5]��[2],��[6]��[10,5]��[5,2]��[2,6]��[5,2,6]��
��Ҫע����� [10,5,2] �����ǳ˻�С�� 100 �������顣
ʾ�� 2��
���룺nums = [1,2,3], k = 0
�����0
��ʾ:?
1 <= nums.length <= 3 * 104
1 <= nums[i] <= 1000
0 <= k <= 106
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size(),ans=0;
        int prod=1,i=0;
        for (int j=0;j<n;j++) {
            prod*=nums[j];
            while (i<=j&&prod>=k)
                prod/=nums[i++];
            ans+=j-i+1;
        }
        return ans;
    }
};