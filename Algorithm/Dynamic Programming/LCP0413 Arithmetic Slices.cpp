/*
����������P0413
���һ������ ����������Ԫ�� ������������������Ԫ��֮����ͬ����Ƹ�����Ϊ�Ȳ����С�
���磬[1,3,5,7,9]��[7,7,7,7] �� [3,-1,-5,-9] ���ǵȲ����С�
����һ���������� nums ���������� nums ������Ϊ�Ȳ������ ������ ������
������ �������е�һ���������С�
ʾ�� 1��
���룺nums = [1,2,3,4]
�����3
���ͣ�nums ���������ӵȲ����飺[1, 2, 3]��[2, 3, 4] �� [1,2,3,4] ����
ʾ�� 2��
���룺nums = [1]
�����0
��ʾ��
1 <= nums.length <= 5000
-1000 <= nums[i] <= 1000
*/
//����
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size(),i,j,k,ans=0;
        if (n<3) return 0;
        for(i=n;i>2;i--)//���ѣ�i���ƴ��ڴ�С
        {
            for(j=0;j<n-i+1;j++)//����ָ��
            {
                int minus=nums[j+1]-nums[j],check=0;
                for(k=2;k<i;k++)//�����ڲ�ѯk+jΪ�±�
                {
                    if (nums[k+j]-nums[k+j-1]!=minus)
                    {
                        check=1;
                        break;
                    }
                }
                if (!check)ans++;
            }
        }
        return ans;
    }
};
//��̬�滮
