/*
    By��Capzera
    QQ��1786126188
    E-mail��1786126188@qq.com
    ���������ڴ���LeeCode��վ�ϵı���CPP�ļ�������ĿP0001������P0001.cpp�ı����ļ�����ʹ��
*/
#include<bits/stdc++.h>
#include<conio.h>
#include<fstream>
using namespace std;
void menu()
{
    fstream File;
    while (1)
    {
        system("cls");
        string str="",swi="";
        int number,times=-1;
        cout<<"��������Ŀ���(-1):";
        cin>>number;
        if (number<0) break;
        if (number<10) times=3;
        else if (number<100) times=2;
        else if (number<1000) times=1;
        for(int i=0;i<times;i++)str.push_back('0');
        swi=to_string(number);
        str+=swi;
        File.open("D:\\Program\\C++\\LeeCode\\P"+str+".cpp",ios::out);
            cout<<"P"<<str<<":"<<endl;
        File.close();
        system("cls");
        cout<<"P"<<str<<".cpp"<<"������ϣ�"<<endl;
        system("pause");
    }

}
int main(){
    menu();
    system("cls");
    cout<<"��ӭ�´�ʹ�ã��ټ���"<<endl;
    system("pause");
    return 0;
}