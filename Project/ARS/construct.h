#ifndef _CONSTRUCT_H_
#define _CONSTRUCT_H_

#include "common.h"
#include "menu.h"
#include "pw.h"
#include "passenger.h"

vector<menu> m(15);
static int adminlogin;
static int passlogin;
static int curpass;

void init(){//�˵������ݳ�ʼ��
	m[1].namein("menu1.txt");
	m[2].namein("menu2.txt");
	m[3].namein("menu3.txt");
	m[4].namein("menu4.txt");
	m[5].namein("menu5.txt");
	m[6].namein("menu6.txt");
	m[7].namein("menu7.txt");
	m[8].namein("menu8.txt");
	m[9].namein("menu9.txt");
	painfoin();
	flinfoin();
}

void over(){//�˳�
	system("cls");
	cout<<"��лʹ�ñ�����ϵͳ���ټ���"<<endl;
}

void fllistprint(int index){//������ӡ 0���⣬1����+�б�>1����+ɸѡ
	cout.width(7);
	cout<<std::left<<"�����";
	cout.width(17);
	cout<<std::left<<"���չ�˾";
	cout.width(17);
	cout<<std::left<<"ʼ��ʱ��";
	cout.width(5);
	cout<<std::left<<"Ʊ��";
	cout.width(10);
	cout<<std::left<<"ʼ��վ";
	cout.width(10);
	cout<<std::left<<"�յ�վ";
	cout.width(3);
	cout<<std::left<<"��Ʊ"<<endl;
	if (index==1){
		for (int i=0;i<F.size();i++){
			F[i].show();
		}
		cout<<endl<<endl;
	}
	if (index>1){
		for (int i=0;i<F.size();i++){
			if (F[i].getdate()==index)
				F[i].show();
		}
	}
}

void palistprint(){
	system("cls");
	cout.width(19);
	cout<<std::left<<"���֤��";
	cout.width(9);
	cout<<std::left<<"����";
	cout.width(5);
	cout<<std::left<<"�Ա�";
	cout.width(12);
	cout<<std::left<<"�绰����"<<endl;
	for (int i=0;i<pass.size();i++){
		cout.width(19);
		cout<<std::left<<pass[i].getid();
		cout.width(9);
		cout<<std::left<<pass[i].getname();
		cout.width(5);
		char sex=pass[i].getsex();
		if (sex=='M') cout<<std::left<<" ��";
		else cout<<std::left<<" Ů";
		cout.width(12);
		cout<<std::left<<pass[i].gettel()<<endl;
	}
	getch();
}

void savepa(){//�����û���Ϣ
	system("cls");
	cout<<"���ڱ����û���Ϣ...";
	fstream f("padb.txt",ios::out);
	for (int i=0;i<pass.size();i++){
		string id=pass[i].getid();
		string name=pass[i].getname();
		char sex=pass[i].getsex();
		string tel=pass[i].gettel();
		string pwd=pass[i].getpwd();
		string fl=pass[i].getfl();
		f<<id<<" "<<name<<" "<<sex<<" "<<tel<<" "<<pwd<<" "<<fl;
		if (i!=pass.size()-1) f<<endl;
	}
	f.close();
	Sleep(500);
}

void savefl(){//���溽����Ϣ
	system("cls");
	cout<<"���ڱ��溽����Ϣ...";
	fstream f("fldb.txt",ios::out);
	for (int i=0;i<F.size();i++){
		string id=F[i].getid();
		string company=F[i].getco();
		vector<int> time=F[i].gett();
		int price=F[i].getprice();
		string departure=F[i].getdep();
		string destination=F[i].getdes();
		int rest=F[i].getrest();
		f<<id<<" "<<company<<" ";
		for (int i=0;i<5;i++) f<<time[i]<<" "<<price<<" "<<departure<<" "<<destination<<" ";
		
		if (i!=F.size()-1) f<<rest<<" "<<endl;
		else f<<rest;
	}
	f.close();
	Sleep(500);
}

void pwdchange(){//�޸��û�����
	string pwdin,pwdc;
	while (1){
		pwdin=pwdc="";
		int in=0,flag=1;
		char g=' ';
		while (1){
			system("cls");
			cout<<"�������޸ĺ�����룺";
			for (int i=0;i<in;i++) cout<<"*";
			g=getch();
			if (g==13) break;
			if (g==8){
				if (in){
					in--;
					pwdin.pop_back();
				}
			}
			else {
				in++;
				pwdin.push_back(g);
			}
		}
		flag=pwdcheck(pwdin);
		if (!flag) continue;//���벻���Ϲ淶����������
		in=0,flag=1;
		g=' ';
		while (1){
			system("cls");
			cout<<"������ȷ�����룺";
			for (int i=0;i<in;i++) cout<<"*";
			g=getch();
			if (g==13) break;
			if (g==8){
				if (in){
					in--;
					pwdc.pop_back();
				}
			}
			else {
				in++;
				pwdc.push_back(g);
			}
		}
		flag=pwdcheck(pwdin,pwdc);
		if (flag) break;
	}
	pass[curpass].pwdchange(pwdin);
	savepa();
}

