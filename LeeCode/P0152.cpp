/*
����������
����һ���������� nums?�������ҳ������г˻����ķǿ����������飨�������������ٰ���һ�����֣��������ظ�����������Ӧ�ĳ˻���
���������Ĵ���һ��?32-λ ������
������ ����������������С�
ʾ�� 1:
����: nums = [2,3,-2,4]
���: 6
����:?������ [2,3] �����˻� 6��
ʾ�� 2:
����: nums = [-2,0,-1]
���: 0
����:?�������Ϊ 2, ��Ϊ [-2,-1] ���������顣
*/
class Solution {
public:
    int maxsection (vector<int> nums,int l,int r,int minus)
    {
        int sum=1,ans=1;
        if (l==r) return nums[l];
        if (minus%2==0) for(int i=l;i<=r;i++) sum*=nums[i];//������ż�������������
        else//������������
        {
            int left=r+1,right=l-1;
            for(int i=l;i<=r;i++)
            {
                if (nums[i]<0)
                {
                    left=min(left,i);//left��¼����ߵĸ���
                    right=max(right,i);//right��¼���ұߵĸ���
                }
            }
            for(int i=l;i<right;i++) sum*=nums[i];//ȥ������߸��������
            for(int i=left+1;i<=r;i++) ans*=nums[i];//ͬ��ȥ�����ұ߸���
            sum=max(sum,ans);
        }
        return sum;
    }
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),i,minus=0;
        if (n==1) return nums[0];
        map<int,int> zero;//��¼0���λ��
        for(i=0;i<n;i++)
        {
            if (nums[i]<0) minus++;//��¼�������ж��ٸ�����
            if (!nums[i]) 
            {
                zero[i]=minus;
                minus=0;
            }
        }i=0;
        zero[n]=minus;//��¼�յ�����ж��ٸ�����
        map<int,int>::iterator nextzero=zero.begin();//��������¼0��λ��
        int current=nums[0];
        while (i<n&&!nums[i])
        {   
            i++;
            nextzero++;//������ǰ��0
        }
        while (i<n)
        {
            current=max(current,maxsection(nums,i,nextzero->first-1,nextzero->second));//��������ֵ
            if (nextzero->first==n) break;//���������һ�飬�˳�
            else i=nextzero++->first+1;//��Ȼ������һ��0�㣬����0��󣬸��µ�����
        }
        if (zero.size()>1&&current<0) current=0;//��0���ڵ�������С��0������
        return current;
    }
};