#include<iostream>
#include<algorithm>
using namespace std;
struct a_signal{
	char name[20];
	char sos[200];
}signals[101];
int n,a[100],i,j,Max=0;
int main(){
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>signals[i].name>>signals[i].sos;
	for(i=1;i<=n;i++)
		for(j=0;signals[i].sos[j+2]!='\0';j++)
			if(signals[i].sos[j]=='s'&&signals[i].sos[j+1]=='o'&&signals[i].sos[j+2]=='s')
				a[i]++;
	for(i=1;i<=n;i++)
		Max=max(Max,a[i]);
	for(i=1;i<=n;i++)
		if(a[i]==Max)
			cout<<signals[i].name<<' ';
	cout<<endl<<Max;
	return 0;
} 
