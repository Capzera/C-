#ifndef _PW_H_
#define _PW_H_

#include "common.h"
#include "passenger.h"
#include "flight.h"

extern vector<passenger> pass;
extern vector<administrator> admin;
extern vector<flight> F;

void init();

void flinfoin();//������Ϣ����

int verification(int);//������֤

string passwordinput();//��������

void paregist();//�û�ע��

void painfoin();//�û���Ϣ¼��

int idlogin(int&);//���֤��½

int tellogin(int&);//�绰�����½

void adlogin(int&);//����Ա��½

bool checkid(string);//�������֤��

bool pwdcheck(string);//��������

bool pwdcheck(string,string);//����ȷ������
#endif //pw.h
