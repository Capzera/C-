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
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for (int first = 0; first < n; ++first)//ö��a
        {
            // ��Ҫ����һ��ö�ٵ�������ͬ
            if (first > 0 && nums[first] == nums[first - 1]) continue;// c ��Ӧ��ָ���ʼָ����������Ҷ�
            int third = n - 1;
            int target = -nums[first];
            for (int second = first + 1; second < n; ++second)//ö��b
            {
                // ��Ҫ����һ��ö�ٵ�������ͬ
                if (second > first + 1 && nums[second] == nums[second - 1]) continue;// ��Ҫ��֤ b ��ָ���� c ��ָ������
                while (second < third && nums[second] + nums[third] > target) --third;
                // ���ָ���غϣ����� b ���������ӾͲ��������� a+b+c=0 ���� b<c �� c �ˣ������˳�ѭ��
                if (second == third) break;
                if (nums[second] + nums[third] == target) ans.push_back({nums[first], nums[second], nums[third]});
            }
        }
        return ans;
    }
};
