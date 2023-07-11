#include<iostream>
using namespace std;
int f[10000]={1,1},n[11],a[11],num[11]={0},t,maxn=0;
int main(){
	int i,j,k;
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>n[i]>>a[i];
		if(n[i]>maxn)	maxn=n[i];
	}
	for(i=1;i<=maxn;i++){
		for(j=1;j<=f[0];j++)	f[j]*=i;
		for(j=1;j<=f[0];j++){
			f[j+1]+=f[j]/10;
			f[j]%=10;
			if(f[j+1]>0&&j>=f[0])	f[0]++;
		}
		for(j=1;j<=t;j++)
			if(i==n[j])
				for(k=1;k<=f[0];k++)
					if(f[k]==a[j])
						num[j]++;
	}
	for(i=1;i<=t;i++)	cout<<num[i]<<endl;
	return 0;
}
