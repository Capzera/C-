/*
����������P0908
����һ���������� nums����һ������ k ��
��һ�������У�������ѡ�� 0 <= i < nums.length ���κ����� i ���� nums[i] ��Ϊ nums[i] + x ��
���� x ��һ����ΧΪ [-k, k] ������������ÿ������ i ����� ֻ�� Ӧ�� һ�� �˲�����
nums?��?����?��?nums?��������СԪ�صĲ�ֵ��?
�ڶ�? nums �е�ÿ���������Ӧ��һ�����������󣬷���?nums ����� ���� ��
ʾ�� 1��
���룺nums = [1], k = 0
�����0
���ͣ������� max(nums) - min(nums) = 1 - 1 = 0��
ʾ�� 2
���룺nums = [0,10], k = 2
�����6
���ͣ��� nums ��Ϊ [2,8]�������� max(nums) - min(nums) = 8 - 2 = 6��
ʾ�� 3��
���룺nums = [1,3,6], k = 3
�����0
���ͣ��� nums ��Ϊ [4,4,4]�������� max(nums) - min(nums) = 4 - 4 = 0��
��ʾ��
1 <= nums.length <= 104
0 <= nums[i] <= 104
0 <= k <= 104
*/
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minv=INT_MAX,maxv=INT_MIN;
        for (int i:nums){
            minv=min(minv,i);
            maxv=max(maxv,i);
        }
        return max(0,maxv-minv-2*k);
    }
};