#ifndef _MAP_def_H_
#define _MAP_def_H_

#include<iostream>
#include<vector>

using namespace std;

void HideCursor();

void Pos(int x,int y);

class Map
{
public:
    Map(){};//Ĭ�Ϲ��캯��

    Map(vector<vector<int> >,int);//���ƹ��캯��
    void printmap();//��ӡ��ͼ������
    int getlen(int);//��ȡ���ֳ����Ծ���
    void drawmap();//��ӡ��ͼģ��
    void change(vector<vector<int> >,int);//����map������
    void change(vector<vector<int> >);
    void setnew(int ,int);//���������ֵ�
    ~Map(void){};
private:
    vector<vector<int> > grid;
    int score;
    int x;
    int y;
};
#endif // _MAP_H_

