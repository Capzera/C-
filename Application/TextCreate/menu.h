#ifndef _MENU_H_
#define _MENU_H_
#include<bits/stdc++.h>
#include "color.h"
#include<conio.h>
#include<fstream>
using namespace std;
const string DAD="D:\\Program\\C++\\";
const vector<string>
    s0={//���˵�
        {"2021��ټ�ѵ"},
        {"�㷨"},
        {"Ӧ��"},
        {"���ű�����"},
        {"���ݽṹ"},
        {"LeeCode"},
        {"���OJ"},
        {"���ݿ�MySQL"},
        {"����"},
        {"Python"},
        {"����C++���Բ���"},
        {"����"}
    },
    s1={//�㷨�ֲ˵�
        {"���ֲ���"},
        {"�����������"},
        {"�����������"},
        {"����"},
        {"˫ָ��"},
        {"��̬�滮"},
        {"̰��"},
        {"��ϣ��"},
        {"�߾���"},
        {"�ݹ�"},
        {"����"},
        {"���������"},
        {"�߶���"},
        {"ģ��"},
        {"��������"},
        {"����"},
        {"�ֵ���"}
    },
    s2={//���ű�ֲ˵�
        {"2013������"},
        {"2021�������̴�ѧУ��"},
        {"����OJ"}
    },
    s3={//���ݽṹ�ֲ˵�
        {"����������"},
        {"���Ա�"},
        {"����"},
        {"����"},
        {"����"},
        {"ջ"},
        {"��"},
    },
    s4={//�������ֲַ˵�
        {"����"},
        {"ѭ���ṹ"},
        {"�������"},
        {"ָ��"},
        {"ѡ��ṹ"},
        {"˳��ṹ"},
        {"�ַ���"},
        {"�ṹ��"},
    },
    s5={//���ű�3���˵�
        {"ALGO"},
        {"BASIC"},
        {"PreTest"},
    },
    s6={//LeetCode�����˵�
        {"���� 100"},
        {"��ָOffer"},
        {"ԭ���"},
    };
