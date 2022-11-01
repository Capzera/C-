/*
����������P0870
����������С��ȵ�����?A?��?B��A ����� B �����ƿ���������?A[i] > B[i]?������ i?����Ŀ��������
����?A?���������У�ʹ������� B?��������󻯡�
ʾ�� 1��
���룺A = [2,7,11,15], B = [1,10,4,11]
�����[2,11,7,15]
ʾ�� 2��
���룺A = [12,24,8,32], B = [13,25,32,11]
�����[24,32,8,12]
��ʾ��
1 <= A.length = B.length <= 10000
0 <= A[i] <= 10^9
0 <= B[i] <= 10^9
*/
class Solution {
public:
    static bool cmp(const pair<int,int>& a,const pair<int,int>& b) {
        return a.first<b.first;
    }
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),l=0,r=n-1;
        vector<int> ans(n);
        vector<pair<int,int>> index;
        for (int i=0;i<n;i++) index.push_back({nums2[i],i});//����{ֵ������}��ֵ��
        sort(index.begin(),index.end(),cmp);//��index��ֵ����
        sort(nums1.begin(),nums1.end());//��nums1����
        for (int i=0;i<n;i++) {
            if (nums1[i]>index[l].first) {//���a�����µȿ��Դ�Ӯ
                ans[index[l++].second]=nums1[i];//�����Ǵ�
            }
            else ans[index[r--].second]=nums1[i];//��a���µȵ�ȥ��b��ǿ��
        }
        return ans;
    }
};