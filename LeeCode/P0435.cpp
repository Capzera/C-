/*
    LeeCode P435 ���ص�����
    ����һ������ļ��ϣ��ҵ���Ҫ�Ƴ��������С������ʹʣ�����以���ص���
    ע��:
    ������Ϊ������յ����Ǵ���������㡣
    ���� [1,2] �� [2,3] �ı߽��໥���Ӵ�������û���໥�ص���
    �㷨��̰�� ���� ��̬�滮 ����
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[1001],b[1001];
    int i,j,len=0,n=0;
    while(a[n]!=0&&b[n]!=0){
        n++;
        cin>>a[n]>>b[n];
    }
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
            if (b[i]>b[j])
            {
                swap(a[i],a[j]);
                swap(b[i],b[j]);
            }
    a[0]=b[1];
    for(i=2;i<=n;i++)
        if (a[i]<a[0]) len++;
            else a[0]=b[i];
    cout<<len<<endl;
    system("pause");
    return 0;
}
/*��������1��
1 2
2 3
3 4
1 3
0 0
�������1��
1
��������2��
1 2
1 2
1 2
0 0
�������2��
2
��������3��
1 2
2 3
0 0
�������3��
0
*/