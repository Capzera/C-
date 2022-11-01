class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int i,n=nums.size(),l=0,r,left=0,right=0;
        for(i=0;i<n;i++) if (nums[i]<0) l=i;
        r=l+1;
        if (r==n) left=1;
        while (1)
        {
            if ((left||right)==0)//��ָ����ָ�붼û�ߵ�ͷ
            {
                if (nums[l]*nums[l]<nums[r]*nums[r])
                {
                    ans.push_back(nums[l]*nums[l]);
                    l--;
                }
                else
                {
                    ans.push_back(nums[r]*nums[r]);
                    r++;
                }
            }
            else if (right) //��ָ�뵽ͷ
            {
                ans.push_back(nums[r]*nums[r]);//������ָ���Ӧֵ
                r++;
            }
            else //��ָ�뵽ͷ
            {
                ans.push_back(nums[l]*nums[l]);//������ָ���Ӧֵ
                l--;
            }
            if (!right&&l<0) right=1;
            if (!left&&r==n) left=1;
            if (left&&right) break;
        }
        return ans;
    }
};