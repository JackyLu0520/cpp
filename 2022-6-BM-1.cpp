#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	cin>>t;
	while(t--){
		int n,m,x1,y1;
		string a[110];
		bool f;
		cin>>n>>m;
		for(int i=0;i<n;i++)
			cin>>a[i];
		f=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				if(a[i][j]=='R'){
					x1=i,y1=j;
					f=1;
					break;
				}
			if(f)	break;
		}
		f=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++)
				if(a[j][i]=='R'){
					if(x1==j&&y1==i)	cout<<"YES"<<endl;
					else				cout<<"NO"<<endl;
					f=1;
					break;
				}
			if(f)	break;
		}		
	}
	return 0;
}