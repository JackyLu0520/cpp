#include<bits/stdc++.h>
using namespace std;
const int N=16,M=1<<N;
int n;
double w[N][N],f[M][N],x[N],y[N],ans=10000000;
int main(){
	scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lf%lf",&x[i],&y[i]);
	x[0]=y[0]=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
            w[i][j]=hypot(x[i]-x[j],y[i]-y[j]);
    for(int i=0;i<(1<<(n+1));i++)
        for(int j=0;j<=n;j++)
            f[i][j]=10000000;
	f[1][0]=0;
	for(int i=0;i<(1<<(n+1));i++)
		for(int j=0;j<=n;j++)
			if(i>>j&1)
				for(int k=0;k<=n;k++)
					if((i-(1<<j))>>k&1)	f[i][j]=min(f[i][j],f[i-(1<<j)][k]+w[k][j]);
	for(int i=0;i<=n;i++)
        ans=min(ans,f[(1<<(n+1))-1][i]);
    printf("%.2lf",ans);
	return 0;
}