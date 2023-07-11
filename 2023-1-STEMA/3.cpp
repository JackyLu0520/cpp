#include<bits/stdc++.h>
using namespace std;
int n,a[60],g,sum=0,ans=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	g=sum/n;
	while(1){
		int maxa=0;
		for(int i=1;i<=n;i++)
			if(a[maxa]<a[i])
				maxa=i;
		if(a[maxa]==g)	break;
		int d1=0,d2=0;
		for(int i=maxa;a[i]>g;i++)	d1++;
		for(int i=maxa;a[i]>g;i--)	d2++;
		if(d1<d2){
			a[maxa-1]+=a[maxa]-g;
			a[maxa]=g;
			ans++;
		}else{
			a[maxa+1]+=a[maxa]-g;
			a[maxa]=g;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}