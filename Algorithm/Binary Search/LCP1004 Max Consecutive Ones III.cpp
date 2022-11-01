/*
����������P1004
����һ������������?nums?��һ������?k?��������Է�ת���k?�� 0 ���򷵻� ���������� 1 �������� ��
ʾ�� 1��
���룺nums = [1,1,1,0,0,0,1,1,1,1,0], K = 2
�����6
���ͣ�[1,1,1,0,0,1,1,1,1,1,1]
�������ִ� 0 ��ת�� 1����������鳤��Ϊ 6��
ʾ�� 2��
���룺nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
�����10
���ͣ�[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
�������ִ� 0 ��ת�� 1����������鳤��Ϊ 10��
��ʾ��
1 <= nums.length <= 105
nums[i]?����?0?����?1
0 <= k <= nums.length
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size(),ans=k? 1:0;
        vector<int> sum(n+1);
        for (int i=1;i<=n;i++) sum[i]=sum[i-1]+nums[i-1];
        int l=0,r=n+1,mid=ans;
        while (l<r) {
            mid=l+(r-l)/2;//mid������ִ�
            int step=0;//step��¼��ǰ���Ƿ��н�
            for (int i=0;i<n-mid+1;i++) {
                if (mid-(sum[i+mid]-sum[i])<=k) {//�ж���Ҫ�����Ĵ����Ƿ�С�ڵ���k
                    step=1;//����
                    ans=max(ans,mid);//��¼��
                    break;//��֦
                }
            }
            if (step) l=mid+1;//�𰸿��У����Ҷ���
            else r=mid;//�𰸷Ƿ����������
        }
        return ans;
    }
};