#include "Menu.h"

using namespace std;

void Drawmenu()
{
	if(Menu_Examine==0)
	{
		Menu_Examine = 1;
		for (int i = 5; i > 0; i--) printf("\n");
		printf("\t\t\t\t        ��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��\n");
		printf("\t\t\t\t |                                                    |\n");
		printf("\t\t\t\t |                      2048PC��                      |\n");
		printf("\t\t\t\t |                                                    |\n");
		printf("\t\t\t\t |                                                    |\n");
		printf("\t\t\t\t |                      ��ʼ��Ϸ                      |\n");
		printf("\t\t\t\t |                                                    |\n");
		printf("\t\t\t\t |                                                    |\n");
		printf("\t\t\t\t |                      �˳���Ϸ                      |\n");
		printf("\t\t\t\t |                                                    |\n");
		printf("\t\t\t\t |                                                    |\n");
		printf("\t\t\t\t |                                                    |\n");
		printf("\t\t\t\t��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��\n");
		printf("\t\t\t\t                                    wasd���ƣ�spaceѡ��\n");
		printf("\t\t\t\t                                        ������:�������\n");
		}
}

void choice(int x) {
    void HideCursor();
    static char c='1';
    if (_kbhit()){
        char tmp=_getch();
        if (c=='1'&&tmp=='s')
            c='2';
        if (c=='2'&&tmp=='w')
            c='1';
        if (c=='1'&&tmp==' ')
            x=2;
            return;
        if (c=='2'&&tmp==' ')
            exit(0);
    }
    return;
}
