#include<iostream>
using namespace std;
int n,num=0,q[20];
void Dfs(int m,int col,int x1,int x2){
	int i,j,k;
	if(m==n){
		num++;
		if(num<=3){
			for(int i=0;i<n;i++)
				cout<<q[i]+1<<' ';
			cout<<endl;
		}
		return;
	}
	int pos=((1<<n)-1)&(~(col|x1|x2));
	while(pos){
		int p=pos&(-pos);
		pos=pos&(pos-1);
		int column=__builtin_ctz(p);
		q[m]=column;
		Dfs(m+1,col|p,(x1|p)>>1,(x2|p)<<1);
		q[m]=0;
	}
}
int main(){
	int i,j;
	cin>>n;
	Dfs(0,0,0,0);
	cout<<num<<endl;
	return 0;
}
