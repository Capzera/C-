/*
����������
��������
����123321��һ���ǳ����������������߶��ʹ��ұ߶���һ���ġ�
��������һ��������n�� �����������������λ����λʮ�������������λ����֮�͵���n ��
�����ʽ
��������һ�У�����һ��������n��
�����ʽ
��������С�����˳���������������������ÿ������ռһ�С�
��������
52
�������
899998
989989
998899
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int sum,i;
    cin>>sum;
    vector<int> vessel(3);
    vessel.clear();
    if (sum<=45&&sum>1)
    {
        if (sum<45)
            for(i=100;i<=999;i++)
            {
                vessel.push_back(i%10);
                vessel.push_back(i/10%10);
                vessel.push_back(i/100);
                //cout<<vessel[2]<<" "<<vessel[1]<<" "<<vessel[0]<<endl;
                if (vessel[0]+2*vessel[1]+2*vessel[2]==sum) 
                {
                    string ans="";
                    ans+=vessel[2]+48;
                    ans+=vessel[1]+48;
                    ans+=vessel[0]+48;
                    ans+=vessel[1]+48;
                    ans+=vessel[2]+48;
                    cout<<ans<<endl;
                }
                vessel.clear();
            }
        else cout<<99999<<endl;
    }
    if (sum%2==0)
    {
        for(i=100;i<=999;i++)
        {
            vessel.push_back(i%10);
            vessel.push_back(i/10%10);
            vessel.push_back(i/100);
            if (2*vessel[0]+2*vessel[1]+2*vessel[2]==sum) 
            {
                string ans="";
                ans+=vessel[2]+48;
                ans+=vessel[1]+48;
                ans+=vessel[0]+48;
                ans+=vessel[0]+48;
                ans+=vessel[1]+48;
                ans+=vessel[2]+48;
                cout<<ans<<endl;
            }
            vessel.clear();
        }
    }
    system("pause");
    return 0;
}