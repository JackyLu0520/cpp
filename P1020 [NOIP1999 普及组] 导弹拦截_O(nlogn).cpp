#include<bits/stdc++.h>
using namespace std;
const int MAXN=100001,INF=0x3f3f3f3f;
int n,p1=0,p2=0,a[MAXN],f1[MAXN],f2[MAXN];
int main(){
	for(n=1;scanf("%d",&a[n])!=EOF;n++)	;
	fill(f1,f1+MAXN,INF);
	for(int i=1;i<n;i++){
		if(a[i]<=f1[p1])	f1[++p1]=a[i];
		else	f1[upper_bound(f1+1,f1+p1+1,a[i],greater<int>())-f1]=a[i];
		if(a[i]>f2[p2])	f2[++p2]=a[i];
		else	f2[lower_bound(f2+1,f2+p2+1,a[i])-f2]=a[i];
	}
	cout<<p1<<endl<<p2;
	return 0;
}
