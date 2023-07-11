#include<iostream>
#include<cstring>
using namespace std;
int n,m,k,num=0,x[510],y[510],ty;
bool b[20010];
int main(){
	int i,j;
	cin>>n>>m>>k;
	for(i=1;i<=k;i++)
		cin>>x[i]>>y[i];
	for(i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(j=1;j<=k;j++)
			if(i==x[j])	{num+=m;break;}
		if(j==k+1)
			for(j=1;j<=k;j++){
				ty=y[j];
				if(!b[ty])	b[ty]=1,num++;
				ty=y[j]+i-x[j];
				if(ty>=1&&ty<=m&&!b[ty])	b[ty]=1,num++;
				ty=y[j]-i+x[j];
				if(ty>=1&&ty<=m&&!b[ty])	b[ty]=1,num++;
			}
	}
	cout<<n*m-num<<endl;
	return 0;
}
