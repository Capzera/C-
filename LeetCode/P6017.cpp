/*
����������P6017 ���۵�283������
����һ���������� nums ��һ������ k �������� nums ��׷�� k �� δ ������ nums �еġ�������ͬ �� �� ��������ʹ��������Ԫ�غ� ��С ��
����׷�ӵ� nums �е� k ������֮�͡�
ʾ�� 1��
���룺nums = [1,4,25,10,25], k = 2
�����5
���ͣ��ڸýⷨ�У���������׷�ӵ�����������ͬ��δ���ֵ��������� 2 �� 3 ��
nums ����Ԫ�غ�Ϊ 1 + 4 + 25 + 10 + 25 + 2 + 3 = 70 ��������������е���Сֵ��
����׷�ӵ������е���������֮���� 2 + 3 = 5 �����Է��� 5 ��
ʾ�� 2��
���룺nums = [5,6], k = 6
�����25
���ͣ��ڸýⷨ�У���������׷�ӵ�����������ͬ��δ���ֵ��������� 1 ��2 ��3 ��4 ��7 �� 8 ��
nums ����Ԫ�غ�Ϊ 5 + 6 + 1 + 2 + 3 + 4 + 7 + 8 = 36 ��������������е���Сֵ��
����׷�ӵ������е���������֮���� 1 + 2 + 3 + 4 + 7 + 8 = 25 �����Է��� 25 ��
��ʾ��
1 <= nums.length <= 105
1 <= nums[i], k <= 109
*/
class Solution {
public:
    long long sum(int l,int r)
    {
        return (long long)(l+r)*(long long )(r-l+1)/2;
    }
    long long minimalKSum(vector<int>& nums, int k) {
        long long ans=0;
        set<int> tmp;
        tmp.insert(nums.begin(),nums.end());
        nums.assign(tmp.begin(),tmp.end());
        int n=nums.size(),key=1;
        for(int i=0;i<n;i++)
        {
            if (k<=0) break;
            if (key==nums[i]||key>nums[i])
            {
                key=nums[i]+1;
                continue;
            }
            if (nums[i]-key+1<=k)
            {
                ans+=sum(key,nums[i]-1);
                k-=nums[i]-key;
                key=nums[i]+1;
            }
            else
            {
                ans+=sum(key,key+k-1);
                k=0;
            }
        }
        if (k>0) ans+=sum(nums[n-1]+1,nums[n-1]+k);
        return ans;
    }
};