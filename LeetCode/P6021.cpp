/*
����������P6021 ���۵�74��˫����
����һ���±�� 0?��ʼ���ַ���?text?����һ���±�� 0?��ʼ�ҳ���Ϊ 2?���ַ���?pattern?�����߶�ֻ����СдӢ����ĸ��
������� text?������λ�ò��� һ�� �ַ������������ַ�������?pattern[0]?����?pattern[1]?��
ע�⣬����ַ����Բ����� text?��ͷ���߽�β��λ�á�
���㷵�ز���һ���ַ���text?�����������ٸ����� pattern?�� ������?��
������ ָ���ǽ�һ���ַ���ɾ�����ɸ��ַ���Ҳ���Բ�ɾ������ʣ���ַ�����ԭ��˳��õ����ַ�����
ʾ�� 1��
���룺text = "abdcdbc", pattern = "ac"
�����4
���ͣ�
��������� text[1] �� text[2] ֮����� pattern[0] = 'a' ����ô���ǵõ� "abadcdbc" ����ô "ac" ��Ϊ�����г��� 4 �Ρ�
�����õ� 4 �� "ac" �����еķ������� "aabdcdbc" �� "abdacdbc" ��
���ǣ�"abdcadbc" ��"abdccdbc" �� "abdcdbcc" ��Щ�ַ�����Ȼ�ǿ��еĲ��뷽��������ֻ������ 3 �� "ac" �����У����Բ������Ž⡣
����֤������һ���ַ����޷��õ����� 4 �� "ac" �����С�
ʾ�� 2��
���룺text = "aabb", pattern = "ab"
�����6
���ͣ�
���Եõ� 6 �� "ab" �����еĲ��ַ���Ϊ "aaabb" ��"aaabb" �� "aabbb" ��
��ʾ��
1 <= text.length <= 105
pattern.length == 2
text ��?pattern?��ֻ����СдӢ����ĸ��
*/
class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long ans0=0,ans1=0,x=0,y=0;
        string tmp="";
        for (auto i:text){
            if (i==pattern[0]) {
                tmp+=i;
                x++;
            }
            else if (i==pattern[1]) {
                tmp+=i;
                y++;
            }
        }
        int n=tmp.length(),cnt=0;
        if (n==1) return 1;
        if (pattern[0]==pattern[1]){
            if (n%2) {//n��ż��������n+1Ϊ����
                ans0=(n+1)/2;
                ans0*=n;
            }
            else {
                ans0=n/2;
                ans0*=n+1;

            }
            return ans0;
        }
        for(int i=n;i>=0;i--) {
            if (i<n&&tmp[i]==pattern[1]) cnt++;
            if (i<n&&tmp[i]==pattern[0]) ans0+=cnt;
        }
        ans0+=y;cnt=0;
        for(int i=0;i<=n;i++) {
            if (i<n&&tmp[i]==pattern[0]) cnt++;
            if (i<n&&tmp[i]==pattern[1]) ans1+=cnt;
        }
        ans1+=x;
        return max(ans0,ans1);
    }
};