#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define LIST_INIT_SIZE 100
typedef struct ElementType
{
    int Num;
    char Name[20];
    double Price;
    int Rest;
}ElementType;
typedef struct list
{
    ElementType *element;
    int listsize;
    int length;
}SQList;
int Initlist(SQList &L)
{
    L.element = (ElementType *)malloc(LIST_INIT_SIZE * sizeof(ElementType));
    if (!L.element)
    {
        return -1;
    }
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return 1;
}
int Locatelist(SQList L,int x)
{
    int pos=-1;
    for (int i=0;i<=L.length;i++)
    {
        if (L.element[i].Num==x)
        {
            pos = i;
        } 
    }
    return pos;
}
int ListDelete(SQList &L,int i)
{
    if(i<1||i>L.length)return -1;
    struct ElementType *p,*q;
    p = &(L.element[i-1]);
    q = L.element+L.length-1;
    for(;p<=q;p++)
    {
        *p = *(p+1);
    }
    --L.length;
    return 0;
}
int main(){
    SQList List;
    int n,z=1,change;
    system("title ��Ʒ����ϵͳ By��/////////�������");
    system("color A1");
	while(1){
        system("cls");
        printf("��ӭʹ����Ʒ����ϵͳ���밴��ʾʹ�ã�\n");
		printf("1.������Ϣ\n2.������ѯ\n3.ɾ����Ϣ\n4.��Ϣ�޸�\n0.�˳�ϵͳ\n");
        char ch=getch();
        while (ch>52||ch<48) ch=getch();
        int sNum;
		if(ch=='0')
        {
            system("cls");
			printf("лл����ʹ�ã��ټ���\n\n\n\n");
			break; 
		}
        if (ch=='1')
        {
            system("cls");
            if (!z)
            {
                system("cls");
                printf("�����Ѿ����룬�����ظ�������\n\n\n\n\n");
                system("pause");
            }
            else
            {
                Initlist(List);
                printf("����������������ٸ���Ʒ����Ϣ:");
                scanf("%d",&n);
                List.length=n;
                for (int i=0;i<n;i++)
                {
                    system("cls");
                    printf("�������%d����Ʒ����Ϣ:\n",i+1);
                    printf("��ţ�");
                    scanf("%d",&List.element[i].Num);
                    printf("���ƣ�");
                    scanf("%s",List.element[i].Name);
                    printf("�۸�");
                    scanf("%lf",&List.element[i].Price);
                    printf("ʣ��������");
                    scanf("%d",&List.element[i].Rest);
                    printf("\n");
                    z=0;
                }
                continue;
            }
        }
		if(ch=='2')
        {
            system("cls");
            if (z)
            {
                printf("����δ�������ݣ����Ƚ����������!\n\n\n\n\n");
                system("pause");
            }
			else
            {
                printf("�����������ѯ����Ʒ���:");
                scanf("%d",&sNum);
                system("cls");
                if (Locatelist(List,sNum)<0)
                {
                    system("cls");
                    printf("����Ʒδ��ѯ��\n\n\n\n\n");
                    system("pause");
                } 
                else 
                {
                    printf("%d����Ʒ����ϢΪ:\n��ţ�%d\n���ƣ�%s\n�۸�%.2lf\nʣ��������%d\n",sNum,List.element[Locatelist(List,sNum)].Num,List.element[Locatelist(List,sNum)].Name,List.element[Locatelist(List,sNum)].Price,List.element[Locatelist(List,sNum)].Rest);
                    system("pause");
                }
            }
            continue;
        }
		if(ch=='3')
        {
            system("cls");
            if (z)
            {
                printf("����δ�������ݣ����Ƚ����������!\n\n\n\n\n");
                system("pause");
            }
            else
            {
                printf("����������ɾ������Ʒ���:");
                scanf("%d",&sNum);
                system("cls");
                if (Locatelist(List,sNum)<0)
                {
                    system("cls");
                    printf("����Ʒδ��ѯ��!\n\n\n\n\n");
                    system("pause");
                }
                else {
                    ListDelete(List,Locatelist(List,sNum)+1);
                    printf("����Ʒɾ���ɹ���\n\n\n\n\n");
                    system("pause");
                }
            }
            continue;
        }
        if (ch=='4')
        {
            system("cls");
            if (z)
            {
                printf("����δ�������ݣ����Ƚ����������!\n\n\n\n\n");
                system("pause");
            }
            else
            {
                printf("��������Ҫ�޸���Ʒ�ı�ţ�");
                scanf("%d",&sNum);
                system("cls");
                if (Locatelist(List,sNum)<0)
                {
                    system("cls");
                    printf("����Ʒδ��ѯ��!\n\n\n\n\n");
                    system("pause");
                }
                else {
                    while(1)
                    {
                        printf("ѡ����Ҫ���еĲ�����\n1.��������\n2.�޸ĵ���\n0.�˳��޸�");
                        char ch2=getch();
                        while(ch2>50||ch2<48)ch2=getch();
                        system("cls");
                        if (ch2=='0')
                        {
                            break;
                        }
                        if (ch2=='1')
                        {
                            system("cls");
                            printf("1.����\n2.����\n0.���ز˵�");
                            char ch3=getch();
                            while (ch3>50||ch3<49)ch3=getch();
                            system("cls");
                            if (ch3=='0'){
                                break;
                            }
                            if (ch3=='1')
                            {
                                printf("������Ҫ���Ӷ��ٿ�棺");
                                scanf("%d",&change);
                                List.element[Locatelist(List,sNum)].Rest+=change;
                                system("cls");
                                printf("���������!");
                            }
                            if (ch3=='2')
                            {
                                printf("������Ҫ���ٶ��ٿ�棺");
                                scanf("%d",&change);
                                system("cls");
                                List.element[Locatelist(List,sNum)].Rest-=change;
                                if (List.element[Locatelist(List,sNum)].Rest<0)
                                {   
                                    system("cls");
                                    printf("��治����Ϊ����!\n\n\n\n\n");
                                    system("pause");
                                    system("cls");
                                    List.element[Locatelist(List,sNum)].Rest+=change;
                                    break;
                                }
                                printf("����Ѽ��٣�\n\n\n\n\n");
                            }
                        }
                        if (ch2=='2')
                        {
                            system("cls");
                            printf("��ѡ���޸ĺ����Ʒ����:");
                            scanf("%lf",&List.element[Locatelist(List,sNum)].Price);
                            printf("��Ʒ�������޸�\n");
                        }
                        system("pause");
                        system("cls");
                    }
                }              
            }
        }
    }
    system("pause");
    return 0;
}