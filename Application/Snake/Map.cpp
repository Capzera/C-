#include"Map.h"
void Pos(int x, int y);
void HideCursor();

void Map::DrawMap()
{
	system("color 3F");                      //������ɫ
	int i = 0;
	for (i = 20; i < COL_Map + 20; i += 2)   //��ӡ���±߿�ÿ����ռ�����У�
	{
		Pos(i, 5);							 //�������20���Ǵ�ӡ�ڿ���̨���ϣ������5Ҳ���ü�
		printf("��");
		Pos(i, 5 + ROW_Map - 1);
		printf("��");
	}
	for (i = 5; i < ROW_Map + 5; i++)		 //��ӡ���ұ߿�
	{
		Pos(20, i);
		printf("��");
		Pos(20 + COL_Map - 2, i);
		printf("��");
	}
}