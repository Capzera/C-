/*
����������P0442
����һ������Ϊ n ���������� nums ������ nums �������������ڷ�Χ [1, n] �ڣ�
��ÿ���������� һ�� �� ���� �������ҳ����г��� ���� ������������������ʽ���ء�
�������Ʋ�ʵ��һ��ʱ�临�Ӷ�Ϊ O(n) �ҽ�ʹ�ó�������ռ���㷨��������⡣
ʾ�� 1��
���룺nums = [4,3,2,7,8,2,3,1]
�����[2,3]
ʾ�� 2��
���룺nums = [1,1,2]
�����[1]
ʾ�� 3��
���룺nums = [1]
�����[]
��ʾ��
n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
nums �е�ÿ��Ԫ�س��� һ�� �� ����
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> hash;
        for (auto i:nums) {
            if (hash.find(i)==hash.end()) hash[i]++;
            else ans.push_back(i);
        }
        return ans;
    }
};