/*
����������P0485
����һ������������ nums �� ��������������� 1 �ĸ�����
ʾ�� 1��
���룺nums = [1,1,0,1,1,1]
�����3
���ͣ���ͷ����λ��������λ�������� 1 ������������� 1 �ĸ����� 3.
ʾ�� 2:
���룺nums = [1,0,1,1,0,1]
�����2
��ʾ��
1 <= nums.length <= 105
nums[i]?����?0?����?1.
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
		int n=nums.size(),ans=nums[0],cnt=nums[0];
        for (int i=1;i<n;i++){
			if (!nums[i]&&nums[i-1]) ans=max(ans,cnt);
            else if (nums[i]&&!nums[i-1]) cnt=1;
            else if (nums[i]*nums[i-1]) cnt++;
		}
        return max(ans,cnt);
    }
};