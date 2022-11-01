#include<bits/stdc++.h>
using namespace std;
class KMP{
public:
    KMP(string s,string t):s(s),t(t),len1(s.size()),len2(t.size()){
	    GetNextval(t);
    }
    void GetNextval(string t)//��ȡnextval����
    {
        nextval=vector<int>(t.size());//����һ������Ϊt-1������
	    nextval[0]=-1;//�����ʼ�߽�
	    for (int i=1,j=0;i<len2;i++) {//����t�ַ�������1��ʼ����t-2����
            if (j==-1||t[i]==t[j]) {//j==-1˵��û�й���ǰ��׺��t[i]==t[j]��ǰ����ָ��ָ�������ͬ
                j++;
                if (t[i]!=t[j]) nextval[i]=j;//nextvalֱ���ƶ�Ӧ��ǰ׺������±�
                else nextval[i]=nextval[j];//nextvalֱ��������
            }
            else j=nextval[j];//��Ҫ����
	    }
    } 
    int KMPindex(string s,string t) {//��KMP�㷨
        int i=0,j=0;
	    while (i<len1&&j<len2) {
		    if (j==-1||s[i]==t[j]) {
                i++;
                j++;
            }
		    else j=nextval[j];
        }
        if (j>=len2) return(i-len2);
        else  return(-1);
    }
    void getNextArray(){
        for (auto& i:nextval){
            cout<<i<<" ";
        }
        cout<<endl;
        system("pause");
        system("cls");
    }
    void show(){//��ӡ����
        int val=KMPindex(s,t);
        if (val<0) cout<<"δƥ��"<<endl;
        else cout<<"ƥ������Ϊ"<<val<<"--"<<val+len2-1<<endl;
    }
private:
    string s,t;
    int len1,len2;
    vector<int> nextval;
};
int main(){
    string s1,s2;
    cin>>s1>>s2;
    KMP K(s1,s2);
    K.getNextArray();
    K.show();
    system("pause");
    return 0;
}