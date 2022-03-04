/*
����������P278
���ǲ�Ʒ����Ŀǰ���ڴ���һ���Ŷӿ����µĲ�Ʒ�����ҵ��ǣ���Ĳ�Ʒ�����°汾û��ͨ��������⡣
����ÿ���汾���ǻ���֮ǰ�İ汾�����ģ����Դ���İ汾֮������а汾���Ǵ�ġ�
�������� n ���汾 [1, 2, ..., n]�������ҳ�����֮�����а汾����ĵ�һ������İ汾��
�����ͨ������?bool isBadVersion(version)?�ӿ����жϰ汾�� version �Ƿ��ڵ�Ԫ�����г���
ʵ��һ�����������ҵ�һ������İ汾����Ӧ�þ������ٶԵ��� API �Ĵ�����
ʾ�� 1��
���룺n = 5, bad = 4
�����4
���ͣ�
���� isBadVersion(3) -> false 
���� isBadVersion(5)?-> true 
���� isBadVersion(4)?-> true
���ԣ�4 �ǵ�һ������İ汾��
ʾ�� 2��
���룺n = 1, bad = 1
�����1
*/
// The API isBadVersion is defined for you.
bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) {
        int l=1,r=n,mid=1+(n-1)/2;
        while (l<r)
        {
            if (isBadVersion(mid)) r=mid;
            else l=mid+1;
            mid=l+(r-l)/2;
        }
        return mid;
    }
};