class menu
{
public:
    menu(){}
    void strin(vector<string>,int);//����˵��嵥
    void printmenustr();//��ӡ�˵�
    void start(int);//�˵���ʼ
    void select(int,int);//ѡ��ϵͳ
    void textcreate(string);//�ļ�����ϵͳ
    void titlein(string);//��������ϵͳ
    int listsize(vector<string>);//�б���
    ~menu(){}
private:
    vector<string> s;//����˵�
    string title;//�������
    bool listset=0,titleset=0;
};
#include "menu.h"
menu a,b,c,d,e;
int menu::listsize(vector<string> t)//�б���
{
    return t.size();
}
void menu::strin(vector<string> s,int x)//����˵��嵥
{
    if (listset) return;
    int n=s.size();
    for(int i=0;i<n;i++) this->s.push_back(s[i]);
    listset=1;
    if (x==1)this->s.push_back("�˳�");
    else this->s.push_back("����");
}
void menu::titlein(string t)//��������
{
    if (titleset) return;
    this->title=t;
    titleset=1;
}
void menu::printmenustr()//��ӡ�˵�
{
    int i,n=s.size();
    char c;
    for(i=0;i<n;i++) 
    {
        int r=rand()%255,g=rand()%255,b=rand()%255;
        rgb_set(r,g,b);
        if (i<n-1) 
        {
            c=i+65;
            cout<<c<<"-"<<s[i]<<endl;
        }
        else cout<<s[i];
    }
}
void menu::start(int x)//�˵���ʼ
{
    system("cls");
    int n=listsize(s);
    char ch='0';
    while (ch!='.') 
    {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY| FOREGROUND_GREEN);
        cout<<title<<endl;
        printf("\\-----By:�������-----/\n"); 
        printf(" \\--------V1.9-------/\n");
        printmenustr();
        if (ch-96>0&&ch-96<n) 
        {
            select(ch-96,x);
            ch='0';
        }
        else 
        {
            ch=getch();
            if (ch>64&&ch<91) ch+=32;
        }
    }
}
void menu::textcreate(string address)//�ļ�����ϵͳ
{
    fstream File;
    system("cls");
    string str="",swi="";
    int number,times=-1;
    cout<<"��������Ŀ���:";
    cin>>number;
    if (number<0) return;
    if (number<10) times=3;
    else if (number<100) times=2;
    else if (number<1000) times=1;
    for(int i=0;i<times;i++)str.push_back('0');
    swi=to_string(number);
    str+=swi;
    File.open(address+str+".cpp",ios::out);
            File<<"/*"<<endl<<"����������P"<<str<<endl<<endl<<"*/"<<endl;
    File.close();
    system("cls");
    cout<<"P"<<str<<".cpp"<<"������ϣ�"<<endl;
    system("pause");
}
void menu::select(int x,int n)//x���ƽ����ĸ��ӷ��࣬n���Ƶڼ����˵�
{
    menu a,b,c,d,e,f;
    a.strin(s1,2);
    a.titlein("          �㷨");
    b.strin(s2,2);
    b.titlein("         ���ű�");
    c.strin(s3,2);
    c.titlein("        ���ݽṹ");
    d.strin(s4,2);
    d.titlein("        ��������");
    e.strin(s5,2);
    e.titlein("       ���ű����");
    f.strin(s6,2);
    f.titlein("        LeetCode");
    if (n==1)//���˵�
    {
        switch(x)
        {
            case 1:
                textcreate(DAD+"2021SummerHolidayStudy\\P");
            break;
            case 2:
                a.start(2);
            break;
            case 3:
                textcreate(DAD+"Application\\P");
            break;
            case 4:
                b.start(3);
            break;
            case 5:
                c.start(4);
            break;
            case 6:
                f.start(7);
            break;
            case 7:
                textcreate(DAD+"LGOJ\\P");
            break;
            case 8:
                textcreate(DAD+"MySQL\\P");
            break;
            case 9:
                textcreate(DAD+"Project\\P");
            break;
            case 10:
                textcreate(DAD+"Python\\P");
            break;
            case 11:
                d.start(5);
            break;
            case 12:
                textcreate(DAD+"Test\\P");
            break;
        }
    }
    if (n==2)//�㷨
    {
        switch(x)
        {
            case 1:
                textcreate(DAD+"Algorithm\\Binary Search\\LCP");
            break;
            case 2:
                textcreate(DAD+"Algorithm\\Breadth First Search Algorithm\\LCP");
            break;
            case 3:
                textcreate(DAD+"Algorithm\\Depth First Search Algorithm\\LCP");
            break;
            case 4:
                textcreate(DAD+"Algorithm\\Divide and Conquer Algorithm\\LCP");
            break;
            case 5:
                textcreate(DAD+"Algorithm\\Double Pointer\\LCP");
            break;
            case 6:
                textcreate(DAD+"Algorithm\\Dynamic Programming\\LCP");
            break;
            case 7:
                textcreate(DAD+"Algorithm\\Greedy Algorithm\\LCP");
            break;
            case 8:
                textcreate(DAD+"Algorithm\\HashMap\\LCP");  
            break;
            case 9:
                textcreate(DAD+"Algorithm\\HighAccuracy Algorithm\\LCP");
            break;
            case 10:
                textcreate(DAD+"Algorithm\\Recursion Algorithm\\LCP");
            break;
            case 11:
                textcreate(DAD+"Algorithm\\Recursive Algorithm\\LCP");
            break;
            case 12:
                textcreate(DAD+"Algorithm\\Search and Backtracking Algorithm\\LCP");
            break;
            case 13:
                textcreate(DAD+"Algorithm\\Segment Tree\\LCP");
            break;
            case 14:
                textcreate(DAD+"Algorithm\\Simulation\\LCP");
            break;
            case 15:
                textcreate(DAD+"Algorithm\\Sliding Window\\LCP");
            break;
            case 16:
                textcreate(DAD+"Algorithm\\Sorting Algorithm\\LCP");
            break;
            case 17:
                textcreate(DAD+"Algorithm\\Trie Tree\\LCP");
            break;
        }
    }
    if (n==3)//���ű�
    {
        switch(x)
        {
            case 1:
                textcreate(DAD+"BlueBridgeCompetitive\\2013\\P");
            break;
            case 2:
                textcreate(DAD+"BlueBridgeCompetitive\\2021BlueBridgeXPUCompetitive\\P");
            break;
            case 3:
                e.start(6);
            break;
        }
    }
    if (n==4)//���ݽṹ
    {
        switch(x)
        {
            case 1:
                textcreate(DAD+"Data Structure\\Array and Generalized\\LCP");
            break;
            case 2:
                textcreate(DAD+"Data Structure\\Linear List\\LCP");
            break;
            case 3:
                textcreate(DAD+"Data Structure\\LinkList\\LCP");
            break;
            case 4:
                textcreate(DAD+"Data Structure\\Queue\\LCP");
            break;
            case 5:
                textcreate(DAD+"Data Structure\\Sort\\LCP");
            break;
            case 6:
                textcreate(DAD+"Data Structure\\Stack\\LCP");
            break;
            case 7:
                textcreate(DAD+"Data Structure\\Tree\\LCP");
            break;            
        }
    }
    if (n==5)//��������
    {
        switch(x)
        {
            case 1:
                textcreate(DAD+"Statement\\Array\\LCP");
            break;
            case 2:
                textcreate(DAD+"Statement\\Loop Oganization\\LCP");
            break;
            case 3:
                textcreate(DAD+"Statement\\Objects\\LCP");
            break;
            case 4:
                textcreate(DAD+"Statement\\Pointer\\LCP");
            break;
            case 5:
                textcreate(DAD+"Statement\\Selection Oganization\\LCP");
            break;
            case 6:
                textcreate(DAD+"Statement\\Sequential Oganization\\LCP");
            break;
            case 7:
                textcreate(DAD+"Statement\\String\\LCP");
            break;
            case 8:
                textcreate(DAD+"Statement\\Structre\\LCP");
            break;           
        }
    }
    if (n==6)//���ű���
    {
        switch(x)
        {
            case 1:
                textcreate(DAD+"BlueBridgeCompetitive\\OpenJudge\\ALGO\\ALGO-");
            break;
            case 2:
                textcreate(DAD+"BlueBridgeCompetitive\\OpenJudge\\BASIC\\BASIC-");
            break;
            case 3:
                textcreate(DAD+"BlueBridgeCompetitive\\OpenJudge\\PreTest\\PT-");
            break;
        }
    }
    if (n==7)//����
    {
        switch(x)
        {
            case 1:
                textcreate(DAD+"LeetCode\\Hot 100\\Offer-P");
            break;
            case 2:
                textcreate(DAD+"LeetCode\\Sword Finger Offer\\Offer-P");
            break;
            case 3:
                textcreate(DAD+"LeetCode\\P");
            break;
        }
    }
}
#endif