/*
����������
����һ�� �� 0 ��ʼ������ nums���±�Ҳ�� 0 ��ʼ�������㹹��һ�� ͬ������ ������ ans ��
���У�����ÿ�� i��0 <= i < nums.length���������� ans[i] = nums[nums[i]] �����ع����õ����� ans ��
�� 0 ��ʼ������ nums ��һ���� 0 ��?nums.length - 1��0 �� nums.length - 1 Ҳ�������ڣ��Ĳ�ͬ������ɵ����顣
ʾ�� 1��
���룺nums = [0,2,1,5,3,4]
�����[0,1,2,4,5,3]
���ͣ����� ans �������£�
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
    = [0,1,2,4,5,3]
ʾ�� 2��
���룺nums = [5,0,1,2,3,4]
�����[4,5,0,1,2,3]
���ͣ����� ans �������£�
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[5], nums[0], nums[1], nums[2], nums[3], nums[4]]
    = [4,5,0,1,2,3]
*/
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size(),i;
        vector<int> ans(n);
        for(i=0;i<n;i++) ans[i]=nums[nums[i]];
        return ans;
    }
};