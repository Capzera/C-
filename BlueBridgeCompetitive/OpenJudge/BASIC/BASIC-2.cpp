/*
����������
���ڳ���Ϊ5λ��һ��01����ÿһλ��������0��1��һ����32�ֿ��ܡ����ǵ�ǰ�����ǣ�
00000
00001
00010
00011
00100
�밴��С�����˳�������32��01����
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    for(int i=0;i<32;i++)
    {
        string ans="";
        ans.push_back(i%2+48);
        ans.push_back(i/2%2+48);
        ans.push_back(i/2/2%2+48);
        ans.push_back(i/2/2/2%2+48);
        ans.push_back(i/2/2/2/2%2+48);
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}