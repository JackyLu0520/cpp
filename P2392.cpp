#include<iostream>
#include<cmath>
using namespace std;
int s[5],a[21],l,r,mina,sum;
void Dfs(int step,int n){
	if(step==s[n]+1){
		mina=min(mina,max(l,r));
		return;
	}
	l+=a[step];
	Dfs(step+1,n);
	l-=a[step];
	r+=a[step];
	Dfs(step+1,n);
	r-=a[step];
}
int main(){
	int i,j;
	cin>>s[1]>>s[2]>>s[3]>>s[4];
	for(i=1;i<=4;i++){
		for(j=1;j<=s[i];j++)	cin>>a[j];
		mina=1200;
		l=r=0;
		Dfs(1,i);
		sum+=mina;
	}
	cout<<sum;
	return 0;
}
