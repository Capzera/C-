/*
����������P0410
����һ���Ǹ��������� nums ��һ������?m ������Ҫ���������ֳ�?m?���ǿյ����������顣
���һ���㷨ʹ����?m?����������Ժ͵����ֵ��С��
ʾ�� 1��
���룺nums = [7,2,5,10,8], m = 2
�����18
���ͣ�
һ�������ַ����� nums �ָ�Ϊ 2 �������顣 
������õķ�ʽ�ǽ����Ϊ [7,2,5] �� [10,8] ��
��Ϊ��ʱ��������������Եĺ͵����ֵΪ18���������������С��
ʾ�� 2��
���룺nums = [1,2,3,4,5], m = 2
�����9
ʾ�� 3��
���룺nums = [1,4,4], m = 3
�����4
��ʾ��
1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= m <= min(50, nums.length)
*/
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
		int n=nums.size(),l=0,r=1;
        for (int num:nums) {
			r+=num;
			l=max(l,num);
        }
        if (m==1) return r-1;
        while (l<r){
			int mid=l+(r-l)/2;
            int cot=1,sum=0;
            for (int num:nums){
                if(sum+num<=mid) {
					sum+=num;
					continue;
                }
                cot++,sum=num;
                if (cot>m) break;
			}
            if (cot>m) l=mid+1;
            else r=mid;
		}
        return r;
    }
};