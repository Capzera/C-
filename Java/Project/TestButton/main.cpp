#include "MyButton.h"
int main()
{
	setcaption("��ť����");
    initgraph(-1,-1,INIT_RENDERMANUAL);
	setbkcolor(WHITE);
	setbkmode(TRANSPARENT);
	ege_enable_aa(true);
	/*��ʼ��*/
	CircleButton C;
	C.newButton(600,700,100,"��ʼ��Ϸ");
	C.newButton(1200,700,100,"�˳���Ϸ");
    RectangleButton R;
    R.newButton(800,600,1100,700,"��ʼ��Ϸ");
	for (;is_run();delay_fps(144)){
		R.RectangleButton::PutButton();
	}
	getch();
	closegraph();
    return 0;
}
