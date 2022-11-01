/*
����������P2120
����һ�� n x n ��С���������Ͻǵ�Ԫ������ (0, 0) �����½ǵ�Ԫ������ (n - 1, n - 1) ��
�������� n ��һ���������� startPos ������ startPos = [startrow, startcol] 
��ʾ�������ʼ������Ϊ (startrow, startcol) �ĵ�Ԫ���ϡ�
�����һ������Ϊ m ���±�� 0 ��ʼ���ַ��� s ������ s[i] �ǶԻ����˵ĵ� i ��ָ�
'L'�������ƶ�����'R'�������ƶ�����'U'�������ƶ����� 'D'�������ƶ�����
�����˿��Դ� s �е���һ�� i ��ָ�ʼִ�С�����������ִ��ָ��ֱ�� s ��ĩβ������������������֮һʱ�������˽���ֹͣ��
��һ��ָ��ᵼ�»������ƶ��������⡣
û��ָ�����ִ�С�
����һ������Ϊ m ������ answer ������ answer[i] �ǻ����˴ӵ� i?��ָ�� ��ʼ?������ִ�е� ָ����Ŀ ��
ʾ�� 1��
���룺n = 3, startPos = [0,1], s = "RRDDLU"
�����[1,5,4,3,1,0]
���ͣ������˴� startPos ���������ӵ� i ��ָ�ʼִ�У�
- 0: "RRDDLU" ���ƶ���������֮ǰ��ֻ��ִ��һ�� "R" ָ�
- 1:  "RDDLU" ����ִ��ȫ������ָ����������������ڣ����յ��� (0, 0) ��
- 2:   "DDLU" ����ִ��ȫ������ָ����������������ڣ����յ��� (0, 0) ��
- 3:    "DLU" ����ִ��ȫ������ָ����������������ڣ����յ��� (0, 0) ��
- 4:     "LU" ���ƶ���������֮ǰ��ֻ��ִ��һ�� "L" ָ�
- 5:      "U" ��������ƶ��������ƶ��������⡣
ʾ�� 2��
���룺n = 2, startPos = [1,1], s = "LURD"
�����[4,1,0,0]
���ͣ�
- 0: "LURD"
- 1:  "URD"
- 2:   "RD"
- 3:    "D"
ʾ�� 3��
���룺n = 1, startPos = [0,0], s = "LRUD"
�����[0,0,0,0]
���ͣ����ۻ����˴�����ָ�ʼִ�У������ƶ��������⡣
��ʾ��
m == s.length
1 <= n, m <= 500
startPos.length == 2
0 <= startrow, startcol < n
s �� 'L'��'R'��'U' �� 'D' ���
*/
class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int len=s.size();
        vector<int> ans(len);
        for(int i=0;i<len;i++){
            int step=0;
            int xpos=startPos[0],ypos=startPos[1];
            for (int j=i;j<len;j++){
                switch(s[j]){
                    case 'L': ypos--;
                    break;
                    case 'U': xpos--;
                    break;
                    case 'R': ypos++;
                    break;
                    case 'D': xpos++;
                    break;
                }
                if (xpos>-1&&ypos>-1&&xpos<n&&ypos<n) step++;
                else break;
            }
            ans[i]=step;
        }
        return ans;
    }
};