#include "MyButton.h"
int main()
{
	srand((unsigned)time(NULL));
	setcaption("��ť����");
    initgraph(-1,-1,INIT_RENDERMANUAL);
	setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
	ege_enable_aa(true);
	/*��ʼ��*/
    RectangleButton R;
    R.newButton(500,600,300,100,"��ʼ��Ϸ");
	R.newButton(1060,600,300,100,"�� ��");
	for (;is_run();delay_fps(144)){
		R.PutButton();
	}
	getch();
	closegraph();
    return 0;
}
