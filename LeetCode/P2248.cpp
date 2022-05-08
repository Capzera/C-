/*
����������P2248
����һ����ά�������� nums ������ nums[i] ���� ��ͬ ��������ɵ�һ���ǿ����飬
�� �������� ����һ�����飬�����е�ÿ��Ԫ���� nums?�������� �ж����ֹ���
ʾ�� 1��
���룺nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
�����[3,4]
���ͣ�
nums[0] = [3,1,2,4,5]��nums[1] = [1,2,3,4]��nums[2] = [3,4,5,6]���� nums ��ÿ�������ж����ֵ������� 3 �� 4 �����Է��� [3,4] ��
ʾ�� 2��
���룺nums = [[1,2,3],[4,5,6]]
�����[]
���ͣ�
������ͬʱ������ nums[0] �� nums[1] �����������Է���һ�����б� [] ��
��ʾ��
1 <= nums.length <= 1000
1 <= sum(nums[i].length) <= 1000
1 <= nums[i][j] <= 1000
nums[i] �е�����ֵ ������ͬ
*/
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<int> ans;
        set<int> s;
        for (int i:nums[0]) s.insert(i);
        for (int i=1;i<n;i++) {
            set<int> tmp;
            for (int j:nums[i]) tmp.insert(j);
            for (auto x:s){
                if (tmp.find(x)==tmp.end()) s.erase(x);
            }
        }
        ans.assign(s.begin(),s.end());
        return ans;
    }
};