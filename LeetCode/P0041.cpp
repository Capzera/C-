/*
����������P0041
����һ��δ������������� nums �������ҳ�����û�г��ֵ���С����������
����ʵ��ʱ�临�Ӷ�Ϊ O(n) ����ֻʹ�ó����������ռ�Ľ��������
ʾ�� 1��
���룺nums = [1,2,0]
�����3
ʾ�� 2��
���룺nums = [3,4,-1,1]
�����2
ʾ�� 3��
���룺nums = [7,8,9,11,12]
�����1
��ʾ��
1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
		set<int> s;
        for (int i:nums) if (i>0) s.insert(i);
        int i=1;
        while (1){
			if (s.find(i++)==s.end()){
				return i-1;
			}
		}
        return 0;
    }
};