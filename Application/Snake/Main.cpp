#include"Menu.h"
#include"BeginGame.h"

//����ȫ�ֺ���
//����������
void Pos(int x, int y)   
{
	COORD pos;  //posΪ�ṹ��
	pos.X = x;  //������
	pos.Y = y;  //������
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);//��ȡ�����������ƹ��
}
//���ع��
void HideCursor()           
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

int main()
{
	system("title ̰����");	//���ô�������
	system("color 3F");		//������ɫ
	static int x = 1;		//��ʼ��ӡ�˵�
	void HideCursor();		//���ع��
	while (true)										//��һ��mp3��ʽ�ļ���������Ŀ¼�¸���Ϊbgm.mp3����
	{
		switch (x)
		{
		case 1:
			DrawMenu();
			Chioce(x);
			Init_Examine = 0;
			break;
		case 2:
			BeginGame(x);
			break;
		}
	}
	system("pause");
	return 0;
}