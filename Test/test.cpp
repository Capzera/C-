#include<bits/stdc++.h>
using namespace std;
int main() {
	int len;
	cin>>len;
	int half=len/2,j=0;
	if(len%2==0) {
		int MAX=9*pow(10,half-1);
		int i=pow(10,half-1);
		while (j<MAX){
			string s1=to_string(i),s2(s1);
			reverse(s2.begin(),s2.end());
			s1+=s2;
			cout<<j+1<<" "<<s1<<endl;
			j++;
			i+=pow(10,half-2);
		}
	}
	else {
		half++;
		int MAX=9*pow(10,half-1);
		int i=pow(10,half-1);
		while (j<MAX){
			string s1=to_string(i),s2;
			s2=s1.substr(0,half-1);
			reverse(s2.begin(),s2.end());
			s1+=s2;
			cout<<j+1<<" "<<s1<<endl;
			j++;
			i++;
		}
	}
	system("pause");
	return 0;
}
/*
����ֵ���� ������(�������1���� �������1���������2���� �������2 ����){

}
1���з���ֵ���ͺ���
����Ҫ�з���ֵ
����ֵ���ͱ���Ͷ�����ƥ��
����ֵΨһ

2) �޷���ֵ���ͺ�����������
���벻���з���ֵ
*/


//ProblemA:  ��������a,b�����2*a+b*b;
//ProblemB:  ��������һ��������n����1-n�ĺ�
100 100 100 100 100 100 700
						1
						1
						1
						1
						1
						1
100  8
1	 7