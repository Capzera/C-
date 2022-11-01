#pragma once
#include<vector>
#include <conio.h>
#include"Food.h"
#include <Psapi.h>
#pragma comment(lib, "Psapi.lib")
void Pos(int x, int y);
void HideCursor();
class Snake
{
private:
    struct Snakepoint
    {
        int x;  //�ڼ���
        int y;  //�ڼ���
    };
    vector<Snakepoint> snakepoint;

    char Direction;                                         //�����ߵķ���
    void Show_information(int& score, int& sleeptime);      //��ӡ��Ϣ
    void overout(const int score);                          //��Ϸ������ʾ
    void Gameover(int& score,int &x);                       //��Ϸ����
    void Control(Snakepoint& nexthead);                     //���Ʒ���

public:
    Snake();                                                //���캯��
    void move(Food& food, int& score, int& sleeptime,int& x);//���ƶ�����ӡ����
    void sleep(int& score, int& sleeptime);                 //���ݷ���������Ϸ�ٶ�
};