#include<bits/stdc++.h>
using namespace std;
vector<int> nums,location;
vector<bool> ind;
int n,k;
void dfs(int cur) {
    if (cur==k) {//����Ѿ�ѡȡ��k����
        for (auto i:location) cout<<i<<" ";//������Ĵ����
        cout<<endl;
        return;//���ټ���Ѱ����һ���������ݻ�ȥ
    }
    for (int i=0;i<n;i++) {
        if (ind[i]) continue;//����������ѡȡ�ˣ�������
        ind[i]=1;//ѡȡ�����
        location[cur]=nums[i];//����������������ĸ�
        dfs(cur+1);//��ʼ����һ����
        ind[i]=0;//���ݻ���֮��ȡ��������ı��
    }
}
int main(){
    cin>>n>>k;
    nums=vector<int> (n);//nums���n����
    location=vector<int> (k);//location��Ŵ�
    ind=vector<bool>(n,false);//������飬����ÿ�����Ƿ�ѡȡ
    for (int i=0;i<n;i++) cin>>nums[i];//����
    dfs(0);
    system("pause");
    return 0;
}