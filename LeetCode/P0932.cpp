/*
����������P0932
����ĳЩ�̶���?N���������?A?������?1, 2, ..., N?��ɵ����У�ʹ�ã�
����ÿ��?i < j����������?k ����?i < k < j?ʹ��?A[k] * 2 = A[i] + A[j]��
��ô���� A?��Ư�����顣
����?N����������Ư������?A����֤����һ������
ʾ�� 1��
���룺4
�����[2,1,4,3]
ʾ�� 2��
���룺5
�����[3,1,2,5,4]
��ʾ��
1 <= N <= 1000
*/
class Solution {
public:
    unordered_map<int,vector<int>> um;
    vector<int> beautifulArray(int n) {
        if (n==1) return {1};
        if (um.count(n)) return um[n];
        int mid=(n+1)/2;
        vector<int> left=beautifulArray(mid);
        vector<int> right=beautifulArray(n-mid);
        vector<int> ans;
        for (int i:left) ans.push_back(2*i-1);
        for (int i:right) ans.push_back(2*i);
        um[n]=ans;
		return ans;
    }
};