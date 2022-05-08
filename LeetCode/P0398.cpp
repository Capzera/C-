/*
����������P0398
����һ�����ܺ��� �ظ�Ԫ�� ����������?nums ������������������Ŀ������?target ������������Լ������������һ�������������С�

ʵ�� Solution �ࣺ
Solution(int[] nums) ������ nums ��ʼ������
int pick(int target) �� nums ��ѡ��һ������ nums[i] == target ��������� i ��
������ڶ����Ч����������ÿ�������ķ��ظ���Ӧ����ȡ�
ʾ����
����
["Solution", "pick", "pick", "pick"]
[[[1, 2, 3, 3, 3]], [3], [1], [3]]
���
[null, 4, 0, 2]
����
Solution solution = new Solution([1, 2, 3, 3, 3]);
solution.pick(3); // ����������� 2, 3 ���� 4 ֮һ��ÿ�������ķ��ظ���Ӧ����ȡ�
solution.pick(1); // ���� 0 ����Ϊֻ�� nums[0] ���� 1 ��
solution.pick(3); // ����������� 2, 3 ���� 4 ֮һ��ÿ�������ķ��ظ���Ӧ����ȡ�
��ʾ��
1 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
target �� nums �е�һ������
������ pick ���� 104 ��
*/
class Solution {
    vector<int> &nums;
public:
    Solution(vector<int> &nums) : nums(nums) {}

    int pick(int target) {
        int ans;
        for (int i = 0, cnt = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                ++cnt;
                if (rand() % cnt == 0) {
                    ans = i;
                }
            }
        }
        return ans;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */