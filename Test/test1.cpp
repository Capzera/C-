#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,a,b;
	string s;
	cin>>t;
	for (int T=0;T<t;T++) {
		cin>>s;
		n=s.size();
		int ans=0,i=0,j=1;
		while (i<n&&j<n) {
			while (j<n&&s[j]!=s[i]) j++;
			if (j<n) {
				ans+=j-i-1;
				i=j+1;
				j=i+1;
			}
			else {
				i++;
				ans++;
				j=i+1;
			}
		}
		cout<<ans<<endl;
	}
	system("pause");
    return 0;
}
obbo
dp[i][j]��ʾ��i���ַ�����j���ַ���Ҫɾ�����ٵĸ�����������ż�ַ����ĸ���
dp[i][j]=max(dp[i+1][j-1]+2,)