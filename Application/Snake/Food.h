#pragma once
#include <ctime>
#include "Map.h"
class Food
{
private:
    int pos_x;
    int pos_y;
public:
    void randfood();          //�������һ��ʳ��
    int getFood_x();          //����ʳ���x����
    int getFood_y();          //����ʳ���y����
};