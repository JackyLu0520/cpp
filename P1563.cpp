#include<iostream>
#include<string>
using namespace std;
struct toy{
	bool dir;
	string job;
}a[100001];
int n,m,y,i,num=1;
bool x;
int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i].dir>>a[i].job;
	for(i=1;i<=m;i++){
		cin>>x>>y;
		if(x==a[num].dir)	num-=y;
		else				num+=y;
		while(num>n)	num-=n; 
		while(num<=0)	num+=n; 
	}
	cout<<a[num].job;
	return 0;
}
