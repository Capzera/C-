#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int a,b,c,d,jia,yi,bing;
	for(a=1;a<=4;a++)
	{
		for(b=1;b<=4;b++)
		{
			if (b==a) continue;
			for(c=1;c<=4;c++)
			{
				if (c==a||c==b) continue;
				for(d=1;d<=4;d++)
				{
					jia=yi=bing=0;
					if (d==a||d==b||d==c) continue;
					if (a==1) jia++;
					if (b==2) jia++;
					if (c==1)yi++;
					if (b==3) yi++;
					if (d==2) bing++;
					if (a==3) bing++;
					if (jia==1&&yi==1&&bing==1)
					{
						cout<<"A��������"<<a<<endl<<"B��������"<<b<<endl<<"C��������"<<c<<endl<<"D��������"<<d<<endl;
						return 0; 
					}
				}
			}
		}
	}
}
