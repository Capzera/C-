#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include<ctime>
#include <stdio.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

void Pos(int x, int y);
void HideCursor();

int Menu_Examine = 0;			//�������ƴ�ӡ�˵���ʱ��ֻ��ӡһ�Σ���Ȼ����ѭ����ʱ��һֱ��ӡ
void DrawMenu()					//��ӡ�˵�
{
	void HideCursor();
	if(Menu_Examine==0)
	{ 
		Menu_Examine = 1;
		for (int i = 5; i > 0; i--) printf("\n");
		printf("\t\t\t\t��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��-��\n");
		printf("\t\t\t\t |                                                    |\n");
		printf("\t\t\t\t |    ̰����֮�޵��㽶��Ƥ��֮�̹ſ����֮��ԭʼ��    |\n");
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

void Chioce(int &x)
{
	void HideCursor();
	static char n = '1';
	if (_kbhit())
	{
		char temp = _getch();	//��ʱ����������������ֵ
		if ((n == '1') && (temp == 'w'))
		{
			n = '1';			//ѡ��1����ʱ���������Ϸ�
		}	
		else if ((n == '1') && (temp == 's'))
		{
			n = '2';
		}
		else if ((n == '2') && (temp == 'w'))
		{
			n = '1';
		}
		else if ((n == '2') && (temp == 's'))
		{
			n = '2';			//ѡ��2����ʱ���������·�
		}
		else if ((temp == ' ') && (n == '1'))
		{
			x = 2;				//������Ϸ
			return;
		}
		else if ((temp == ' ') && (n == '2'))
		{
			exit(0);			//�˳�
		}
	}
	switch (n)
	{
	case '1':					//ѡ���ʶ��ѡ��1��
		Pos(52, 10);
		cout << "��";
		Pos(52, 13);
		cout << "  ";
		break;
	case '2':					//ѡ���ʶ��ѡ��2��
		Pos(52, 10);
		cout << "  ";
		Pos(52, 13);
		cout << "��";
		break;
	}
	Sleep(10);				//���ü�����⿴����˸
}