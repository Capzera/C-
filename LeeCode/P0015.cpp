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
        if (m[0]==0) m.erase(0);
        map<int,int>::iterator m1=m.begin(),m2=m.end();//m2��ָ��
        while(m1->first<0)
        {
            map<int,int>::iterator m2=m.end();
            m2--;
            while(m2->first>0)
            {
                int target=0-m1->first-m2->first;
                if (target<m1->first||target>m2->first)
                {
                }
                else if (target==m1->first&&m1->second==2)//Ŀ��ֵΪ��ָ������ָ��>1
                {
                    temp[0]=temp[1]=m1->first;temp[2]=m2->first;
                    ans.push_back(temp);
                }
                else if (target==m2->first&&m2->second==2)//Ŀ��ֵΪ��ָ������ָ��>1
                {
                    temp[0]=m1->first;temp[1]=temp[2]=m2->first;
                    ans.push_back(temp);
                }
                else if ((target==m1->first&&m1->second<2)||(target==m2->first&&m2->second<2))
                {//Ŀ��ֵ������
                }
                else if (m.find(target)!=m.end())
                {
                    temp[0]=m1->first;temp[1]=target;temp[2]=m2->first;
                    ans.push_back(temp);
                }
                m2--;
            }
            m1++;
        }
        return ans;
    }
};