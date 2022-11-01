/*
    �ָ���һ���ı���S������һ��ģʽ��P����P��S���׸�����λ��

    ABCDABCABCDABD ABCDABD
    7
*/
#include <bits/stdc++.h>

using namespace std;
vector<int> Next;

void Nextval(string p){
    int k = Next[0] = -1;
    int j = 0;
    while (j < p.size() - 1) {
        //p[k]��ʾǰ׺  p[j]��ʾ��׺
        if (k == -1 || p[j] == p[k]) {// ���û��ǰ׺��ǰƥ������
            k++,j++;//k,j����ͬʱ�ƶ�
            if (p[k] == p[j])//�������k����Ҫ����������������һ��
                Next[j] = Next[k];
            else 
                Next[j] = k;//���³���jλ�������ǰ��׺
        }
        else
            k = Next[k];//����ǰ׺����λ��
    }
}

void show(){
    cout<<"Next:";
    for (auto& i:Next){
        cout<<i<<" ";
    }
    cout<<endl;
    system("pause");
    system("cls");
}

int KMP(string s, string p){
    int i = 0,j = 0;
    int slen = s.size(), plen = p.size();
    while (i < slen && j < plen){//ƥ�䲻���ʱ��i == slen������ƥ�����ʱ j == plen
        if (j == -1 || s[i] == p[j]){//j == -1?
            i++,j++;
        }
        else {//(j!= -1 && s[i] != p[j])
            j = Next[j];
        }
    }
    if (j == plen) return i - j;
    else return -1;
}

int main(){
    string s,p;
    cin>>s>>p;
    Next = vector<int> (p.size());
    Nextval(p);
    show();
    cout<<"p��s�ĵ�"<<KMP(s,p)<<"λ"<<endl;
    system("pause");
    return 0;
}
/*
ԭ���� ������
������ �������
2>=1 || 5<2
2< 1 && 5 >=2
2<1 || 5<2
5<2 || 2>=1 
*/