#include<bits/stdc++.h>
using namespace std;
int n,f1[60],f2[60],ans=0,a[60];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		double t;
		cin>>t;
		a[i]=t*10;
	}
	for(int i=1;i<=n;i++){
		f1[i]=1;
		for(int j=1;j<i;j++)
			if(a[i]>a[j])
				f1[i]=max(f1[i],f1[j]+1);
	}
	for(int i=n;i>=1;i--){
		f2[i]=1;
		for(int j=i+1;j<=n;j++)
			if(a[i]>a[j])
				f2[i]=max(f2[i],f2[j]+1);
	}
	for(int i=2;i<n;i++)
		if(f1[i]!=1&&f2[i]!=1)
			ans=max(ans,f1[i]+f2[i]-1);
	cout<<(ans==0?-1:n-ans);
	return 0;
}