/*
��Ŀ������
����ѧ���ϲ��ѧ��ѧ��������ѧ����������ϲ���о��ľ���������������ˡ���õ�����ѧ���������Ҫͨ�����Ŀ��飡
�������뿼����ǰn����������ͬ��������Ϸ����ж��٣�����дһ�������ֵ���, �г�1~n���е�������Ϸ�����
����
��������ֻ��һ�У�����һ������ n��1  <=  n  <= 7��
���
���ֵ������1~n�����п��ܵ�������Ϸ���, ÿ������ռһ��
���ں�Ϊ"�ֵ���", ��ο����������
ע��ÿ����ĩ��Ҫ�������һ���ո�(���������ø�������)
�������
1 2 3\n
�Ǵ��, ��
1 2 3 \n
���ǶԵ�
�������� 1 
3
������� 1
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/
#include<bits/stdc++.h>
using namespace std;
    int n;
    void dfs(int i,vector<int> ans,vector<bool> check){
        if (i==n){
            for(int t:ans) cout<<t<<" ";
            cout<<endl;
            return;
        }
        for(int j=0;j<n;j++) {
            if (check[j]) continue;
            check[j]=1;
            ans[i]=j+1;
            dfs(i+1,ans,check);
            check[j]=0;
        }
    }
int main(){
    cin>>n;
    vector<int> ans(n);
    vector<bool>check(n);
    dfs(0,ans,check);
    system("pause");
    return 0;
}