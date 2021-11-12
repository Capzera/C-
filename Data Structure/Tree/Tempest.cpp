#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
typedef struct Node
{
	char data;
	Node *LChild,*RChild;
}*BiTree;
BiTree T;
int Total=0;
void CreateTree(BiTree T,char c)
{
	char A;
	T->LChild=(Node *)malloc(sizeof(Node));
	T->RChild=(Node *)malloc(sizeof(Node));
    system("cls");
	printf("������%c������:",c);
	A=getch();
	if ((A<'A')||(A>'Z'))
	{
		T->LChild=NULL;
	}
	else
	{
		T->LChild->data=A;
        Total++;
		CreateTree(T->LChild,A);
	}
    system("cls");
	printf("������%c���ҽ��:",c);
	A=getch();
	if ((A<'A')||(A>'Z'))
	{
		T=T->RChild=NULL;
		return ;
	}
	else
	{
		T->RChild->data=A;
        Total++;
		CreateTree(T->RChild,A);
	}
	
}

void PreOrder(BiTree T)
{
	if (T!=NULL)
	{
		printf("%c",T->data);
		PreOrder(T->LChild);
		PreOrder(T->RChild);
	}
}

void InOrder(BiTree T)
{
	if (T!=NULL)
	{
		InOrder(T->LChild);
		printf("%c",T->data);
		InOrder(T->RChild);
	}
}

void PostOrder(BiTree T)
{
	if (T!=NULL)
	{
		PostOrder(T->LChild);
		PostOrder(T->RChild);
		printf("%c",T->data);
	}
}

void PrintTree(BiTree T,int type,int Depth)
{
	int i;
	if (T==NULL) return ;
	PrintTree(T->RChild,2,Depth+1);
	switch (type)
	{
		case 0:
			printf("%2c\n",T->data);
		break;
		case 1:
			for (i=1; i<=Depth; i++) printf("\t");
			printf("\\\n");
			for (i=1; i<=Depth; i++) printf("\t");
			printf("  %2c\n",T->data); 
		break;
		case 2:
			for (i=1; i<=Depth; i++) printf("\t");
			printf("  %2c\n",T->data);
			for (i=1; i<=Depth; i++) printf("\t");
			printf("/\n");
		break;
	}
	PrintTree(T->LChild,1,Depth+1);
}
int check(int i)
{
    if (!i)
    {
        printf("�㻹δ����������!\n\n\n\n\n");
        system("pause");       
        return 0;
    }
    else return 1;
}
int Menu()
{
    char ch1,X;
    int z=0,x;
    ch1='0';
    while(ch1!='7')
    {
        system("cls");
        printf("-----By:�������-----\n");
        printf("��ѡ����Ҫʹ�õĹ���:\n");
        printf("1.����������\n");
        printf("2.����������������\n");
        printf("3.����������������\n");
        printf("4.����������������\n");
        printf("5.�������������ͼ\n");
        printf("6.����������������\n");
        printf("7.�˳�\n");
        ch1=getch();
        switch(ch1)
        {
            case '1':
                system("cls");
	            printf("������������ĸ��ڵ�:");
	            X=getch();
                system("cls");
	            if ((X>='A')&&(X<='Z'))
	            {
		            T=(BiTree)malloc(sizeof(BiTree));
                    T->data=X;
                    Total++;
                    CreateTree(T,X);
                    system("cls");
                    printf("�����ɹ���\n\n\n\n\n");
                    z=1;
	            }
                else printf("���ڵ�Ƿ�������ʧ�ܣ�\n\n\n\n\n");
                system("pause");
            break;
            case '2':
                system("cls");
                if(!check(z)) break;
                printf("�������Ϊ��");
                PreOrder(T);
                printf("\n\n\n\n\n");
                system("pause");
            break;
            case '3':
                system("cls");                
                if(!check(z)) break;
                printf("�������Ϊ��");
                InOrder(T);
                printf("\n\n\n\n\n");
                system("pause");
            break;
            case '4':
                system("cls");
                if(!check(z)) break;
                printf("�������Ϊ��");
                PostOrder(T);
                printf("\n\n\n\n\n");
                system("pause");
            break;
            case '5':
                system("cls");
                if(!check(z)) break;
                PrintTree(T,0,0);
                system("pause");
            break;
            case '6':
                system("cls");
                if(!check(z)) break;
                printf("����%d����㡣\n\n\n\n\n",Total);
                system("pause");
            break;
        }
    }
    system("cls");
    printf("��ӭ�´�ʹ�ã��ټ�...\n\n\n\n\n");
    return 0;
}
int main()
{
	Menu();
	system("pause");
	return 0;
}