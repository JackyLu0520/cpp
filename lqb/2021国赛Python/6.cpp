#include<iostream>
#include<algorithm>
using namespace std;
int b[110][110]={0};
int n,x,y,m=0,s;
int main(){
	int i,j,k;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>x>>y;
		b[x][y]=1;
	}
	//------------------
	for(i=1;i<=100;i++){
		s=0;
		for(j=1;j<=100;j++)
			s+=b[j][i];
		m=max(m,s);
	}
	//------------------
	for(i=1;i<=100;i++){
		s=0;
		for(j=1;j<=100;j++)
			s+=b[i][j];
		m=max(m,s);
	}
	//------------------
	for(i=1;i<=100;i++){
		s=0;
		for(j=1,k=i;k<=100;j++,k++)
			s+=b[j][k];
		m=max(m,s);
	}
	for(i=1;i<=100;i++){
		s=0;
		for(j=1,k=i;k<=100;j++,k++)
			s+=b[k][j];
		m=max(m,s);
	}
	//------------------
	for(i=1;i<=100;i++){
		s=0;
		for(j=1,k=i;k>=0;j++,k--)
			s+=b[j][k];
		m=max(m,s);
	}
	for(i=1;i<=100;i++){
		s=0;
		for(j=100,k=i;k<=100;j--,k++)
			s+=b[k][j];
		m=max(m,s);
	}
	cout<<m;
	return 0;
}
/*
Sample Input:
6
2 1
3 2
5 2
4 3
3 4
6 5
Sample Output:
4
*/
