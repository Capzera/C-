/*
����������P5268 ����������286��
���������±�� 0 ��ʼ���������� nums1 �� nums2 �����㷵��һ������Ϊ 2 ���б� answer �����У�
answer[0] �� nums1 ������ �� ������ nums2 �е� ��ͬ ������ɵ��б�
answer[1] �� nums2 ������ �� ������ nums1 �е� ��ͬ ������ɵ��б�
ע�⣺�б��е��������԰� ���� ˳�򷵻ء�
ʾ�� 1��
���룺nums1 = [1,2,3], nums2 = [2,4,6]
�����[[1,3],[4,6]]
���ͣ�
���� nums1 ��nums1[1] = 2 ������ nums2 ���±� 0 ����Ȼ�� nums1[0] = 1 �� nums1[2] = 3 û�г����� nums2 �С�
��ˣ�answer[0] = [1,3]��
���� nums2 ��nums2[0] = 2 ������ nums1 ���±� 1 ����Ȼ�� nums2[1] = 4 �� nums2[2] = 6 û�г����� nums2 �С�
��ˣ�answer[1] = [4,6]��
ʾ�� 2��
���룺nums1 = [1,2,3,3], nums2 = [1,1,2,2]
�����[[3],[]]
���ͣ�
���� nums1 ��nums1[2] �� nums1[3] û�г����� nums2 �С����� nums1[2] == nums1[3] ��
���ߵ�ֵֻ��Ҫ�� answer[0] �г���һ�Σ��� answer[0] = [3]��
nums2 �е�ÿ���������� nums1 �г��֣���ˣ�answer[1] = [] �� 
��ʾ��
1 <= nums1.length, nums2.length <= 1000
-1000 <= nums1[i], nums2[i] <= 1000
*/
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> um1,um2;
        set<int> tmp1,tmp2;
        vector<vector<int>> ans(2);
        for (int i:nums1) um1[i]++;
        for (int i:nums2) {
            um2[i]++;
            if (um1.find(i)==um1.end()) tmp2.insert(i);
        }
        for (int i:nums1) {
            if (um2.find(i)==um2.end()) tmp1.insert(i);
        }
        ans[0].assign(tmp1.begin(),tmp1.end());
        ans[1].assign(tmp2.begin(),tmp2.end());
        return ans;
    }
};