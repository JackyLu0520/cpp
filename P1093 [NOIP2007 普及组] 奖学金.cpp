#include<bits/stdc++.h>
using namespace std;
struct stu{
	int num,c,m,e,t;
}stus[310];
int n;
bool cmp(stu a,stu b){
	a.t=a.c+a.m+a.e;
	b.t=b.c+b.m+b.e;
	if(a.t>b.t)	return true;
	if(a.t==b.t&&a.c>b.c)	return true;
	if(a.t==b.t&&a.c==b.c&&a.num<b.num)	return true;
	return false;
}
int main(){
	int i;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>stus[i].c>>stus[i].m>>stus[i].e;
		stus[i].num=i;
	}
	sort(stus+1,stus+n+1,cmp);
	for(i=1;i<=5;i++)
		cout<<stus[i].num<<' '<<stus[i].c+stus[i].m+stus[i].e<<endl;
	return 0;
}
