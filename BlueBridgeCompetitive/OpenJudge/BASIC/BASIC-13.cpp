/*
����������
����һ������Ϊn�����У���������а���С�����˳�����С�1<=n<=200
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums;
    int n,i,put;
    cin>>n;
    for(i=0;i<n;i++) 
    {
        cin>>put;
        nums.push_back(put);
    }
    sort(nums.begin(),nums.end());
    for(i=0;i<n;i++) cout<<nums[i]<<" ";
    cout<<endl;
    system("pause");
    return 0;
}