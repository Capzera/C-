#include<bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node():val(0),next(nullptr){};
    Node(int x):val(x),next(nullptr){};
    Node(int x,Node* p):val(x),next(p){};
};

class Queue{
public:
    Queue(){};
    void Init();
    void Input();
    void Push(int);
    void Pop();
    void Show();
    ~Queue(){};
private:
    Node* front;
    Node* rear;
};

void Queue::Init(){
    Node *p=new Node(-1);
    front=p;
    rear=p;
}

void Queue::Input(){
    int n;
    cout<<"�������������ݸ�����";
    cin>>n;
    cout<<"���������ݣ��Կո�ָ�:"<<endl;
    for (int i=0;i<n;i++){
        int put;
        cin>>put;
        Push(put);
    }
    cout<<"�Ѳ��룬����Ϊ��";
    Show();
}

void Queue::Push(int x){
    Node *p = new Node(x);
    rear->next=p;
    rear=p;
}

void Queue::Pop(){
    Node *p=front->next;
    front->next=front->next->next;     
    if (rear==p) rear=front;
    delete p;
}

void Queue::Show(){
    Node *p=front->next;
    if (!p) cout<<"����Ϊ��"<<endl;
    while (p) {
        cout<<p->val<< " ";
        p=p->next;
    }
    cout<<endl;
}

int main(){
    Queue q;
    q.Init();
    q.Input();
    q.Push(5);
    q.Show();
    q.Pop();
    q.Show();
    system("pause");
    return 0;
}