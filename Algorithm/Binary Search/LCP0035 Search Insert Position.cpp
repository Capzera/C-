/*
��������:P0035
����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
�����ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��
ʾ�� 1:
����: nums = [1,3,5,6], target = 5
���: 2
ʾ��?2:
����: nums = [1,3,5,6], target = 2
���: 1
ʾ�� 3:
����: nums = [1,3,5,6], target = 7
���: 4
ʾ�� 4:
����: nums = [1,3,5,6], target = 0
���: 0
ʾ�� 5:
����: nums = [1], target = 0
���: 0
��ʾ:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums Ϊ���ظ�Ԫ�ص�������������
-104 <= target <= 104
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size(),mid=l+(r-l)/2;
        while (l<r)
        {
            if (nums[mid]<target) l=mid+1;
            else if (nums[mid]>target) r=mid;
            else return mid;
            mid=l+(r-l)/2;
        }
        return mid;
    }
};