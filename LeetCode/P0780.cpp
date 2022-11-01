/*
����������P0780
�����ĸ�����?sx?,?sy?��tx?��?ty�����ͨ��һϵ�е�ת�����Դ����?(sx, sy)?�����յ�?(tx, ty)���򷵻� true�����򷵻�?false��
�ӵ�?(x, y)?����ת����?(x, x+y)? ����?(x+y, y)��
ʾ�� 1:
����: sx = 1, sy = 1, tx = 3, ty = 5
���: true
����:
����ͨ������һϵ��ת�������ת�����յ㣺
(1, 1) -> (1, 2)
(1, 2) -> (3, 2)
(3, 2) -> (3, 5)
ʾ�� 2:
����: sx = 1, sy = 1, tx = 2, ty = 2 
���: false
ʾ�� 3:
����: sx = 1, sy = 1, tx = 1, ty = 1 
���: true
��ʾ:
1 <= sx, sy, tx, ty <= 109
*/
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (sx>tx||sy>ty) return false;
        while (tx>=sx&&ty>=sy) {
            if (sx==tx&&sy==ty) return true;
            if (tx>ty) tx-=ty*max((tx-sx)/ty,1);
            else ty-=tx*max((ty-sy)/tx,1);
        }
        return false;
    }
};