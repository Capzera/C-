# pragma pack(16)
# include <stdio.h>
# include <stdlib.h>
//# pragma pack(1)
//# pragma pack(2)   //����Ĭ�϶�����Ϊ2
//# pragma pack(4)
//# pragma pack(8)
struct s1              //�ṹ��
{
	char c1;
	int i;
	char c2;
};
struct s2
{
	char c1;
	char c2;
	int i;
};
struct s3
{
	double c1;
	char c2;
	int i;
};
//#pragma pack()  //ȡ�����õ�Ĭ�϶���������ԭΪĬ������
struct s4
{
	char c1;
	struct s3 s3;
	double d;
};
struct s5
{
	struct s4 s4;//32  0-31
	int e;//4 32-35
	char f[5];//5 36-40
	char* h;//8   48-55
    struct s4 ss4;//64-95
	void(*g)(int); //������ָ�뺯��  8 96-103

};
struct s6{
    void (*g)(int);
};
int main ()
{
	printf ("s1=%d\n",sizeof(struct s1));    //����ṹ���С
	printf ("s2=%d\n",sizeof(struct s2));
	printf ("s3=%d\n",sizeof(struct s3));
	printf ("s4=%d\n",sizeof(struct s4));
	printf ("s5=%d\n",sizeof(struct s5));
    printf ("s6=%d\n",sizeof(struct s6));
    system ("pause");
    return 0;
}
