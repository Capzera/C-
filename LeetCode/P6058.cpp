/*
����������P6058 ���۵�291������
Alice �ڸ� Bob ���ֻ����֡����ֵ���ĸ�� ��Ӧ?����ͼ��ʾ��
Ϊ�� ���?һ����ĸ��Alice ��Ҫ ��?��Ӧ��ĸ i?�Σ�i?�Ǹ���ĸ�����������������λ�á�
�ȷ�˵��Ϊ�˰�����ĸ?'s'?��Alice ��Ҫ��?'7'?�ĴΡ����Ƶģ� Alice ��Ҫ��?'5'?���εõ���ĸ??'k'?��
ע�⣬����?'0' ��?'1'?��ӳ�䵽�κ���ĸ������?Alice ��?ʹ�����ǡ�
���ǣ����ڴ���Ĵ���Bob û���յ� Alice ���ֵ���ĸ��Ϣ�������յ��� �������ַ�����Ϣ?��
�ȷ�˵��Alice ��������ϢΪ?"bob"?��Bob ���յ��ַ���?"2266622"?��
����һ���ַ���?pressedKeys?����ʾ Bob �յ����ַ��������㷵�� Alice �ܹ����ܷ���������������Ϣ?��
���ڴ𰸿��ܴܺ󣬽�����?109 + 7?ȡ�� �󷵻ء�
ʾ�� 1��
���룺pressedKeys = "22233"
�����8
���ͣ�
Alice ���ܷ�����������Ϣ������
"aaadd", "abdd", "badd", "cdd", "aaae", "abe", "bae" �� "ce" ��
�����ܹ��� 8 �ֿ��ܵ���Ϣ���������Ƿ��� 8 ��
ʾ�� 2��
���룺pressedKeys = "222222222222222222222222222222222222"
�����82876089
���ͣ�
�ܹ��� 2082876103 �� Alice ���ܷ�����������Ϣ��
����������Ҫ���𰸶� 109 + 7 ȡ�࣬�������Ƿ��� 2082876103 % (109 + 7) = 82876089 ��
��ʾ��
1 <= pressedKeys.length <= 105
pressedKeys ֻ��������?'2'?��?'9'?��
*/
class Solution {
public:
    long long ans=1;
    int mod=1e9+7;
    int countTexts(string Keys) {
        int n=Keys.size(),cnt=1;
        char last;
        vector<int> dp3(4),dp4(5);
        dp3[1]=dp4[1]=1;
        dp3[2]=dp4[2]=2;
        dp3[3]=dp4[3]=4;
        dp4[4]=8;
        last=Keys[0];
        for (int i=1;i<n;i++) {
            if (Keys[i]==last) {
                cnt++;
                if (last=='7'||last=='9') {
                    if (cnt==dp4.size()) {
                        int tmp=(((dp4[cnt-1]+dp4[cnt-2])%mod+dp4[cnt-3])%mod+dp4[cnt-4])%mod;
                        dp4.push_back(tmp);
                    }
                }
                else {
                    if (cnt==dp3.size()) {
                        int tmp=((dp3[cnt-1]+dp3[cnt-2])%mod+dp3[cnt-3])%mod;
                        dp3.push_back(tmp);
                    }
                }
            }
            if (Keys[i]!=last||i==n-1) {
                if (last=='7'||last=='9') ans=ans*dp4[cnt]%mod;
                else ans=ans*dp3[cnt]%mod;
                last=Keys[i];
                cnt=1;
            }
        }
        
        return ans;
    }
};
/*


*/