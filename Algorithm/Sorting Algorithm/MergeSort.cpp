/*
    By:Capzera QQ:1786126188 E-Mail:1786126188@qq.com
    �鲢�����׼�㷨�����˱�д�������Ժ���Ŀ���㷨����
*/
#include<bits/stdc++.h>
using namespace std;
void Merge(vector<int>& nums,int l,int mid,int r)//�ϲ�����
{
    int n=r-l+1;//���ϲ����䳤��Ϊr-l+1
    int i=0,left=l,right=mid+1;//leftָ��������䣬rightָ���Ұ����䣬iΪtempָ��
    int* temp=new int[n];//temp��ʱ����ϲ��õ�����
    while(left<=mid && right<=r)//�Ƚ������Ұ�ȡ��
    {
        if (nums[left]<=nums[right]) temp[i++]=nums[left++];
        else temp[i++]=nums[right++];
    }
    while (left<=mid) temp[i++]=nums[left++];//��ʣ�����ѹ��temp��
    while (right<=r) temp[i++]=nums[right++];
    for(i=0;i<n;i++) nums[l+i]=temp[i];//��temp��Ԫ�ؿ�����ԭnums
    delete [] temp;
}
void MergeSort(vector<int>& nums,int l,int r)
{
    int mid=l+(r-l)/2;
    if (l==r) return;
    MergeSort(nums,l,mid);//������������
    MergeSort(nums,mid+1,r);//�����Ұ������
    Merge(nums,l,mid,r);
}
void print(vector<int> nums)
{
    for(int i=0;i<nums.size();i++) cout<<nums[i]<<" ";
    cout<<endl;
}
int main()
{
    int n,i,put;
    cin>>n;
    vector<int> nums(n);
    for(i=0;i<n;i++)
    {
        cin>>put;
        nums[i]=put;
    }
    MergeSort(nums,0,n-1);
    print(nums);
    system("pause");
    return 0;
}