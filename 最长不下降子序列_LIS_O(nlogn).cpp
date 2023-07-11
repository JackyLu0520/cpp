#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000010,INF=0x3f3f3f3f;
int n,p=0,a[MAXN],f[MAXN];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	fill(f,f+MAXN,-INF);
	for(int i=1;i<=n;i++)
		if(a[i]>=f[p])
			f[++p]=a[i];
		else{
			int pos=upper_bound(f+1,f+p+1,a[i])-f;
			f[pos]=a[i];
		}
	cout<<p;
	return 0;
}
