#ifndef _MAP_H_
#define _MAP_H_

#include "common.h"
#include "BLOCK.h"

using namespace std;

class graph{
public:
	graph(){};//���캯��
	void initlocation(int,int);//��ʼ����ͼλ��(ˮƽ��࣬��ֱ���)
	void showmap();//��ӡ��ͼ
	void changechar(char,int);//�ı䷽����Ԫ��
	void changestate(int,int);//�ı䷽����Ԫ�ص���ɫ
	char whattext(int cnt);//���ط������ַ�
	~graph(){};//��������
private:
	int raw=6;
	int len=5;
	Block blocks[30];
	int blockx=70,blocky=70;
};

#endif
