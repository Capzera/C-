#include<bits/stdc++.h>
using namespace std;
void dfs(int ��ǰ����һ��){
    if (���һ��){
        ��¼��/��+1/�����;
        return;
    }
    for (��ǰ������е����){
        if (�����ʹ�) continue;
        *�����/��¼;
        dfs(��һ��);
        *ȡ�����;
    }
}
int main(){
    dfs(0);
}