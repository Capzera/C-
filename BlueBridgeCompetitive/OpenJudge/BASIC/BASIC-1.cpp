/*
����������
����һ����ݣ��ж���һ���ǲ������ꡣ
���������֮һ����ʱ����һ�������꣺
1. �����4�ı���������100�ı�����
2. �����400�ı�����
��������ݶ��������ꡣ
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int year;
    cin>>year;
    if ((year%4==0&&year%100!=0)||year%400==0) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    system("pause");
    return 0;
}