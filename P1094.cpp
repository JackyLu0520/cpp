#include<bits/stdc++.h>
using namespace std;
int w,n,p[30010],cnt=-1;
int main(){
	cin>>w>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+n+1);
	for(int i=1;i<=n;cnt++)
		if(p[i]+p[i+1]>w)	i++;
		else				i+=2;
	cout<<cnt;
	return 0;
}
