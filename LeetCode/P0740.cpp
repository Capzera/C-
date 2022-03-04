class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> v;
        int n=nums.size(),i,ans=0,MAX=-1,MIN=INT_MAX;
        if (n==1) return nums[0];
        for(i=0;i<n;i++) 
        {
            v[nums[i]]++;
            MAX=max(MAX,nums[i]);//����Ҫ��������ֵ
            MIN=min(MIN,nums[i]);//����Ҫ�������Сֵ
        }
        for(i=MIN;i<=MAX;i++) v[i]*=i;//����ͬ��Key�ϲ�����˻�
        int x=v[MIN],y=v[MIN+1];//X����<i-2�����ֵ��Y����i-1�����ֵ
        for (i=MIN+2;i<=MAX;i++)
        {
		    ans=max(x+v[i],y);//dp[i]=max(dp[i-2]+v[i],dp[i-1])
            x=max(x,y);
            y=ans;
	    }
        return max(ans,y);//max(dp[max],dp[max-1])�����յ������һ���������յ��ڵ����ڶ���
    }
};