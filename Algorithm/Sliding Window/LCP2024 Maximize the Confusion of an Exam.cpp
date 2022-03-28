/*
����������P2024
һλ��ʦ���ڳ�һ���� n?���ж��⹹�ɵĿ��ԣ�ÿ����Ĵ�Ϊ true ���� 'T' ��ʾ������ false ���� 'F'?��ʾ����
��ʦ������ѧ�����Լ������𰸵Ĳ�ȷ���ԣ�������?���?�� ������ͬ?�������������Ҳ������������ true ������������ false����
����һ���ַ���?answerKey?������?answerKey[i]?�ǵ� i?���������ȷ�����
�������⣬������һ������ k?����ʾ���ܽ������²�������������
ÿ�β����У����������ȷ�𰸸�Ϊ?'T' ����?'F'?��Ҳ���ǽ� answerKey[i] ��Ϊ?'T'?����?'F'?����
���㷵���ڲ����� k?�β���������£����?���� 'T'?���� 'F'?����Ŀ��
ʾ�� 1��
���룺answerKey = "TTFF", k = 2
�����4
���ͣ����ǿ��Խ����� 'F' ����Ϊ 'T' ���õ� answerKey = "TTTT" ��
�ܹ����ĸ������� 'T' ��
ʾ�� 2��
���룺answerKey = "TFFT", k = 1
�����3
���ͣ����ǿ��Խ���ǰ��� 'T' ���� 'F' ���õ� answerKey = "FFFT" ��
���ߣ����ǿ��Խ��ڶ��� 'T' ���� 'F' ���õ� answerKey = "TFFF" ��
��������£��������������� 'F' ��
ʾ�� 3��
���룺answerKey = "TTFTTFTT", k = 1
�����5
���ͣ����ǿ��Խ���һ�� 'F' ���� 'T' ���õ� answerKey = "TTTTTFTT" ��
�������ǿ��Խ��ڶ��� 'F' ���� 'T' ���õ� answerKey = "TTFTTTTT" ��
��������£�������������� 'T' ��
��ʾ��
n == answerKey.length
1 <= n <= 5 * 104
answerKey[i]?Ҫô��?'T' ��Ҫô��?'F'
1 <= k <= n
*/
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size(),ans=0;
        vector<int> sum(n+1);
        for (int i=1;i<=n;i++) sum[i]=sum[i-1]+(answerKey[i-1]=='T'? 1:0);
        int l=0,r=n+1,mid;
        while (l<r) {
            mid=l+(r-l)/2;
            bool check=false;
            for (int i=0;i<n-mid+1;i++) {
                if (min(sum[i+mid]-sum[i],mid-sum[i+mid]+sum[i])<=k) {
                    ans=mid;
                    check=1;
                    break;
                }
            }
            if (!check) r=mid;
            else l=mid+1;
        }
        return ans;
    }
};