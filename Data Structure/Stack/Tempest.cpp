#include<bits/stdc++.h>
#include<conio.h>
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100000
using namespace std;
typedef struct Node{
    int data;
    struct Node *next;
}Node,* LStack;
void InitStack(LStack *S)
{
    *S=(LStack)malloc(sizeof(Node));
    (*S)->next=NULL;
}
int PushStack(LStack S,int x)
{
    Node *p;
    p=(LStack)malloc(sizeof(Node)*MAXSIZE+1);
    if(p==NULL) return (FALSE);
    p->data=x;
    p->next=S->next;
    S->next=p;
    return (TRUE);
}
int PopStack(LStack S)
{
    Node *r;
    r=S->next;
    if(r==NULL) return (FALSE);
    S->next=r->next;
    free(r);
    return (TRUE);
}0
void CreateStack(LStack S)
{
    Node *p;
    int i,n,x;
    printf("����������Ҫ��ջ��Ԥ�ü���Ԫ��:");
    scanf("%d",&n);
    system("cls");
    printf("���ÿո���������%d����:\n",n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        PushStack(S,x);
    }
    system("cls");
    printf("ջ�����ɹ���\n\n\n\n\n");
    system("pause");
}
void PrintStack(LStack S)
{
    int i=0;
    Node *p;
    p=S->next;
    while (1==1)
    {
        i++;
        printf("%d ",p->data);
        p=p->next;
        if (p==NULL) break;
    }
    printf("\n");
}
int main(){
    LStack S;
    char ch1,ch2;
    int z=0,x;
    ch1='1';
    while(ch1!='5')
    {
        system("cls");
        printf("��ѡ����Ҫʹ�õĹ���:\n");
        printf("1.��ʼ��ջ\n");
        printf("2.����Ԫ��\n");
        printf("3.����Ԫ��\n");
        printf("4.��ӡջ\n");
        printf("5.�˳�\n");
        ch1=getch();
        switch(ch1)
        {
            case '1':
                system("cls");
                InitStack(&S);
                CreateStack(S);
                z=1;
            break;
            case '2':
                system("cls");
                if(!z){
                    printf("�㻹δ����ջ!\n\n\n\n\n");
                    system("pause");
                    break;
                }
                printf("��������Ҫѹ��ջ����ֵ��\n");
                scanf("%d",&x);
                PushStack(S,x);
            break;
            case '3':
                system("cls");
                if(!z){
                    printf("�㻹δ����ջ!\n\n\n\n\n");
                    system("pause");
                    break;
                }
                PopStack(S);
                printf("�����ɹ���\n\n\n\n\n");
                system("pause");
            break;
            case '4':
                system("cls");
                if(!z){
                    printf("�㻹δ����ջ!\n\n\n\n\n");
                    system("pause");
                    break;
                }
                PrintStack(S);
                printf("��ӡ�ɹ�!!!\n\n");
                system("pause");
            break;
            case '5':
            break;
        }
    }
    system("cls");
    printf("��ӭ�´�ʹ��.\n\n\n\n");
    system("pause");
    return 0;
}