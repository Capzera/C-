/*
����������
��1+2+3+...+n��ֵ��
�����ʽ
�������һ������n��
�����ʽ
���һ�У�����һ����������ʾ1+2+3+...+n��ֵ��
��������
4
�������
10
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,ans=0,sum=1;
    cin>>n;
    sum=(n+1)*n/2;
    ans+=sum;
    printf("%I64d",ans);
    system("pause");
    return 0;
}