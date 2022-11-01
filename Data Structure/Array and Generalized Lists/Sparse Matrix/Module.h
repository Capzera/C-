#include<bits/stdc++.h>
#include<conio.h>
#define MAXSIZE 1000
using namespace std;
struct Triple
{
    int row,column,value;
};
struct SparseMatrix
{
    Triple data[MAXSIZE+1];
    int r,c;
    int length;
};
SparseMatrix M,N;
void CreateMatrix(SparseMatrix *M,int i)
{
    char c;
    if (i==1) c='1';
    if (i==2) c='2';
    int m,n,v;
    printf("���������%c���У�\n",c);
    scanf("%d",&m);
    M->r=m;
    system("cls");
    printf("���������%c���У�\n",c);
    scanf("%d",&n);
    M->c=n;
    system("cls");
    printf("���������\n");
    for(m=1; m<=M->r; m++)
    {
        for(n=1; n<=M->c; n++)
        {
            scanf("%d",&v);
            if (v!=0)
            {
                M->length++;
                M->data[M->length].row=m;
                M->data[M->length].column=n;
                M->data[M->length].value=v;
            }
        }
    }
    printf("����%c�����ɹ�\n\n\n\n\n",c);
    system("pause");
    system("cls");
}
void TransMatrix(SparseMatrix M,SparseMatrix *N)
{
    int i,temp,p,q;
    int num[MAXSIZE+1],position[MAXSIZE+1];
    position[1]=1;
    memset(num,0,sizeof(num));
    N->r=M.c;
    N->c=M.r;
    N->length=M.length;
    for(i=1; i<=M.length; i++) num[M.data[i].column]++;
    for(i=2; i<=N->r; i++) position[i]=position[i-1]+num[i-1];
    for(i=1; i<=N->length; i++)
    {
        p=M.data[i].column;
        q=position[p];
        N->data[q].row=M.data[i].column;
        N->data[q].column=M.data[i].row;
        N->data[q].value=M.data[i].value;
        position[p]++;
    }
}
void PrintMatrix(SparseMatrix M)
{
    int i,j;
    int p=1;
    for(i=1;i<=M.r;i++)
    {
        for(j=1;j<=M.c;j++)
        {
            if((i==M.data[p].row)&&(j==M.data[p].column))
            {
                printf("%d ",M.data[p].value);
                p++;
            }
            else printf("0 ");
        }
        printf("\n");
    }
    printf("\n�����ӡ�ɹ�!\n\n");
    system("pause");
    system("cls");
}
void PlusMatrix(SparseMatrix M,SparseMatrix N)
{
    SparseMatrix P;
    int i=0,j=0,t=1,v;
    P.r=M.r;
    P.c=M.c;
    while (i<=M.length&&j<=N.length)
    {
        if (M.data[i].row==N.data[j].row)
        {
            if (M.data[i].column<N.data[j].column)
            {
                P.data[t].row=M.data[i].row;
                P.data[t].column=M.data[i].column;
                P.data[t].value=M.data[i].value;
                t++;
                i++;
            }
            else if (M.data[i].column>N.data[j].column)
            {
                P.data[t].row=N.data[j].row;
                P.data[t].column=N.data[j].column;
                P.data[t].value=N.data[j].value;
                t++;
                j++;
            }
            else
            {
                v=M.data[i].value+N.data[j].value;
                if (v!=0)
                {
                    P.data[t].row=M.data[i].row;
                    P.data[t].column=M.data[i].column;
                    P.data[t].value=v;
                    t++;
                }
                i++;
                j++;
            }
        }
        else if (M.data[i].row<N.data[j].row)
        {
            P.data[t].row=M.data[i].row;
            P.data[t].column=M.data[i].column;
            P.data[t].value=M.data[i].value;
            t++;
            i++;
        }
        else
        {
            P.data[t].row=N.data[j].row;
            P.data[t].column=N.data[j].column;
            P.data[t].value=N.data[j].value;
            t++;
            j++;                
        }
    }
    while (i<=M.length)
    {
        P.data[t].row=M.data[i].row;
        P.data[t].column=M.data[i].column;
        P.data[t].value=M.data[i].value;
        t++;
        i++;
    }
    while (j<=N.length)
    {
        P.data[t].row=N.data[j].row;
        P.data[t].column=N.data[j].column;
        P.data[t].value=N.data[j].value;
        t++;
        j++;
    }
    P.length=t;
    PrintMatrix(P);
}
int Menu()
{
    char ch1;
    int z=0,x;
    ch1='0';
    while(ch1!='4')
    {
        system("cls");
        printf("-----By:�������-----\n");
        printf("��ѡ����Ҫʹ�õĹ���:\n");
        printf("1.����ϡ�����\n");
        printf("2.���ת�þ���\n");
        printf("3.��������\n");
        printf("4.�˳�\n");
        ch1=getch();
        switch(ch1)
        {
            case '1':
                system("cls");
                CreateMatrix(&M,0);
                z=1;
            break;
            case '2':
                system("cls");
                if(!z){
                    printf("�㻹δ����ϡ�����!\n\n\n\n\n");
                    system("pause");
                    break;
                }
                TransMatrix(M,&N);
                PrintMatrix(N);
            break;
            case '3':
                system("cls");
                CreateMatrix(&M,1);
                CreateMatrix(&N,2);
                if ((M.r!=N.r)||(M.c!=N.c))
                {
                    printf("���󣡾������в�ͬ������ӣ�");
                    system("pause");
                    system("cls");
                }
                else PlusMatrix(M,N);
            break;
            case '4':
                system("cls");
                printf("��ӭ�´�ʹ�ã��ټ�...\n\n\n\n\n");
                return 0;
            break;
        }
    }
    return 0;
}