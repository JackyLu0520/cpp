#include<bits/stdc++.h>
using namespace std;
int a[1000010],q,n,m,*t;
int main(){
	int i;
	cin>>n>>m;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=1;i<=m;i++){
		cin>>q;
		t=lower_bound(a,a+n,q);
		if(*t==q)
			cout<<int(t-a+1)<<' ';
		else
			cout<<-1<<' ';
	}
	return 0;
} 
