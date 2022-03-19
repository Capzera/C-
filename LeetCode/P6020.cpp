/*
����������P6020 ���۵�74��˫����
����һ����������?nums?��������?2 * n?��������
����Ҫ��?nums ���ֳ�?n?�����ԣ����㣺
ÿ��Ԫ�� ֻ����һ�� ���ԡ�
ͬһ�����е�Ԫ�� ���?��
������Խ� nums?���ֳ� n?�����ԣ����㷵�� true?�����򷵻� false?��
ʾ�� 1��
���룺nums = [3,2,3,2,2,2]
�����true
���ͣ�
nums?���ܹ��� 6 ��Ԫ�أ���������Ӧ�ñ����ֳ� 6 / 2 = 3 �����ԡ�
nums ���Ի��ֳ� (2, 2) ��(3, 3) �� (2, 2) ����������Ҫ��
ʾ�� 2��
���룺nums = [1,2,3,4]
�����false
���ͣ�
�޷��� nums ���ֳ� 4 / 2 = 2 ����������������Ҫ��
��ʾ��
nums.length == 2 * n
1 <= n <= 500
1 <= nums[i] <= 500
*/
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> um;
        int n=nums.size();
        for (int i:nums) um[i]++;
        unordered_map<int,int>::iterator m=um.begin();
        for (;m!=um.end();m++) if (m->second%2) return false;
        return true;
    }
};