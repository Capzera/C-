/*
����������
����1221��һ���ǳ����������������߶��ʹ��ұ߶���һ���ģ������������������λʮ��������
�����ʽ
��������С�����˳�����������������λʮ��������
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> ve(2);
    ve.clear();
    for(int i=10;i<=99;i++)
    {
        string ans="";
        ve.push_back(i%10);
        ve.push_back(i/10%10);
        ans+=ve[1]+48;
        ans+=ve[0]+48;
        ans+=ve[0]+48;
        ans+=ve[1]+48;
        cout<<ans<<endl;
        ve.clear();
    }
    system("pause");
    return 0;
}