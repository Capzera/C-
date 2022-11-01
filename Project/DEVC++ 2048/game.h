#ifndef _GAME_H_
#define _GAME_H_

#include "map.h"
#include <vector>
#include <set>
#include <iostream>
#include <stdio.h>

using namespace std;

typedef pair<int,int> pii;

void Pos(int x, int y);

void HideCursor();

class game{
public:
    game();//Ĭ�Ϲ��캯��
    void NewNumber();//�½�����
    void play(int&,char&);//��Ϸ����
    void culempty();//����ո�
    int use2(char);//���й�������2.0
    bool Move(char);//�жϵ�ǰ�����Ƿ����
    void check();//�ж��Ƿ���Բ���
    void over();//��Ϸ����
    ~game(void){};
private:
    vector<pii> New;
    vector<vector<int> > grid;
    vector<vector<int> > index;
    int score;
    int x,y;
    set<char> operable;
};

#endif // _GAME_H_

