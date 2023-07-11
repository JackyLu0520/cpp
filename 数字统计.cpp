#include<iostream>
using namespace std;
int main(){
	int l,r,s=0;
	cin>>l>>r;
	for(int i=l;i<=r;i++)
		s+=(i/1%10==2)+(i/10%10==2)+(i/100%10==2)+(i/1000%10==2)+(i/10000%10==2)+(i/100000%10==2);
	cout<<s;
	return 0;
} 
