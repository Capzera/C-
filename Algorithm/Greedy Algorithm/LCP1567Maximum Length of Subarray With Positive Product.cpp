/*
����������
����һ���������� nums?����������˻�Ϊ�������������ĳ��ȡ�
һ�����������������ԭ������������߸��������������ɵ����顣
���㷵�س˻�Ϊ������������鳤�ȡ�
ʾ��? 1��
���룺nums = [1,-2,-3,4]
�����4
���ͣ����鱾��˻�����������ֵΪ 24 ��
ʾ�� 2��
���룺nums = [0,1,-2,-3,-4]
�����3
���ͣ���˻�Ϊ������������Ϊ [1,-2,-3] ���˻�Ϊ 6 ��
ע�⣬���ǲ��ܰ� 0 Ҳ�������������У���Ϊ�����˻�Ϊ 0 ������������
ʾ�� 3��
���룺nums = [-1,-2,-3,0,1]
�����2
���ͣ��˻�Ϊ��������������� [-1,-2] ���� [-2,-3] ��
*/
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n=nums.size(),i=0,ans=0,minus=0,left=n,right=-1;//̰���㷨
        while (nums[i]==0) 
        {i++;if (i==n) return 0;}//ȥ��ǰ��0
        while (nums[n-1]==0) n--;//ȥ��ĩβ0
        nums.resize(n+1);nums[n]=0;//��ĩβ0��ֹ����
        int last=i;
        for(;i<=n;i++)
        {
            if (nums[i]==0)//�ҵ�0Ϊ�ָ���
            {
                if (minus%2==0) ans=max(ans,i-last);//��������ż����������ֱ�Ӽ������䳤��
                else ans=max(ans,max(right-last,i-1-left));
                last=i+1;minus=0;//��һ����ʼ��Ϊ0��
                right=i;left=n;//����ָ��
                continue;
            }
            if (nums[i]<0)
            {
                minus++;
                left=min(left,i);
                right=max(right,i);
            }
        }
        return ans;
    }
};