#include<bits/stdc++.h>
using namespace std;
void QSort(int l,int r,int a[])
{
    int i=l,j=r,mid=(l+r)/2;
    while(i<=j)
    {
        while(a[i]<a[mid]) i++;//�����߶���Ϊ��Сֵ
        while(a[j]>a[mid]) j--;//���Ұ�߶���Ϊ�ϴ�ֵ
        if (i<=j) //�����ұ�Ӧ���ǽ�Сֵ���Ӧ���ǽϴ�ֵ
        {
            swap(a[i],a[j]);//����
            i++;
            j--;
        }
    }
    if (l<j) QSort(l,j,a);//��������߿���
    if (i<r) QSort(i,r,a);//�������ұ߿���
}
int main(){
    int a[10001],n,i;
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    QSort(1,n,a);
    for(i=1;i<=n;i++) cout<<a[i]<<" ";
    system("pause");
    return 0;
}