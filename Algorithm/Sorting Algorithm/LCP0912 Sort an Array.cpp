/*
����������P0912
����һ����������?nums�����㽫�������������С�
ʾ�� 1��
���룺nums = [5,2,3,1]
�����[1,2,3,5]
ʾ�� 2��
���룺nums = [5,1,1,2,0,0]
�����[0,0,1,1,2,5]
��ʾ��
1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104
*/
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums;
    }
};