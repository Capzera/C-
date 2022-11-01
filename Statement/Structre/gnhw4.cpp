#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
	struct Stu{
		int num;
		char name[255];
		int score1;
		int score2;
		double avg;
        bool dele=false;
	};
void input(struct Stu student[],double *average1,double *average2);
void output(struct Stu student[]);
int search(int n,struct Stu student[]);
void del(struct Stu student[],double *average1,double *average2);
int main(){
	struct Stu student[6];
	struct Stu temp;
	int i,j,n=5,nn,z=-1;
    char ch=' ';
    double average1,average2,*pointer1,*pointer2;
    pointer1=&average1;
    pointer2=&average2;
    while (ch!='0'){
        system("cls");
        printf("��ѡ���ܣ�\n1.¼����Ϣ\n2.��ӡ��Ϣ\n3.��ѯѧ����Ϣ\n4.ɾ����Ϣ\n0.�˳�\n");
        ch=getch();
        if (ch>'1'&&ch<='4'&&z==-1){
            printf("�㻹δ¼����Ϣ��\n");
            system("pause");
            system("cls");
            continue;
        }
        else if(ch>'4'||ch<'0'){
            printf("������Ĳ�����Ч���ܣ�\n");
            system("pause");
            system("cls");
            continue;            
        }
        else if(ch=='1'&&z==0){
            printf("ѧ���ɼ��ѵ��롣\n");
            system("pause");
            system("cls");
            continue;              
        }
        else if(ch=='1'){
            system("cls");            
            input(student,pointer1,pointer2);
            z=0;
        }
        else if(ch=='2'){
            system("cls");  
            output(student);
        }
        else if(ch=='3'){
            system("cls");  
            printf("�������������ѧ����ѧ�ţ�");
            scanf("%d",&nn);
            i=search(nn,student);
            if(i>0){
	            printf("Num  Name  Score1  Score2  Average\n");
                printf("%4d %4s %7d %7d     %.2lf\n",student[i].num,student[i].name,student[i].score1,student[i].score2,student[i].avg);
                system("pause");
            }
            else printf("����ѧ��δ�ҵ�");
        }
        else if(ch=='4'){
            system("cls");  
            del(student,pointer1,pointer2);
	        for(i=1;i<=5;i++){
                if (student[i].dele) continue;
                printf("%4d %4s %7d %7d     %.2lf\n",student[i].num,student[i].name,student[i].score1,student[i].score2,student[i].avg);
            }
            printf("��ӡ��ϣ�\n");
            system("pause");
        }
    }
    system("cls");
    printf("��лʹ�ã�\n");
	system("pause");
	return 0;
}
void input(struct Stu student[],double *average1,double *average2){
	int i;
    printf("��¼��ѧ����Ϣ��\n");
	for(i=1;i<=5;i++){
		scanf("%d %s %d %d",&student[i].num,student[i].name,&student[i].score1,&student[i].score2);
		student[i].avg=(student[i].score1+student[i].score2)/2.0;
        *average1+=student[i].score1;
        *average2+=student[i].score2;
	}
    *average1/=5.0;
    *average2/=5.0;
}
void output(struct Stu student[]){
	printf("Num  Name  Score1  Score2  Average\n");
	int i;
	for(i=1;i<=5;i++)printf("%4d %4s %7d %7d     %.2lf\n",student[i].num,student[i].name,student[i].score1,student[i].score2,student[i].avg);
    printf("��ӡ��ϣ�\n");
    system("pause");
}
int search(int n,struct Stu student[]){
    int i;
    for(i=1;i<=5;i++)
        if(student[i].num==n) return(i);
    return(0);
}
void del(struct Stu student[],double *average1,double *average2){
    int i;
    for(i=1;i<=5;i++){
        if (student[i].score1>*average1) student[i].dele=true;
        if (student[i].score2>*average2) student[i].dele=true;
    }
}