void purc(){//��Ʊ����
	int date=1;
	while (1){
		system("cls");
		fllistprint(1);
		cout<<"������ʼ�����ڣ�";
		cin>>date;
		if (date<20||date>30){
			system("cls");
			cout<<"���ڸ�ʽ����,����������";
			getch();
			continue;
		}
		else break;
	}
	string dep,des;
	while (1){
		system("cls");
		fllistprint(date);
		cout<<"������ʼ���أ�Ŀ�ĵأ��ÿո������";
		cin>>dep>>des;
		int index=-1;
		for (int i=0;i<F.size();i++){
			if (F[i].getdate()==date&&F[i].getdep()==dep&&F[i].getdes()==des){
				index=i;
				break;
			}
		}
		if (index<0){
			system("cls");
			cout<<"�ú���β����ڣ����������룡";
			getch();
			continue;
		}
		else {
			int flag=F[index].purchase();
			if (flag){
				pass[curpass].purchase(index);
				savefl();
				savepa();
				break;
			}
		}
	}
}

int veriid(string idin,vector<int> pur){//�������֤,���ز��鵽�ĺ������
	int flag=-1;
	for (int i=0;i<pur.size();i++){
		if (F[pur[i]].getid()==idin){
			flag=pur[i];
			break;
		}
	}
	return flag;
}

void flinfosearch(){//������Ϣ��ѯ
	vector<int> pur=pass[curpass].showpurchase();
	system("cls");
	if (pur.size()){
		fllistprint(0);
		for (int i=0;i<pur.size();i++) F[pur[i]].show();
	}
	else {
		system("cls");
		cout<<"δ�鵽��Ʊ��¼!";
	}
}

void refund(){//��Ʊ
	vector<int> pur=pass[curpass].showpurchase();
	if (pur.empty()){
		system("cls");
		cout<<"δ�鵽��Ʊ��¼���޷���Ʊ��";
		getch();
		return;
	}
	string idin="";
	int flag=-1;
	while (1){
		system("cls");
		fllistprint(0);
		for (int i=0;i<pur.size();i++) F[pur[i]].show();
		cout<<endl<<"�����뺽��Ž�����Ʊ������";
		cin>>idin;
		flag=veriid(idin,pur);
		if (flag==-1){
			system("cls");
			cout<<"����ĺ�����������������롣";
			getch();
			continue;
		}
		break;
	}
	pass[curpass].refund(flag);
	F[flag].refund();
	system("cls");
	cout<<"��Ʊ�ɹ���";
	getch();
	savefl();
	savepa();
}

void flinfochange(){//�޸ĺ�����Ϣ
	string idin="";
	int flag=-1;
	while (1){
		system("cls");
		fllistprint(1);
		cout<<"��������޸ĵĺ����:";
		cin>>idin;
		vector<int> tmp(30);
		for (int i=0;i<30;i++) tmp[i]=i;
		flag=veriid(idin,tmp);
		if (flag==-1){
			system("cls");
			cout<<"�ú���Ų�����,���������롣";
			getch();
			continue;
		}
		break;
	}
	int date,hour,mini;
	while (1){
		system("cls");
		cout<<"�������޸ĺ��ʼ���գ�ʱ���֣�";
		cin>>date>>hour,mini;
		if (date<20||date>30||hour<0||hour>24||mini<0||mini>60){
			system("cls");
			cout<<"ʱ���ʽ����";
			getch();
			continue;
		}
		break;
	}
	F[flag].timechange(date,hour,mini);
	savefl();
	getch();
}

void start(int index){//���������
	while (1){
		system("cls");
		char ch='z';
		if (index==7) fllistprint(1);
		m[index].showmenu();
		while (ch<'0'||ch>m[index].getsize()) ch=getch();
		if (index!=1&&ch==m[index].getsize()) return;
		if (index==1){
			switch(ch){
				case '1':
					start(2);
				break;
				case '2':
					start(3);
				break;
				case '3':
					over();
					return;
				break;
			}
		}
		else if (index==2){
			switch(ch){
				case '1':
					paregist();
				break;
				case '2':
					start(9);
				break;
			}
		}
		else if (index==3){
			adminlogin=0;
			adlogin(adminlogin);
			system("cls");
			if (adminlogin==1){
				cout<<"��½�ɹ�!"<<endl;
				getch();
				start(8);
				return;
			}
			if (!adminlogin) {
				cout<<"�û�����������󣬵�½ʧ��"<<endl;
				getch();
			}
			
		}
		else if (index==4){
			switch(ch){
				case'1':
					start(5);
				break;
				case'2':
					start(6);
				break;
			}
		}
		else if (index==5){
			switch(ch){
				case '1':
					pass[curpass].show();
				break;
				case '2':
					pwdchange();
					system("cls");
					cout<<"�����޸ĳɹ���";
					getch();
					return;
				break;
			}
		}
		else if (index==6){
			switch(ch){
				case '1':
					start(7);
				break;
				case '2':
					flinfosearch();
					getch();
				break;
				case '3':
					refund();
				break;
			}
		}
		else if (index==7){
			purc();
		}
		else if (index==8){
			switch(ch){
				case '1':
					flinfochange();
				break;
				case '2':
					palistprint();
				break;
			}
		}
		else if (index==9){
			switch(ch){
				case '1':
					passlogin=0;
					curpass=idlogin(passlogin);
					system("cls");
					if (passlogin==1){
						cout<<"��½�ɹ���";
						getch();
						start(4);
						return;
					}
					else if (passlogin==0){
						cout<<"�������";
						getch();
					}
					else {
						cout<<"�����֤�Ų����ڣ�����ע�ᣡ";
						getch();
					}
				break;
				case '2':
					passlogin=0;
					curpass=tellogin(passlogin);
					system("cls");
					if (passlogin==1){
						cout<<"��½�ɹ���";
						getch();
						start(4);
						return;
					}
					else if (passlogin==0){
						cout<<"�������";
						getch();
					}
					else {
						cout<<"���ֻ��Ų����ڣ�����ע�ᣡ";
						getch();
					}
				break;
			}
		}
	}
}


#endif //construct.h
