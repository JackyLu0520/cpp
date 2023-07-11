#include<bits/stdc++.h>
using namespace std;
int t,a[10010],b[10010],c[10010],ans[10010],i,j,f[5];
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>a[i]>>b[i]>>c[i];
		a[i]*=2;
		b[i]*=2;
		c[i]*=2;
	}
	for(i=1;i<=t;i++){
		ans[i]=0;
		if(bool(a[i])+bool(b[i])+bool(c[i])>1){
			ans[i]++;
			if(bool(a[i])+bool(b[i])+bool(c[i])==2&&((a[i]+b[i]+c[i])/2==a[i]||(a[i]+b[i]+c[i])/2==b[i]))
				continue;
			if((a[i]+b[i]+c[i])/2-a[i]!=0&&a[i]!=0)
				ans[i]++;
			f[1]=a[i];
			f[2]=(a[i]+b[i]+c[i])/2-a[i];
			f[3]=a[i];
			f[4]=(a[i]+b[i]+c[i])/2-a[i];
			if (b[i]!=f[2]&&
				b[i]!=f[3]&&
				b[i]!=f[4]&&
				b[i]!=f[2]+f[3]&&
				b[i]!=f[3]+f[4]&&
				b[i]!=f[2]+f[4]&&
				b[i]!=f[2]+f[3]+f[4])
				ans[i]++; 
		}
	}
	for(i=1;i<=t;i++)
		cout<<ans[i]<<endl;
	return 0;
} 
