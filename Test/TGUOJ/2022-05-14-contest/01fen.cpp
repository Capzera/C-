#include<bits/stdc++.h>
using namespace std;

int n,c;
int w[101],v[101],bestx[101];
int bestv=0,total=1;
struct node        //�����еĽ������
{
    int no;            //����ţ���1��ʼ 
    int i;            //��ǰ����������ռ��еĲ�� 
    int w;            //��ǰ���������� 
    int v;            //��ǰ�����ܼ�ֵ 
    int x[101];    //��ǰ�������Ľ����� 
    double ub;        //�Ͻ� 
};

void bound(node &e)        //�����֧���e���Ͻ� 
{
    int i=e.i+1;        //���ǽ��e��������Ʒ
    int sumw=e.w;
    double sumv=e.v;
    while((sumw+w[i]<=c)&&i<=n) 
    {
        sumw+=w[i];
        sumv+=v[i];
        i++;
    }
    if(i<=n)            //������Ʒֻ�ܲ���װ�� 
    e.ub=sumv+(c-sumw)*v[i]/w[i];
    else e.ub=sumv; 
} 

void enqueue(node e,queue<node> &q)
//���e����qu 
{
    if(e.i==n)                //����Ҷ�ӽڵ㣬������չ��Ӧһ���� 
    {
        if(e.v>bestv)        //�ҵ������ֵ�Ľ� 
        {
            bestv=e.v;
            for(int j=1;j<=n;j++)
            bestx[j]=e.x[j];
        }
    }
    else q.push(e);        //��Ҷ�ӽ�����
} 

void bfs()
{
    int j;
    node e,e1,e2;
    queue<node> q;
    e.i=0;
    e.w=0;
    e.v=0;
    e.no=total++; 
    for(j=1;j<=n;j++)
    e.x[j]=0;
    bound(e);
    q.push(e);   
    while(!q.empty())
    {
        e=q.front();q.pop();    //���ӽ��e 
        if(e.w+w[e.i+1]<=c)        //��֦��������ӽ�� 
        {
            e1.no=total++;        //�������ӽ�� 
            e1.i=e.i+1;
            e1.w=e.w+w[e1.i];
            e1.v=e.v+v[e1.i];
            for(j=1;j<=n;j++)
            e1.x[j]=e.x[j];
            e1.x[e1.i]=1;
            bound(e1);        //�����ӵ��Ͻ� 
            enqueue(e1,q);    //���ӽ����� 
        }
        e2.no=total++;
        e2.i=e.i+1;
        e2.w=e.w;
        e2.v=e.v; 
        for(j=1;j<=n;j++)
            e2.x[j]=e.x[j];
        e2.x[e2.i]=0;
        bound(e2);
        if(e2.ub>bestv)        //���Һ��ӽ����У�����ӣ����򱻼�֦ 
        enqueue(e2,q);    
    }
} 

int main() {
    cout<<"��������Ʒ�ĸ�����"<<endl;
    cin>>n;
    cout<<"������ÿ����Ʒ����������ֵ:"<<endl;
    for(int i = 1; i <= n; i++) cin>>w[i]>>v[i];
    cout<<"�����뱳����������"<<endl;
    cin>>c;
    bfs();
    cout<<"����ֵ��:"<<bestv<<endl;
    for(int i=1;i<=n;i++) cout<<bestx[i]<<" ";
    system("pause");
    return 0;
} 