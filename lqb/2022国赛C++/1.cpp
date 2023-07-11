#include<bits/stdc++.h>
using namespace std;
int n;
char a[1010];
int b[1010]={0},c[3];
int main(){
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++){
		a[i]=getchar();
		getchar();
	}
	for(int i=1;i<=n;i++)
		if(a[i]=='p')
			b[i+1]++;
		else
			b[i-1]++;
	for(int i=1;i<=n;i++)
		c[b[i]]++;
	cout<<c[0]<<' '<<c[1]<<' '<<c[2];
	return 0;
}