#include"Food.h"

void Pos(int x, int y);
void HideCursor();

void Food::randfood()
{
    srand((int)time(NULL));//����ʱ�������������ӣ���Ҫctimeͷ�ļ�
Loop:
    pos_x = rand() % (76) + 24;
    pos_y = rand() % (29) + 7;
    if (pos_x % 2)         //���ʳ���x���겻��ż��������ȷ��ʳ�������
        goto Loop;
    Pos(pos_x, pos_y);     //��ȷ�Ϻõ�λ�����ʳ��
    cout << "��";
}
int Food::getFood_x()
{
    return pos_x;
}
int Food::getFood_y()
{
    return pos_y;
}