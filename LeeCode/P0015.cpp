/*
����������
����һ������ n ������������?nums���ж�?nums?���Ƿ��������Ԫ�� a��b��c ��ʹ��?a + b + c = 0 �������ҳ����к�Ϊ 0 �Ҳ��ظ�����Ԫ�顣
ע�⣺���в����԰����ظ�����Ԫ�顣
ʾ�� 1��
���룺nums = [-1,0,1,2,-1,-4]
�����[[-1,-1,2],[-1,0,1]]
ʾ�� 2��
���룺nums = []
�����[]
ʾ�� 3��
���룺nums = [0]
�����[]
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int,int> m;
        int n=nums.size(),i,j,MAX=INT_MIN;
        vector<vector<int>> ans;
        if (n<3) return ans;//���У���������������մ�
        vector<int> temp(3);
        for(i=0;i<n;i++) 
        {
            j=nums[i];
            MAX=max(MAX,j);//�����ֵ
            m[j]++;//��¼�ڹ�ϣ��
            if (m[j]>2&&j!=0) m[j]=2;//����0��ÿ������౻��¼2��
        }
        if (m[0]>2) ans.push_back(temp);//���������3��0��
        if (m[0]>0) m[0]=1;
        map<int,int>::iterator m1=m.begin(),m2=m.begin();
        while (m2!=m.end()&&m2->first<=0) m2++;
        int left=m1->first,right=m2->first;//ѡ��һ�Ը�����������Ѱ�Ҹ����ԵĺͲ���ֵ
        while (left<0&&right<=MAX)
        {
            while(left<0&&m[left]==0) left++;//leftָ��ǰ����
            while(right<=MAX&&m[right]==0) right++;//rightָ��ǰ����
            
        }
        return ans;
    }
};