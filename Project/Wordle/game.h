#ifndef _GAME_H_
#define _GAME_H_

#include "common.h"
#include "Map.h"

using namespace std;

static string a="";

void init();

class Game{
public:
	Game(){};//���캯��
	void Init();//��ʼ������
	void Start();//��Ϸ���к���
	void Play(char);//��ʼ��Ϸ
	void Judge(int);//�ж���
	void succ();
	void fail();
	~Game(){};
private:
	string Answer;
	int raw,col;
	int cnt;
	graph G;
	bool success;
	bool failure;
};

#endif
