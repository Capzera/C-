#include<bits/stdc++.h>
using namespace std;
int a[10000],key,n=0;
void search(int l,int r);
int main(){
    printf("�������ź��������:\n");
    char ch;
    while (ch!='\n'){
        n++;
        scanf("%d",&a[n]);
        ch=getchar();
    }
    printf("��������Ҽ�:\n");scanf("%d",&key);
    search(1,n);
    printf("����������ڣ�\n");
    system("pause");
    return 0;
}
void search(int l,int r){
    int mid=(l+r)/2;
    if (r-l<1&&a[mid]!=key)return;
    if (a[mid]==key) {printf("������ڵ�%d��\n",mid);system("pause");exit(0);}
    else if (a[mid]<key) search(mid,r);
    else search(l,mid);
}