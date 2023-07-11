#include<iostream>
using namespace std;
int n,num=0;
char b[20][20];
void Dfs(int m,int col,int x1,int x2){
	int i,j,k;
	if(m==n){
		num++;
		return;
	}
	int pos=((1<<n)-1)&(~(col|x1|x2));
	while(pos){
		int p=pos&(-pos);
		pos=pos&(pos-1);
		int column=__builtin_ctz(p);
		if(b[m][column]=='*')
			Dfs(m+1,col|p,(x1|p)>>1,(x2|p)<<1);
	}
}
int main(){
	int i,j;
	cin>>n;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>b[i][j];
	Dfs(0,0,0,0);
	cout<<num<<endl;
	return 0;
}
