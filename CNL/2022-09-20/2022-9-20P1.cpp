#include <bits/stdc++.h>
using namespace std;
    vector<int> ans, pai(10);
    int card;
    bool dfs(bool quetou, int index, vector<int> pai){
        if (index == 14) return 1;
        if (!quetou){//���ûѡȸͷ
            for (int i = 1; i < 10; i++){
                if (pai[i] < 2) continue;
                pai[i] -= 2;
                if (dfs(1, index + 2, pai)) return 1;
                pai[i] += 2;
            }
            return 0;
        }
        else{//ȸͷ�Ѿ�ȷ����
            for (int i = 1; i < 10; i++){
                if (pai[i] > 2) {
                    pai[i] -= 3;
                    if (dfs(1, index + 3, pai)) return 1;
                    pai[i] += 3;
                }
                if (i < 8 && pai[i] && pai[i + 1] && pai[i + 2]) {
                    pai[i]--;
                    pai[i + 1]--;
                    pai[i + 2]--;
                    if (dfs(1, index + 3, pai)) return 1;
                    pai[i]++;
                    pai[i + 1]++;
                    pai[i + 2]++;
                }
            }
            return 0;
        }
    }
int main(){
    for (int i = 0; i < 13; i++) {
        cin >> card;
        pai[card]++;
    }
    for (int i = 1; i < 10; i++) {//ö��ȱ��������
        if (pai[i] == 4) continue;
        pai[i]++;
        if (dfs(0, 0, pai)) ans.push_back(i);
        pai[i]--;
    }
    if (ans.empty()) cout<<"δ����"<<endl;
    else for(auto& i:ans) cout<<i<<" ";
    system("pause");
    return 0;
}