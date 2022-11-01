/*
����������P2149
����һ���±�� 0 ��ʼ���������� nums �����鳤��Ϊ ż�� ������Ŀ��ȵ��������͸�������ɡ�
����Ҫ ���� nums �е�Ԫ�أ�ʹ�޸ĺ��������������������
����?���� ���������� �����෴
���ڷ�����ͬ���������������� ������ nums �е� ˳�� ��
���ź���������������ͷ��
����Ԫ���������������󣬷����޸ĺ�����顣
ʾ�� 1��
���룺nums = [3,1,-2,-5,2,-4]
�����[3,-2,1,-5,2,-4]
���ͣ�
nums �е��������� [3,1,2] ���������� [-2,-5,-4] ��
���ŵ�Ψһ���з����� [3,-2,1,-5,2,-4]������������������
�� [1,-2,2,-5,3,-4]��[3,1,2,-2,-5,-4]��[-2,3,-5,1,-4,2] ���������������ǲ���ȷ�ģ���Ϊ������һ�����߶�������� 
ʾ�� 2��
���룺nums = [-1,1]
�����[1,-1]
���ͣ�
1 �� nums ��Ψһһ����������-1 �� nums ��Ψһһ����������
���� nums ����Ϊ [1,-1] ��
��ʾ��
2 <= nums.length <= 2 * 105
nums.length �� ż��
1 <= |nums[i]| <= 105
nums �� ��� �������������͸��������
*/
//����ѭ��
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans,pos,neg;
        for(int i:nums){
            if (i>0) pos.push_back(i);
            else neg.push_back(i);
        }
        for(int i=0;i<nums.size();i++){
            if (i%2==0) ans.push_back(pos[i/2]);
            else ans.push_back(neg[i/2]);
        }
        return ans;
    }
};
//˫ָ��һ��ѭ��
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int postive=0,negative=0,n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            if (nums[i]>0) {
                ans[postive*2]=nums[i];
                postive++;
            }
            else {
                ans[negative*2+1]=nums[i];
                negative++;
            }
        }
        return ans;
    }
};