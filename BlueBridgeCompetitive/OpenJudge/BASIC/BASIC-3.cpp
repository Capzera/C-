/*
����������
������ĸ�������һЩ������ͼ�Σ����������һ�����ӣ�
ABCDEFG
BABCDEF
CBABCDE
DCBABCD
EDCBABC
����һ��5��7�е�ͼ�Σ����ҳ����ͼ�εĹ��ɣ������һ��n��m�е�ͼ�Ρ�
�����ʽ
����һ�У�������������n��m���ֱ��ʾ��Ҫ�����ͼ�ε�������������
�����ʽ
���n�У�ÿ��m���ַ���Ϊ���ͼ�Ρ�
��������
5 7
�������
ABCDEFG
BABCDEF
CBABCDE
DCBABCD
EDCBABC
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,i,j;
    cin>>m>>n;
    for(i=0;i<m;i++)
    {
        for(j=0;j<i;j++) 
        {
            if (j==n) break;
            printf("%c",65+i-j);
        }
        for(j=0;j<n-i;j++) printf("%c",65+j);
        cout<<endl; 
    }
    system("pause");
    return 0;
}