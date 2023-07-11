#include<bits/stdc++.h>
using namespace std;
struct Milk{
	int p,a;
}M[5010];
int n,m,s;
bool cmp(Milk a,Milk b){
	return a.p<b.p;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>M[i].p>>M[i].a;
	sort(M,M+m,cmp);
	for(int i=1;i<=m;i++){
		if(M[i].a<n){
			s+=M[i].a*M[i].p;
			n-=M[i].a;
		}else{
			s+=M[i].p*n;
			break;
		}
	}
	cout<<s;
	return 0;
}
