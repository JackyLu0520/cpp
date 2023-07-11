#include<iostream>
#include<cmath>
using namespace std;
const int MAXN=10000;
int main()
{
	int a,i,j,jinwei,w1,w2,n;
	int fibo1[MAXN]={0},fibo2[MAXN]={0},fibo3[MAXN]={0};
	cin>>a;
	fibo1[0]=fibo2[0]=1;
	for(i=3;i<=a;i++)
	{
		jinwei=0;
		for(j=MAXN-1;j>=0;j--) if(fibo1[j]) {w1=j;break;}
		for(j=MAXN-1;j>=0;j--) if(fibo2[j]) {w2=j;break;}
		for(j=0;j<=max(w1,w2)+1;j++)
		{
			n=fibo1[j]+fibo2[j]+jinwei;
			fibo3[j]=n%10;
			jinwei=n/10;
		} 
		for(j=max(w1,w2)+1;j>=0;j--) fibo1[j]=fibo2[j];
		for(j=max(w1,w2)+1;j>=0;j--) fibo2[j]=fibo3[j];
	}
	for(j=max(w1,w2)+1;j>=0;j--) if(fibo3[j]) break;
	for(i=j;i>=0;i--) cout<<fibo3[i];
	return 0;
}
