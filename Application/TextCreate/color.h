#ifndef _COLOR_H_
#define _COLOR_H_
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
void rgb_init() {																// ��ʼ��
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);		//������
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);		//������
	DWORD dwInMode, dwOutMode;
	GetConsoleMode(hIn, &dwInMode);						//��ȡ����̨����ģʽ
	GetConsoleMode(hOut, &dwOutMode);					//��ȡ����̨���ģʽ
	dwInMode |= 0x0200;									//����
	dwOutMode |= 0x0004;
	SetConsoleMode(hIn, dwInMode);						//���ÿ���̨����ģʽ
	SetConsoleMode(hOut, dwOutMode);					//���ÿ���̨���ģʽ
}
void rgb_set(int wr,int wg,int wb) {						//����RGB
	printf("\033[38;2;%d;%d;%dm",wr,wg,wb);	//\033[38��ʾǰ����\033[48��ʾ����������%d��ʾ��ϵ���
}
#endif