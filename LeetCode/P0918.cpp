/*
��Ŀ������
    ����һ������Ϊn�Ļ�����������nums������nums�ķǿ�������������ܺ�?��
    ��������?��ζ�������ĩ�˽����뿪ͷ�����ʻ�״��
        ��ʽ�ϣ�nums[i] ����һ��Ԫ����nums[(i+1)%n],nums[i]��ǰһ��Ԫ����nums[(i-1+n)%n] ��
    ���������ֻ�ܰ����̶�������nums�е�ÿ��Ԫ��һ�Ρ�
        ��ʽ�ϣ�����������nums[i],nums[i+1],...,nums[j],������i<=k1,k2<=j����k1%n==k2%n?��
ʾ�� 1��
���룺
    nums = [1,-2,3,-2]
�����
    3
���ͣ�
    �������� [3] �õ����� 3
ʾ�� 2��
���룺
    nums = [5,-3,5]
�����
    10
    ���ͣ��������� [5,5] �õ����� 5 + 5 = 10
ʾ�� 3��
���룺
    nums = [3,-2,2,-3]
�����
    3
���ͣ��������� [3] �� [3,-2,2] �����Եõ����� 3
*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size(),i,sum=0,ans1=INT_MIN,ans2=INT_MAX,SUM=0;
        for(i=0;i<n;i++)
        {
            SUM+=nums[i];
            sum+=nums[i];
            if (nums[i]>=sum) sum=nums[i];
            ans1=max(ans1,sum);
        }
        sum=0;
        for(i=0;i<n;i++)
        {
            sum+=nums[i];
            if (nums[i]<=sum) sum=nums[i];
            ans2=min(ans2,sum);
        }
        if (SUM==ans2) return ans1;
        return max(ans1,SUM-ans2);
    }
};