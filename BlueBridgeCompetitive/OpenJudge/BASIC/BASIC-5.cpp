/*
����������
����һ������n�����������У�������a�������еĵ�һ�γ����ǵڼ�����
�����ʽ
��һ�а���һ������n��
�ڶ��а���n���Ǹ�������Ϊ���������У������е�ÿ������������10000��
�����а���һ������a��Ϊ�����ҵ�����
�����ʽ
���a�������г����ˣ��������һ�γ��ֵ�λ��(λ�ô�1��ʼ���)���������-1��
��������
6
1 9 4 8 3 9
9
�������
2
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums;nums.clear();
    int n,i,target,put;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>put;
        nums.push_back(put);
    }
    cin>>target;
    for(i=0;i<n;i++)
    {
        if (nums[i]==target)
        {
            cout<<i+1<<endl;
            system("pause");
            return 0;
        }
    }
    cout<<-1<<endl;
    system("pause");
    return 0;
}