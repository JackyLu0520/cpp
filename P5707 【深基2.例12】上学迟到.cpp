#include<bits/stdc++.h>
using namespace std;
int s,v,s1,t,h,m;
int main(){
	cin>>s>>v;
	s1=(24+8)*60;
	t=ceil(s*1.0/v);
	s1-=t;
	s1-=10;
	h=s1/60%24;
	m=s1%60;
	printf("%02d:%02d",h,m);
	return 0;
}
