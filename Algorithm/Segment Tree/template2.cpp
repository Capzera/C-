#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;//��������value
    TreeNode *left,*right;//���Һ���
    TreeNode():val(0),left(nullptr),right(nullptr){};//����Ϊ��ָ����
    TreeNode(int x):val(x),left(nullptr),right(nullptr) {};//��������ֵ
    TreeNode(int x,TreeNode *left,TreeNode *right):val(x),left(left),right(right) {};//����Ϊ�������ݹ���
};
class SegTree
{
public:
    int n;
    vector<int> Tree,data,lazy;
    SegTree(){};
    void datain();//
    void pushup(int);//
    void build(int,int,int);//
    void pushdown(int,int);//����
    void add(int,int,int,int,int);//�����
    void update(int,int,int,int,int,int);//�������
    int query(int,int,int,int,int);//�����ѯ
    ~SegTree(){};
private:
};
void SegTree::datain()
{
    int i,put;
    cin>>this->n;
    this->data.resize(n);
    this->Tree.resize(n*4);
    this->lazy.resize(n*4);
    for(i=0;i<n;i++)
    {
        cin>>put;
        data[i]=put;
    }
}
void SegTree::pushup(int rt)
{
    Tree[rt]=Tree[rt*2]+Tree[rt*2+1];
}

void SegTree::build(int l,int r,int rt)
{
    if (l==r)
    {
        Tree[rt]=data[l];//�Ƚ����ݴ�����������
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,rt*2);//�������ݹ�
    build(mid+1,r,rt*2+1);
    pushup(rt);
}

void SegTree::pushdown(int rt,int l)
{
    if (lazy[rt])
    {
        lazy[rt*2]+=lazy[rt];
        lazy[rt*2+1]+=lazy[rt];
        Tree[rt*2]+=lazy[rt]*(l+l/2);
        Tree[rt*2+1]+=lazy[rt]*(l/2);
        lazy[rt]=0;
    }
}

void SegTree::add(int L,int R,int l,int C,int rt)
{
    if (L==R)
    {
        Tree[rt]=C;//��Ӧ���ӵ�����Cѹ����״����
        return;
    }
    int mid=(L+R)/2;
    pushdown(rt,R-L+1);
    if (l<=mid) add(L,mid,l,C,rt*2);
    else add(mid+1,R,l,C,rt*2+1);
    pushup(rt);
}

void SegTree::update(int L,int R,int l,int r,int C,int rt)
{
    if(L>=l&&R<=r)
    {
        Tree[rt]=C*(R-L+1);
        lazy[rt]+=C;
        return;
    }
    int mid=(L+R)/2;
    pushdown(rt,R-L+1);
    if (r<=mid) update(L,mid,l,r,C,rt*2);
    else if (r>mid) update(mid+1,R,l,r,C,rt*2+1);
    else
    {
        update(L,mid,l,r,C,rt*2);
        update(mid+1,R,l,r,C,rt*2+1);
    }
    pushup(rt);
}

int SegTree::query(int L,int R,int l,int r,int rt)
{
	if(L>=l&&R<=r) return Tree[rt];
	int mid=(L+R)/2;
	pushdown(rt,R-L+1);
	if(r<=mid) return query(L,mid,l,r,rt*2);
	else if(l > mid) return query(mid+1,R,l,r,rt*2+1);
	else return query(L,mid,l,mid,rt*2)+query(mid+1,R,mid+1,r,rt*2+1);
}
int main()
{
    SegTree segtree;
    segtree.datain();
    int m,i;
    for(i=0;i<25;i++) cout<<segtree.Tree[i]<<" ";
    system("pause");
    return 0;
}