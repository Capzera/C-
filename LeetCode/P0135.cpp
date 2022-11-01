/*
����������P0135
n ������վ��һ�š�����һ���������� ratings ��ʾÿ�����ӵ����֡�
����Ҫ��������Ҫ�󣬸���Щ���ӷַ��ǹ���
ÿ���������ٷ��䵽 1 ���ǹ���
���������������ָ��ߵĺ��ӻ��ø�����ǹ���
�����ÿ�����ӷַ��ǹ������㲢������Ҫ׼���� �����ǹ���Ŀ ��
ʾ��?1��
���룺ratings = [1,0,2]
�����5
���ͣ�����Էֱ����һ�����ڶ��������������ӷַ� 2��1��2 ���ǹ���
ʾ��?2��
���룺ratings = [1,2,2]
�����4
���ͣ�����Էֱ����һ�����ڶ��������������ӷַ� 1��2��1 ���ǹ���
     ����������ֻ�õ� 1 ���ǹ��������������е�����������
��ʾ��
n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
		int n=ratings.size(),ans=0,j;
        if (n<2) return n;
        vector<int> left(n),right(n);
        for (int i=0;i<n;i++){
			if (i&&ratings[i-1]<ratings[i]) left[i]=left[i-1]+1;
            else left[i]=1;
		}
        for (int i=n-1;i>=0;i--){
			if (i<n-1&&ratings[i]>ratings[i+1]) j++;
            else j=1;
            ans+=max(j,left[i]);
		}
        return ans;
    }
};