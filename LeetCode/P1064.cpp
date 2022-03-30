/*
����������P1064
�����Ѿ��� ���� ���С��ɲ�ͬ������ɵ����� arr���������� arr[i] == i ����С����?i�����������������?i������ -1��
ʾ�� 1��
���룺arr = [-10,-5,0,3,7]
�����3
���ͣ����ڸ��������飬arr[0] = -10��arr[1] = -5��arr[2] = 0��arr[3] = 3��������Ϊ 3 ��
ʾ�� 2��
���룺arr = [0,2,5,8,17]
�����0
���ͣ�arr[0] = 0��������Ϊ 0 ��
ʾ�� 3��
���룺arr = [-10,-5,3,4,7,9]
�����-1
���ͣ������������� i ���� arr[i] = i��������Ϊ -1 ��
��ʾ��
1 <= arr.length < 104
-109 <= arr[i] <= 109
���ף�ʱ�临�Ӷ�Ϊ O(n) �Ľ��������ֱ��Ҳ�ܼ򵥡��������Ƹ��ŵĽ��������
*/
class Solution {
public:
    int fixedPoint(vector<int>& arr) {
		int l=0,r=arr.size(),ans=INT_MAX;
        while (l<r){
			int mid=l+(r-l)/2;
            if (arr[mid]==mid) ans=min(ans,mid);
            if (arr[mid]>=mid) r=mid;
            else l=mid+1;
		}
        return ans==INT_MAX? -1:ans;
    }
};