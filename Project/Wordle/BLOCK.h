#ifndef _BLOCK_H_
#define _BLOCK_H_
#define IMAGEINIT 0
#define FONT "Consolas"
#include "common.h"

using namespace std;

class Block{
public:
	Block();//���캯��������һ������
	void setstate(int);//�ı䷽��״̬
	void show();//��ʾ����
	void setloc(int ,int);//�ı䷽���λ�á������ú���
	void setchar(char);//�ı䷽�����ַ�
	char whattext();//�����ַ��ӿ�
private:
	char text;//���淽��������
	int state;//���淽��״̬
	int x;//���淽�����꣬��ͬ
	int y;
};

#endif
