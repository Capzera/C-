/*
����������
Fibonacci���еĵ��ƹ�ʽΪ��Fn=Fn-1+Fn-2������F1=F2=1��
��n�Ƚϴ�ʱ��FnҲ�ǳ�������������֪����Fn����10007�������Ƕ��١�
�����ʽ
�������һ������n��
�����ʽ
���һ�У�����һ����������ʾFn����10007��������
��������
10
�������
55
��������
22
�������
7704
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if (n==1) cout<<1;
    else if (n==2) cout<<1;
    else
    {
        int x=1,y=1,sum=0;
        for(int i=3;i<=n;i++)
        {
            sum=(x+y)%10007;
            x=y;
            y=sum;
        }
        cout<<sum;
    }
    system("pause");
    return 0;
}