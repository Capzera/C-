#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){};
    ListNode(int x):val(x),next(nullptr){};
    ListNode(int x,ListNode* p):val(x),next(p){};
};

class Node {
public:
    Node(){};
    void Init();//���ý���������
    void Input();//�����������в�ֵ
    void Insert(int);//��ֵ����
    void Sort();//�����������������
    void Delete();//����ɾ�������е�ֵ
    void Show();//�������
    ~Node(){};
private:
    ListNode* head;
    ListNode* p;
};

void Node::Init() {
    head=new ListNode(-1);
    p=head;
}

void Node::Insert(int x) {
    ListNode *q=new ListNode(x);
    p->next=q;
    p=p->next;//β��
}

void Node::Input() {
    int n;
    cout<<"�������������ݸ�����";
    cin>>n;
    cout<<"���������ݣ��Կո�ָ�:"<<endl;
    for (int i=0;i<n;i++){
        int put;
        cin>>put;
        Insert(put);
    }
    cout<<"�Ѳ��룬����Ϊ��";
    Show();
}

void Node::Show() {
    p=head;
    cout<<"�����ӡΪ��";
    while (p->next){//��������
        p=p->next;
        cout<<p->val<<" ";
    }
    cout<<endl;
}

void Node::Sort() {
    p=head;
    ListNode* newHead=new ListNode(INT_MIN);
    ListNode* p1;
    while (p->next){
        p=p->next;//�ҵ��������ֵ
        ListNode* q=new ListNode(p->val);
        p1=newHead;
        while (p1->next&&p1->next->val<p->val) {
            p1=p1->next;
        }//ȷ���������λ��
        if (p1->next) {//������м��ֵ
            q->next=p1->next;
            p1->next=q;
        }
        else p1->next=q;//�����β��
    }
    head=newHead;
    cout<<"������������Ϊ��";
    Show();
}

void Node::Delete(){
    int x;
    cout<<"������Ҫɾ����ֵ��";
    cin>>x;
    p=head;
    while (p->next&&p->next->val<x){
        p=p->next;
    }//�ҵ���ɾ��ֵ��ǰһ��
    if (p->next==nullptr||p->next->val>x){//������һ��ֵС��x����һ��ֵ����x��x����������
        cout<<"��ֵ�����ڣ�"<<endl;
        return;
    }
    p->next=p->next->next;
    cout<<"��ɾ����������Ϊ��";
    Show();
}

int main() {
    Node LN;
    LN.Init();
    LN.Input();
    LN.Sort();
    LN.Delete();
    system("pause");
    return 0;
}