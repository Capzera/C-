#pragma once
#include"Map.h"
#include"Food.h"
#include"Snake.h"
Food food;              //ʳ�����
Map map;				//��ͼ����
Snake snake;            //�߶���
int score = 0;          //�÷ֱ���
int sleeptime = 120;	//��Ϸ�ٶ�
int Init_Examine;

void BeginGame(int &x)
{
	if (Init_Examine == 0)
	{
		Init_Examine = 1;
		system("cls");							//���֮ǰ��ӡ�Ĳ˵�
		HideCursor();
		map.DrawMap();							//����ͼ
		food.randfood();						//�������һ��ʳ��
		snake.move(food, score, sleeptime, x);	//���ƶ�
		snake.sleep(score, sleeptime);
	}
	else if (Init_Examine == 1)
	{
		snake.move(food, score, sleeptime, x);	//���ƶ�
		snake.sleep(score, sleeptime);			//��Ϸ�ٶ�
	}
}