#include<iostream>
#include<algorithm>
using namespace std;
int n,x,y,row[110]={0},c[110]={0},l[210]={0},r[210]={0},m=0;
int main(){
	int i;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>x>>y;
		row[y]++;
		c[x]++;
		l[y-x+100]++;
		r[x+y]++;
	}
	for(i=0;i<=110;i++)	m=max(m,row[i]);
	for(i=0;i<=110;i++)	m=max(m,c[i]);
	for(i=0;i<=210;i++)	m=max(m,l[i]);
	for(i=0;i<=210;i++)	m=max(m,r[i]);
	cout<<m;
	return 0;
}
