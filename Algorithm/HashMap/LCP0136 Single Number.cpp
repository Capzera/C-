/*
����������P0136
����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
˵����
����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����
ʾ�� 1:
����: [2,2,1]
���: 1
ʾ��?2:
����: [4,1,2,1,2]
���: 4
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>um;
        int n=nums.size(),i;
        for(i=0;i<n;i++)
        {
            if (um.find(nums[i])==um.end()) um[nums[i]]++;
            else um.erase(nums[i]);
        }
        return um.begin()->first;
    }
};