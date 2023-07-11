#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[510],b[510],Min[510];
int main(){
	cin>>t;
	for(int l=1;l<=t;l++){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			Min[i]=600;
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++){
				for(int k=1;k<=n;k++)
					b[k]=a[k];
				reverse(b+i,b+j+1);
				int f=0;
				for(int k=1;k<=n;k++)
					if(b[i]<Min[i])
						f=1;
				if(f==1)
					for(int k=1;k<=n;k++)
						Min[k]=b[k];
			}
		for(int i=1;i<=n;i++)
			cout<<Min[i]<<' ';
		cout<<endl;
	}
	return 0;
}