/*
����������P0279
����һ������ n ������ ��Ϊ n ����ȫƽ�������������� ��
��ȫƽ���� ��һ����������ֵ������һ��������ƽ�������仰˵����ֵ����һ�������Գ˵Ļ���
���磬1��4��9 �� 16 ������ȫƽ�������� 3 �� 11 ���ǡ�
ʾ��?1��
���룺n = 12
�����3 
���ͣ�12 = 4 + 4 + 4
ʾ�� 2��
���룺n = 13
�����2
���ͣ�13 = 4 + 9
��ʾ��
1 <= n <= 104
*/

//��̬�滮 �㷨ʱ�临�Ӷ�O��n^1.5�� �ռ临�Ӷ�O(N)��
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        int power=2;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            if (i==power*power)
            {
                power++;
                dp[i]=1;
            }
            else
            {
                dp[i]=INT_MAX;
                for(int j=1;j<power;j++)
                {
                    dp[i]=min(dp[i],dp[i-j*j]+1);
                }
            }
        }
        return dp[n];
    }
};
//��ѧ�㷨������ƽ���Ͷ��� ʱ�临�Ӷ�O��n^0.5�� �ռ临�Ӷ�O��1��
class Solution {
public:
    // �ж��Ƿ�Ϊ��ȫƽ����
    bool isPerfectSquare(int x) {
        int y = sqrt(x);
        return y * y == x;
    }

    // �ж��Ƿ��ܱ�ʾΪ 4^k*(8m+7)
    bool checkAnswer4(int x) {
        while (x % 4 == 0) {
            x /= 4;
        }
        return x % 8 == 7;
    }

    int numSquares(int n) {
        if (isPerfectSquare(n)) {
            return 1;
        }
        if (checkAnswer4(n)) {
            return 4;
        }
        for (int i = 1; i * i <= n; i++) {
            int j = n - i * i;
            if (isPerfectSquare(j)) {
                return 2;
            }
        }
        return 3;
    }
};
//