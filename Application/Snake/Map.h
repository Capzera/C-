#pragma once
#include <iostream>
#include <windows.h>
#include <stdio.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
class Map
{
private:
	int ROW_Map = 32;			//��ͼ���д�С;
	int COL_Map = 82;			//��ͼ���д�С;
public:
	void DrawMap();				//����ͼ;
};