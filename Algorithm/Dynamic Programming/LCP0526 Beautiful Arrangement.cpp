/*
����������P0526
�����д� 1 �� n �� n ������������Щ��������һ������ perm���±�� 1 ��ʼ����
ֻҪ������������ ֮һ �����������һ�� ���������� ��
perm[i] �ܹ��� i ����
i �ܹ��� perm[i] ����
����һ������ n �����ؿ��Թ���� �������� �� ���� ��
ʾ�� 1��
���룺n = 2
�����2
���ͣ�
�� 1 �������������� [1,2]��
    - perm[1] = 1 �ܱ� i = 1 ����
    - perm[2] = 2 �ܱ� i = 2 ����
�� 2 �������������� [2,1]:
    - perm[1] = 2 �ܱ� i = 1 ����
    - i = 2 �ܱ� perm[2] = 1 ����
ʾ�� 2��
���룺n = 1
�����1
��ʾ��
1 <= n <= 15
*/
class Solution {
public:
    int countArrangement(int n) {
        vector<int> dp(1<<n);
        dp[0]=1;
        for (int state=0;state<(1<<n);state++) {
            int num=__builtin_popcount(state);
            for (int i=0;i<n;i++) {
                if ((state>>i)&1 && (num%(i+1)==0 || (i+1)%num==0))
                    dp[state]+=dp[state^(1<<i)];
            }
        }
        return dp.back();
    }
};