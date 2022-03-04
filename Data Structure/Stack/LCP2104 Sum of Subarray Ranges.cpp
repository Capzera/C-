/*
����������P2104
����һ���������� nums ��nums �У�������� ��Χ �������������Ԫ�غ���СԪ�صĲ�ֵ��
���� nums �� ���� �����鷶Χ�� �� ��
��������������һ������ �ǿ� ��Ԫ�����С�
ʾ�� 1��
���룺nums = [1,2,3]
�����4
���ͣ�nums �� 6 ��������������ʾ��
[1]����Χ = ��� - ��С = 1 - 1 = 0 
[2]����Χ = 2 - 2 = 0
[3]����Χ = 3 - 3 = 0
[1,2]����Χ = 2 - 1 = 1
[2,3]����Χ = 3 - 2 = 1
[1,2,3]����Χ = 3 - 1 = 2
���з�Χ�ĺ��� 0 + 0 + 0 + 1 + 1 + 2 = 4
ʾ�� 2��
���룺nums = [1,3,3]
�����4
���ͣ�nums �� 6 ��������������ʾ��
[1]����Χ = ��� - ��С = 1 - 1 = 0
[3]����Χ = 3 - 3 = 0
[3]����Χ = 3 - 3 = 0
[1,3]����Χ = 3 - 1 = 2
[3,3]����Χ = 3 - 3 = 0
[1,3,3]����Χ = 3 - 1 = 2
���з�Χ�ĺ��� 0 + 0 + 0 + 2 + 0 + 2 = 4
ʾ�� 3��
���룺nums = [4,-2,-3,4,1]
�����59
���ͣ�nums �����������鷶Χ�ĺ��� 59
��ʾ��
1 <= nums.length <= 1000
-109 <= nums[i] <= 109
*/
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> minLeft(n), minRight(n), maxLeft(n), maxRight(n);
        stack<int> minStack, maxStack;
        for (int i = 0; i < n; i++) {
            while (!minStack.empty() && nums[minStack.top()] > nums[i]) {
                minStack.pop();
            }
            minLeft[i] = minStack.empty() ? -1 : minStack.top();
            minStack.push(i);
            
            // ��� nums[maxStack.top()] == nums[i], ��ô���ݶ��壬
            // nums[maxStack.top()] �߼���С�� nums[i]����Ϊ maxStack.top() < i
            while (!maxStack.empty() && nums[maxStack.top()] <= nums[i]) { 
                maxStack.pop();
            }
            maxLeft[i] = maxStack.empty() ? -1 : maxStack.top();
            maxStack.push(i);
        }
        minStack = stack<int>();
        maxStack = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            // ��� nums[minStack.top()] == nums[i], ��ô���ݶ��壬
            // nums[minStack.top()] �߼��ϴ��� nums[i]����Ϊ minStack.top() > i
            while (!minStack.empty() && nums[minStack.top()] >= nums[i]) { 
                minStack.pop();
            }
            minRight[i] = minStack.empty() ? n : minStack.top();
            minStack.push(i);

            while (!maxStack.empty() && nums[maxStack.top()] < nums[i]) {
                maxStack.pop();
            }
            maxRight[i] = maxStack.empty() ? n : maxStack.top();
            maxStack.push(i);
        }

        long long sumMax = 0, sumMin = 0;
        for (int i = 0; i < n; i++) {
            sumMax += static_cast<long long>(maxRight[i] - i) * (i - maxLeft[i]) * nums[i];
            sumMin += static_cast<long long>(minRight[i] - i) * (i - minLeft[i]) * nums[i];
        }
        return sumMax - sumMin;
    }
};