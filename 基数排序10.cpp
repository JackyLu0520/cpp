#include<bits/stdc++.h>
using namespace std;
int n,a[10001];
void geta()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
}
void puta(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<' ';
}
int maxbit(int a[],int n)
{
	int d=1,p=10;
	for(int i=0;i<n;i++)
		while(a[i]>=p)
		{
			p*=10;
			d++;
		} 
	return d;
}
void sort(int a[],int n)
{
	int d=maxbit(a,n);
	int ra[10][n];
	int c[10];
	int i,j,k,m;
	int r=1;
	for(i=1;i<=d;i++)
	{
		memset(c,0,sizeof(c));
		for(j=0;j<n;j++)
		{
			k=(a[j]/r)%10;
			ra[k][c[k]]=a[j];
			c[k]++;
		}
		for(k=0,j=0;k<10;k++)
		{
			for(m=0;m<c[k];m++)
				a[j++]=ra[k][m];
		}
		r*=10;
	}
}
int main()
{
	geta();
	sort(a,n);
	puta(a,n);
	return 0;
}
