/*
����������P0416
����һ�� ֻ���������� �� �ǿ� ����?nums �������ж��Ƿ���Խ��������ָ�������Ӽ���ʹ�������Ӽ���Ԫ�غ���ȡ�
ʾ�� 1��
���룺nums = [1,5,11,5]
�����true
���ͣ�������Էָ�� [1, 5, 5] �� [11] ��
ʾ�� 2��
���룺nums = [1,2,3,5]
�����false
���ͣ����鲻�ָܷ������Ԫ�غ���ȵ��Ӽ���
��ʾ��
1 <= nums.length <= 200
1 <= nums[i] <= 100
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
		int sum=0;
        for (int i:nums) sum+=i;
        if (sum%2) return 0;
        sum/=2;
        vector<bool> dp(sum+1);
        dp[0]=true;
        for (int num:nums){
			for (int j=sum;j>=num;j--)
				if (dp[j-num]) dp[j]=1;
		}
        return dp[sum];
    }
};