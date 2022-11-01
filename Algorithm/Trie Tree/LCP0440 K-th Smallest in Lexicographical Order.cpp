/*
����������P0440
��������?n?��?k������??[1, n]?���ֵ����?k?С�����֡�
ʾ�� 1:
����: n = 13, k = 2
���: 10
����: �ֵ���������� [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]�����Եڶ�С�������� 10��
ʾ�� 2:
����: n = 1, k = 1
���: 1
��ʾ:
1 <= k <= n <= 109
*/
class Solution {
public:
    int getSteps(int curr, long n) {
        int steps = 0;
        long first = curr;
        long last = curr;
        while (first <= n) {
            steps += min(last, n) - first + 1;
            first = first * 10;
            last = last * 10 + 9;
        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0) {
            int steps = getSteps(curr, n);
            if (steps <= k) {
                k -= steps;
                curr++;
            } else {
                curr = curr*10;
                k--;
            }
        }
        return curr;
    }
};