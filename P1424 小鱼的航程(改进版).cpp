#include<iostream>
using namespace std;
int main(){
	int x,n;
	cin>>x>>n;
	if(x<=6)
		if((n%7+x-1)%7==6)
			cout<<(n-(n+x-1)/7*2+1)*250;
		else
			cout<<(n-(n+x-1)/7*2)*250;
	else
		if((n%7+x-1)%7==6)
			cout<<(n-(n+x-1)/7*2)*250;
		else
			cout<<(n-(n+x-1)/7*2+1)*250;
	return 0;
}
