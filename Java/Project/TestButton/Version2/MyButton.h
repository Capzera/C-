#ifndef _MY_BUTTON_H_
#define _MY_BUTTON_H_

#include <graphics.h>
#include <bits/stdc++.h>

using namespace std;

	static int PressId=-1;
	static int FocusId=-1;
	static int HoverId=-1;

struct ButtonStates {
	bool pressed;	/* ����״̬ */
	bool hovered;	/* ��ͣ״̬ */
	bool focused;	/* ����״̬ */
};

struct Circle{
	unsigned int id;
	int x, y;		/* Բ��*/
	int radius;		/* �뾶*/
	color_t normalColor;
	color_t pressedColor;
	const char* text;
	ButtonStates state;
};

struct RoundRectangle{
	unsigned int id;
	int x, y;
	int width, height;
	float radius;
	color_t normalColor;
	color_t pressdColor;
	const char* text;
	ButtonStates state;
};

struct NormalRectangle{
	unsigned int id;
	int x, y;
	int width, height;
	color_t normalColor;
	color_t pressedColor;
	const char* text;
	ButtonStates state;
};

class CircleButton{
public:
	CircleButton(){};
	void newButton(int,int,int,const char*);//��ʼ��һ���°�ť*
	void initButtonState(struct Circle&);//��ʼ����ť״̬*
	bool insideButton(struct Circle&,int,int);//�ж�xy�Ƿ��ڰ�ť��*
	void DrawButton();//����ť*
	int SearchButton(int,int);//Ѱ��x,y�����ĸ���ť
	color_t interpColor(color_t, color_t, float);//��ɫ
	void PutButton();//��ʾ��ť
	~CircleButton(){};
private:
	vector<struct Circle> button;
	bool redraw=true;
	int xMouse,yMouse;
};

class RectangleButton{
public:
	RectangleButton(){};
	void newButton(int,int,int,int,const char*);//��ʼ�����ΰ�ť
	void initButtonState(struct NormalRectangle&);
	bool insideButton(struct NormalRectangle&,int x,int y);
	void DrawButton();//����ť
	int SearchButton(int,int);//Ѱ��x,y�����ĸ���ť
	color_t interpColor(color_t, color_t, float);//��ɫ
	void PutButton();//��ʾ��ť
	~RectangleButton(){};
private:
	vector<struct NormalRectangle> button;
	bool redraw=true;
	int xMouse,yMouse;
};

#endif
