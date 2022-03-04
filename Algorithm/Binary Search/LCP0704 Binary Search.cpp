/*
����������P704
����һ��?n?��Ԫ������ģ�������������?nums ��һ��Ŀ��ֵ?target ?��
дһ����������?nums?�е� target�����Ŀ��ֵ���ڷ����±꣬���򷵻� -1��
ʾ�� 1:
����: nums = [-1,0,3,5,9,12], target = 9
���: 4
����: 9 ������ nums �в����±�Ϊ 4
ʾ��?2:
����: nums = [-1,0,3,5,9,12], target = 2
���: -1
����: 2 ������ nums ����˷��� -1
��ʾ��
����Լ��� nums?�е�����Ԫ���ǲ��ظ��ġ�
n?����?[1, 10000]֮�䡣
nums?��ÿ��Ԫ�ض�����?[-9999, 9999]֮�䡣
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size(),mid=(l+r)/2;
        while (l<mid)
        {
            if (nums[mid]<target) l=mid+1;
            if (nums[mid]>target) r=mid;
            if (nums[mid]==target) return mid;
            mid=(l+r)/2;
        }
        if (nums[mid]==target)return mid;
        else return -1;
    }
};