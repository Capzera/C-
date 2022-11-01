/*
����������P0905
����һ���������� nums���� nums �еĵ�����ż��Ԫ���ƶ��������ǰ�棬�����������Ԫ�ء�
��������������� ��һ���� ��Ϊ�𰸡�
ʾ�� 1��
���룺nums = [3,1,2,4]
�����[2,4,3,1]
���ͣ�[4,2,3,1]��[2,4,1,3] �� [4,2,1,3] Ҳ�ᱻ������ȷ�𰸡�
ʾ�� 2��
���룺nums = [0]
�����[0]
��ʾ��
1 <= nums.length <= 5000
0 <= nums[i] <= 5000
*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        while (i<j) {
            while (i<j&&nums[i]%2==0) i++;
            while (i<j&&nums[j]%2) j--;
            if (i<j)
                swap(nums[i++],nums[j--]);
        }
        return nums;
    }
};