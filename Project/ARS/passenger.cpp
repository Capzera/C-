#include "passenger.h"

passenger::passenger(){
}

void passenger::infoin(string i,string n,char s,string t,string p,string f) {
	id=i;
	name=n;
	sex=s;
	tel=t;
	pwd=p;
	if (f=="*") return;
	for (int i=0;i<f.size();i++){
		fl+=f[i];
	}
}

void passenger::show(){
	system("cls");
	cout<<"���֤��:"<<id<<endl;
	cout<<"����:"<<name<<endl;
	cout<<"�Ա�:";
	if (sex=='M') cout<<"��"<<endl;
	else cout<<"Ů"<<endl;
	cout<<"�绰:"<<tel<<endl;
	getch();
}

string passenger::getid(){
	return id;
}

string passenger::getname(){
	return name;
}

string passenger::gettel(){
	return tel;
}

string passenger::getpwd(){
	return pwd;
}

char passenger::getsex(){
	return sex;
}

string passenger::getfl(){
	return fl;
}

vector<int> passenger::showpurchase(){
	vector<int> ans;
	if (fl=="*") return ans;
	for (int i=0;i<fl.size();i++){
		ans.push_back(fl[i]-97);
	}
	return ans;
}

void passenger::purchase(int index){
	if (fl=="*") fl="";
	fl+=index+97;
}

void passenger::refund(int index){
	if (fl=="*") {
		system("cls");
		cout<<"��Ʊ���㣬�޷���Ʊ��";
		getch();
		return;
	}
	string ans="";
	for (int i=0;i<fl.size();i++){
		if (fl[i]!=index+97) ans+=fl[i];
	}
	if (ans!="") fl=ans;
	else fl="*";
}

void passenger::pwdchange(string pwdin){
	pwd=pwdin;
}
