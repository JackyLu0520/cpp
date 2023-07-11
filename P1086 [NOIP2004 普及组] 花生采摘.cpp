#include<bits/stdc++.h>
using namespace std;
struct P{
	int a,x,y;
	P(){}
	P(int A,int X,int Y){a=A;x=X;y=Y;}
}p[410];
bool cmp(P a,P b){
	return a.a>b.a;
}
int dis(int x1,int y1,int x2,int y2){
	return abs(x1-x2)+abs(y1-y2);
}
int m,n,k,s,cnt;
int main(){
	int i;
	cin>>m>>n>>k;
	for(i=0;i<m*n;i++){
		int t;
		cin>>t;
		p[i]=P(t,i/n-1,i%n);
	}
	sort(p,p+m*n,cmp);
	s=p[0].x+1;
	for(i=0;s+p[i].x+1<=k;i++){
		s+=dis(p[i].x,p[i].y,p[i+1].x,p[i+1].y)+1;
		cnt+=p[i].a;
	}
	cout<<cnt;
	return 0;
}