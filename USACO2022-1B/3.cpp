#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,res[110],f[110]={0};
		string b[110];
		cin>>n>>m;
		for(int i=1;i<=m;i++)
			cin>>b[i]>>res[i];
		for(int i=0;i<n;i++){
			int p0=1,dif0=0;
			while(p0<=m&&(b[p0][i]!='0'||f[p0]))p0++;
			for(int j=p0;j<=m;j++)
				if(b[j][i]=='0'&&!f[j])
					if(res[j]!=res[p0])
						dif0=1;
			if(!dif0)
				for(int j=p0;j<=m;j++)
					if(b[j][i]=='0'&&!f[j])
						f[j]=1;
			int p1=1,dif1=0;
			while(p1<=m&&(b[p1][i]!='1'||f[p1]))p1++;
			for(int j=p1;j<=m;j++)
				if(b[j][i]=='1'&&!f[j])
					if(res[j]!=res[p1])
						dif1=1;
			if(!dif1)
				for(int j=p1;j<=m;j++)
					if(b[j][i]=='1'&&!f[j])
						f[j]=1;
			//cout<<p0<<' '<<dif0<<endl;
			//cout<<p1<<' '<<dif1<<endl;
		}
		int p=1,dif=0;
		while(p<=m&&f[p])p++;
		for(int j=p;j<=m;j++)
			if(!f[j])
				if(res[j]!=res[p])
					dif=1;
		//cout<<p<<' '<<dif<<endl;
		if(!dif)
			cout<<"OK"<<endl;
		else
			cout<<"LIE"<<endl;
	}
	return 0;
}