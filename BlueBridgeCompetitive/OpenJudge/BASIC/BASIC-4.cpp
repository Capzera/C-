/*
����������
����n�������ҳ���n���������ֵ����Сֵ���͡�
�����ʽ
��һ��Ϊ����n����ʾ���ĸ�����
�ڶ�����n������Ϊ������n������ÿ�����ľ���ֵ��С��10000��
�����ʽ
������У�ÿ��һ����������һ�б�ʾ��Щ���е����ֵ���ڶ��б�ʾ��Щ���е���Сֵ�������б�ʾ��Щ���ĺ͡�
��������
5
1 3 -2 4 5
�������
5
-2
11
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,MIN=INT_MAX,MAX=INT_MIN,sum=0,put;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>put;
        MIN=min(MIN,put);
        MAX=max(MAX,put);
        sum+=put;
    }
    cout<<MAX<<endl;
    cout<<MIN<<endl;
    cout<<sum<<endl;
    system("pause");
    return 0;
}