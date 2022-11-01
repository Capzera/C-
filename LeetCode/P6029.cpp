/*
����������P6029 ���۵�285������
Alice �� Bob ��һ����������еĶ��֡������������£�

Alice ���� numArrows ֧����Ȼ�� Bob Ҳ�� numArrows ֧����
����������������㣺
���������������Ʒ����򣬷�Χ�� 0 �� 11 ���� 0 �� 11����
������ÿ�����򶼶�Ӧһ���÷� k����Χ�� 0 �� 11����Alice �� Bob �ֱ��ڵ÷� k �������� ak �� bk ֧������� ak >= bk ����ô Alice �� k �֡���� ak < bk ���� Bob �� k ��
��� ak == bk == 0 ����ô���˵õ� k �֡�
���磬Alice �� Bob ����Ʒ�Ϊ 11 �������� 2 ֧������ô Alice �� 11 �֡�
��� Alice ��Ʒ�Ϊ 11 �������� 0 ֧������ Bob ��ͬһ�������� 2 ֧������ô Bob �� 11 �֡�
�������� numArrows ��һ������Ϊ 12 ���������� aliceArrows ���������ʾ Alice ���� 0 �� 11 ÿ���Ʒ�����ļ�������
���ڣ�Bob ��Ҫ������ ��� �����ܻ�õ��ܷ֡�
�������� bobArrows ���������ʾ Bob ���� 0 �� 11 ÿ�� �Ʒ�����ļ��������� bobArrows ���ܺ�Ӧ������ numArrows ��
������ڶ��ַ���������ʹ Bob �������ܷ֣��������� ����һ�� ���ɡ�
ʾ�� 1��
���룺numArrows = 9, aliceArrows = [1,1,0,1,0,0,2,1,0,1,2,0]
�����[0,0,0,0,1,1,0,0,1,2,3,1]
���ͣ��ϱ���ʾ�˱����÷������
Bob ����ܷ� 4 + 5 + 8 + 9 + 10 + 11 = 47 ��
����֤�� Bob �޷���ñ� 47 ���ߵķ�����
ʾ�� 2��
���룺numArrows = 3, aliceArrows = [0,0,1,0,0,0,0,0,0,0,0,2]
�����[0,0,0,0,0,0,0,0,1,1,1,0]
���ͣ��ϱ���ʾ�˱����÷������
Bob ����ܷ� 8 + 9 + 10 = 27 ��
����֤�� Bob �޷���ñ� 27 ���ߵķ�����
��ʾ��
1 <= numArrows <= 105
aliceArrows.length == bobArrows.length == 12
0 <= aliceArrows[i], bobArrows[i] <= numArrows
sum(aliceArrows[i]) == numArrows
*/
class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int>bobArrows(12);
        int ans=-1;
        for (int i=0;i<(1<<12);i++) {
            int tot=0,score=0;
            for (int j=0;j<12;j++)
                if (i>>j&1) {
                    tot+=aliceArrows[j]+1;
                    score+=j;
                }
            if (tot<=numArrows&&score>ans){
                ans=score;
                for (int j=0;j<12;j++) {
                    if (i>>j&1) bobArrows[j]=aliceArrows[j]+1;
                    else bobArrows[j]=0;
                }
                bobArrows[0]+=numArrows-tot;
            }
        }
        return bobArrows;
    }
};