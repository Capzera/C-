#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,wide=4;
	cin>>n;
    n=pow(2,n);//Ԥ����nΪ2^n
    vector<string> ans(n,string(2*n,' '));//һ����2^n�У�ÿһ����2^i���ַ���2^i���ո�����ÿһ�е��ַ�������Ԥ��Ϊ2^n+1���ո�
	ans[0][0]=ans[1][1]='/';
	ans[0][1]=ans[0][2]='_';
	ans[0][3]=ans[1][2]='\\';
	while(wide<=n){//����wide���ܴ���2^n
		for(int i=0;i<wide/2;i++){
			for(int j=0;j<wide;j++){
				ans[i][j+wide]=ans[i][j];//����ƽ�Ƹ���
				ans[i+wide/2][j+wide/2]=ans[i][j];//������չ����
			}
		}
		wide*=2;
	}
	for(int i=n-1;i>=0;i--){//����������ȴ�ӡ��ǣ��ٴ�ӡ����
		cout<<ans[i]<<endl;//ÿ�ж�����string����ģ�ֱ����������ַ���
	}
    system("pause");
	return 0;
}