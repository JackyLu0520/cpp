#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int n,m,s[20][100],i,j,sum;
	float max;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&s[i][j]);
	for(i=0;i<n;i++){
		sort(s[i],s[i]+m);
		sum=0;
		for(j=1;j<m-1;j++)
			sum+=s[i][j];
		if(max<sum/(m-2.0))
			max=sum/(m-2.0);
	}
	printf("%.2f",max);
}
